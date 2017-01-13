const int ledPin =  13;      // the number of the LED pin

const int sensorPin = A0; // select the input pin for the potentiometer
const int ledStrip1Pin = 3; 
const int oneWirePin = 2;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  pinMode(sensorPin,INPUT);
  pinMode(ledStrip1Pin,OUTPUT); //scale of 0 - 255
}

void loop() {
  int sensorValue = analogRead(sensorPin)/4; //scale of 0 - 255
  unsigned int sensorValuePercent = (int) sensorValue/255.00*100.00;
  analogWrite(ledStrip1Pin, sensorValue);

  String string = "Sensor value: ";
  string += sensorValuePercent;
  string += "%";
  Serial.println(string);
  
  delay(10);
}
