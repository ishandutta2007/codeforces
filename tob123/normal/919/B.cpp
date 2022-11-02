#include <bits/stdc++.h>
using namespace std;

int K;

bool perfect(int x){
  int sum = 0;
  while(x > 0){
    sum += x%10;
    x /= 10;
  }
  return sum == 10;
}

int main(){
  cin >> K;

  for(int i=1; i<=100000000; i++){
    if(perfect(i)){
      K--;
    }
    if(K == 0){
      cout << i << endl;
      break;
    }
  }

  return 0;
}