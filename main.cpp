#include <Servo.h>

Servo servo1;
Servo servo2;
int potValue1;
int potValue2;
int serValue1;
int serValue2;

const int buzzer = 8;
const int redLed = 10;
const int greenLed = 9;

void setup(){
  Serial.begin(9600);
  servo1.attach(13);
  servo2.attach(2);
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  delay(1000);
}

void loop(){
  
  potValue1 = analogRead(A5);
  serValue1 = map(potValue1, 0, 1023, 0, 180);
  
  potValue2 = analogRead(A4);
  serValue2 = map(potValue2, 0, 1023, 0, 180);
  
  servo1.write(serValue1);
  servo2.write(serValue2);
  
  if(serValue1 < 5){
    tone(buzzer, 250);
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  } else if(serValue1 > 175){
    tone(buzzer, 250);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);   
  } else{
    noTone(buzzer);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
  }
  
  if(serValue2 >= 120){
    tone(buzzer, 250);
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    delay(500);  
  }  
}