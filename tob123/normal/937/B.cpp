#include <bits/stdc++.h>
using namespace std;

long long P, Y;

int main(){
  cin >> P >> Y;
  for(long long x=Y; x>P; x--){
    bool flag = true;
    for(long long i=2; i<=P && i*i<=x; i++){
      if(x%i == 0){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}