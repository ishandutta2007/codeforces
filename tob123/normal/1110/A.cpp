#include <bits/stdc++.h>
using namespace std;

int B, K;

int main(){
  cin >> B >> K;
  bool o = false;
  for(int i=K-1; i>=0; i--){
    int x;
    cin >> x;
    if(B%2){
      o ^= (x%2 == 1);
    }
    else{
      if(i == 0){
        o = x % 2;
      }
    }
  }
  cout << (o ? "odd" : "even") << endl;

  return 0;
}