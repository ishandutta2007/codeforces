#include <bits/stdc++.h>
using namespace std;

int N, D;
vector<int> A;

int main(){
  cin >> N >> D;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  for(int i=N; i>=1; i--){
    for(int j=0; j+i-1<N; j++){
      int m=1001, ma=0;
      for(int x=0; x<i; x++){
        m = min(m, A[x+j]);
        ma = max(ma, A[x+j]);
      }
      if(ma-m <= D){
        cout << N-i << endl;
        return 0;
      }
    }
  }

  return 0;
}