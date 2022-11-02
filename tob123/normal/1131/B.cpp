#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A, B;

int main(){
  cin >> N;
  A.resize(N+1);
  B.resize(N+1);
  for(int i=1; i<=N; i++){
    cin >> A[i] >> B[i];
  }

  int res = 1;
  for(int i=1; i<=N; i++){
    int x = max(A[i-1], B[i-1]);
    int y = min(A[i], B[i]);
    if(y >= x){
      res += y-x+1;
    }
    if(A[i-1]==B[i-1])
      res--;
  }

  cout << res << endl;

  return 0;
}