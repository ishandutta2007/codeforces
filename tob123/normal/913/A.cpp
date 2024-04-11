#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N, M, X;
  cin >> N >> M;
  X = 1;
  for(int i=0; i<N; i++){
    X *= 2;
    if(X > M){
      cout << M << endl;
      return 0;
    }
  }
  cout << M%X << endl;

  return 0;
}