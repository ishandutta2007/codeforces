#include <bits/stdc++.h>
using namespace std;


int main(){
  long long N, M;
  cin >> N >> M;
  if(N <= 2*M){
    cout << 0;
  }
  else{
    cout << N-M*2;
  }
  cout << " ";
  if(M == 0){
    cout << N << endl;
    return 0;
  }
  long long maxE = 0;
  for(long long i=2; i<=N; i++){
    maxE += i-1;
    if(maxE >= M){
      cout << N-i << endl;
      return 0;
    }
  }
  
  return 0;
}