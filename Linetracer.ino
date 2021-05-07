float checking();

int A_1A = 3;
int A_1B = 4;
int B_1A = 8;
int B_1B = 9;
int high = 2;
int high1 = 13;

int trigger = 5;
int echo = 6;
float distance, result;
float duration;

int leftLineSensor =  10;
int rightLineSensor = 11;


void setup() {

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(high,OUTPUT);
  pinMode(high1,OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  
  digitalWrite(high,HIGH);  //motor driver enable pin
  digitalWrite(high1,HIGH);
  
  digitalWrite(A_1A, LOW);
  digitalWrite(A_1B, LOW);
  digitalWrite(B_1A, LOW);
  digitalWrite(B_1B, LOW);

  
  pinMode(leftLineSensor, INPUT);
  pinMode(rightLineSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
 
  checking();

  if(result <10 && result>3) {
  digitalWrite(A_1A, LOW);
  digitalWrite(A_1B, LOW);
  digitalWrite(B_1A, LOW);
  digitalWrite(B_1B, LOW);
  Serial.println("Barrier");
    }
  
 //straight
  else if (!digitalRead(leftLineSensor) && !digitalRead(rightLineSensor)) {
    Serial.println("stop");   
    analogWrite(A_1A, 120);
    analogWrite(A_1B, 0);
    analogWrite(B_1A, 120);
    analogWrite(B_1B, 0);
    
  }
  else if (!digitalRead(leftLineSensor) && digitalRead(rightLineSensor)) {
   Serial.println("Right Sensor Detect");
    analogWrite(A_1A, 10);
    analogWrite(A_1B, 120);
    analogWrite(B_1A, 80);
    analogWrite(B_1B, 10);
  }
  
  else if (digitalRead(leftLineSensor) && !digitalRead(rightLineSensor)) {
   Serial.println("Left Sensor Detect");
   
    analogWrite(A_1A, 80);
    analogWrite(A_1B, 10);
    analogWrite(B_1A, 10);
    analogWrite(B_1B, 120);
    
   
  } else if (digitalRead(leftLineSensor) && digitalRead(rightLineSensor)) {
   Serial.println("Both Sensor Detect");
    analogWrite(A_1A, LOW);
    analogWrite(A_1B, LOW);
    analogWrite(B_1A, LOW);
    analogWrite(B_1B, LOW);
  }
  /*  analogWrite(A_1A, 80);
    analogWrite(A_1B, 0);
    analogWrite(B_1A, 80);
    analogWrite(B_1B, 0);
  */
  }
  

float checking()
{ // HC-SR04 -> checking if there is an obstacle.
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);

  duration = pulseIn(echo, HIGH); // Measure distance from echo pin

  // Use 343 meters per second as 80 as sound
  distance = (duration/2)*0.0343;

  Serial.print(" Distance = ");
  Serial.println(distance);
  delay(500);
  
  if(result <10 && result>3) {
  digitalWrite(A_1A, LOW);
  digitalWrite(A_1B, LOW);
  digitalWrite(B_1A, LOW);
  digitalWrite(B_1B, LOW);
  Serial.println("Barrier");
    }
 // return distance;
  
  }
