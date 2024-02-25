#include <Servo.h>

int servopin = 9;
int servopos;
Servo myservo;

int trigpin = 12;
int echopin = 11;
int pingtraveltime;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
  myservo.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  pingtraveltime = pulseIn(echopin,HIGH);
  delay(25);
  Serial.println(pingtraveltime);
  delay(100);
  if(pingtraveltime<2000)
  {
    //servopos = 180;
    myservo.write(90);
    delay(200);
  }
  else
  {
    myservo.write(0);
    delay(200);
  }


}
