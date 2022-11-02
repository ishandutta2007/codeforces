#include <bits/stdc++.h>
using namespace std;

unsigned long long N, K;

int main(){
  cin >> N >> K;
  unsigned long long p = 1;
  while(p*2 <= N)
    p *= 2;

  if(K == 1){
    cout << N << endl;
  }
  else{
    cout << p*2-1 << endl;
  }

  return 0;
}