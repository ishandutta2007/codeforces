#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
  cin >> N;
  int res = 0;
  for(unsigned int a=1; a<=N; a++){
    for(unsigned int b=a; b<=N; b++){
      unsigned int c = a ^ b;
      if(c >= b && c <= N && c < a+b){
        res++;
        //cout << a << " " << b << " " << c << endl;
      }
    }
  }
  cout << res << endl;

  return 0;
}