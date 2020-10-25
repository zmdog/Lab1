#include <iostream>
#include <cmath>
#include <string>

using namespace std;
class Representation{
  public:

// функция отображающая размер имеющегося в ней типа данных
void typesSize(){
    cout<<"Размер int: "<<sizeof(int)<<endl;
    cout<<"Размер short int: "<<sizeof(short int)<<endl;
    cout<<"Размер long int: "<<sizeof(long int)<<endl;
    cout<<"Размер float: "<<sizeof(float)<<endl;
    cout<<"Размер double: "<<sizeof(double)<<endl;
    cout<<"Размер long double: "<<sizeof(long double)<<endl;
    cout<<"Размер char: "<<sizeof(char)<<endl;
    cout<<"Размер bool: "<<sizeof(bool)<<endl;
}

// строка, получаемая в результате перевода целого десятичного числа в двоичное, количество bit - количество нулей перед двоичным числом + двоичное число
string binaryConverterInt(int bit, int reserve){
    string binary, concatPiece;

  // запись итога цикла в concatPiece двоичного кода в обратном порядке 265 - 100100001(100001001)
    for(int i=0;i<bit;i++){
    if(abs(reserve)>0){
      concatPiece+=to_string(abs(reserve)%2);
    }else{
      cout<<abs(reserve)%2;
    }
    reserve=abs(reserve)>>1;
    }

    // правильная запись двоичного кода в переменную binary
    for(int i=0; i<=concatPiece.length();i++){
      binary+=concatPiece[concatPiece.length()-i];
    }

   return binary;
  }


// функция, которая визуально отображает двоичное представление в памяти компьютера в зависимости от битности системы целого числа
  void binaryInt(int bit, int reserve)
  {
  reserve>0? cout<<1<<"\t":cout<<0<<"\t";
  cout<<binaryConverterInt(bit, reserve);
  }


// функция, которая визуально отображает двоичное представление в памяти компьютера в зависимости от битности системы числа с точкой
  void binaryFloat(int bit, float reserve)
  {
    int reserving = floor(abs(reserve));
    float expPiece, mainPiece=modf(abs(reserve), &expPiece),extent=0;
    string binary, firstPiece, secondPiece;

    // проверка на знак числа
    reserve>0? cout<<0<<"\t":cout<<1<<"\t";
    
    // создание двоичного кода целого числа
      for(int i=0;i<bit;i++){
        if(abs(reserving)>0){
          firstPiece+=to_string(abs(reserving)%2);
        }
      reserving=abs(reserving)>>1;
      }
      
    // создание двоичного кода числа после запятой
      for(int i = 0; i<=bit-firstPiece.length();i++){
        mainPiece*=2;
        if(floor(mainPiece)==0){
          secondPiece+="0";
        }else{
          secondPiece+="1";
          mainPiece-=1;
        }
      }
      binary+=(firstPiece);
      binary+=secondPiece;

    // поиск степени для экспоненты
      for(int i=0;i<=firstPiece.length();i++){
          if(expPiece>=2){
              ++extent;
              expPiece/=2;
          }
      }
    cout<<binaryConverterInt(8, extent+127)<<"\t";
    cout<<binary<<endl;
  }

  
};

int main() {
  Representation representation;
  // representation.binaryFloat(15, 3.14);
  // representation.binaryInt(32, 265);
  // representation.typesSize();
}
