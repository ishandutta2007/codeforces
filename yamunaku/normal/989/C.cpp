#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  cout << "36 50" << endl;
  for(int i=0;i<9;i++){
    if(!(i%2)){
      for(int j=0;j<50;j++){
        cout << "A";
      }
      cout << endl;
    }else{
      for(int j=0;j<50;j++){
        if(j%2){
          if(i/2<(b-1)/25||(i/2==(b-1)/25&&(j+1)/2<=(b-1)%25)) cout << 'B';
          else cout << 'A';
        }else{
          cout << 'A';
        }
      }
      cout << endl;
    }
  }
  for(int i=0;i<9;i++){
    if(!(i%2)){
      for(int j=0;j<50;j++){
        cout << "B";
      }
      cout << endl;
    }else{
      for(int j=0;j<50;j++){
        if(j%2){
          if(i/2<(c-1)/25||(i/2==(c-1)/25&&(j+1)/2<=(c-1)%25)) cout << 'C';
          else cout << 'B';
        }else{
          cout << 'B';
        }
      }
      cout << endl;
    }
  }
  for(int i=0;i<9;i++){
    if(!(i%2)){
      for(int j=0;j<50;j++){
        cout << "C";
      }
      cout << endl;
    }else{
      for(int j=0;j<50;j++){
        if(j%2){
          if(i/2<(d-1)/25||(i/2==(d-1)/25&&(j+1)/2<=(d-1)%25)) cout << 'D';
          else cout << 'C';
        }else{
          cout << 'C';
        }
      }
      cout << endl;
    }
  }
  for(int i=0;i<9;i++){
    if(!(i%2)){
      for(int j=0;j<50;j++){
        cout << "D";
      }
      cout << endl;
    }else{
      for(int j=0;j<50;j++){
        if(j%2){
          if(i/2<(a-1)/25||(i/2==(a-1)/25&&(j+1)/2<=(a-1)%25)) cout << 'A';
          else cout << 'D';
        }else{
          cout << 'D';
        }
      }
      cout << endl;
    }
  }
  return 0;
}