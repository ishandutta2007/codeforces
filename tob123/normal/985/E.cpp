#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1000001;

int N, K, D;
vector<int> A;
bool pos[SIZE];
int M[SIZE];
int main(){
  cin >> N >> K >> D;
  A.resize(N+1);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  A[N] = 0;
  sort(A.begin(), A.end());
  M[0] = A[0];
  for(int i=0; i<=N; i++){
    if(pos[i]){
      M[i+K-1] = max(M[i+K-1], A[i]+D);
    }
    if(M[i] >= A[i]){
      pos[i+1] = true;
      M[i+1] = max(M[i+1], M[i]);
    }
  }
  if(pos[N+1]){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}