void setup()
{
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    Serial.begin(9600);
}
int income = 0;
void loop()
{
  if ( Serial.available() )
  {
      income = Serial.read();
      switch( income )
      {
        case 'f': forward();  digitalWrite(1,LOW);  digitalWrite(2,LOW);    break;
        case 'b': backward(); digitalWrite(1,LOW);  digitalWrite(2,LOW);    break;
        case 'l': left();
        while ( !Serial.available() )
        {
          digitalWrite(2,HIGH); digitalWrite(1,LOW);delay(1000）；
          digitalWrite(2,LOW); digitalWrite(1,LOW); delay(1000）；  
        }
        break;
        case 'r': right();
        while ( !Serial.available() )
        {
          digitalWrite(1,HIGH); digitalWrite(2,LOW);delay(1000);
          digitalWrite(1,LOW); digitalWrite(2,LOW);delay(1000);
        }
        break;
        case 's': stop(); 
        digitalWrite(1,LOW);  digitalWrite(2,LOW);    break;
        default: break;           
    }    
  } 
}

void forward()
{
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
}
void backward()
{
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
}

void left()
{
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    
}

void right()
{
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    
}
void stop()
{
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
}
