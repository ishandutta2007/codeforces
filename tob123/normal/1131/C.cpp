#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A, R;

int main(){
  cin >> N;
  A.resize(N);
  R.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  int l=N-1, r=0;
  R[0] = A[0];
  R[N-1] = A[1];
  for(int i=2; i<N; i++){
    if(R[l] < R[r]){
      R[--l] = A[i];
    }
    else{
      R[++r] = A[i];
    }
  }

  for(int i=0; i<N; i++){
    cout << R[i] << " ";
  }

  cout << endl;

  return 0;
}