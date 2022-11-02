#include <bits/stdc++.h>
using namespace std;

int T, x;

int main(){
  cin >> T;
  while(T--){
    cin >> x;
    if(x%2){
      cout << 1+(x-3)/2 << endl;
    }
    else{
      cout << x/2 << endl;
    }
  }

  return 0;
}