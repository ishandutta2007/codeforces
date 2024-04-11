#include <bits/stdc++.h>
using namespace std;

int N, K, S;
int A[100001];

int main(){
  cin >> N >> K;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    int t;
    cin >> t;
    S += t * A[i];
    A[i] *= 1-t;
  }
  for(int i=1; i<N; i++){
    A[i] += A[i-1];
  }
  int m = A[K-1];
  for(int i=0; i<N-K; i++){
    m = max(m, A[i+K]-A[i]);
  }
  cout << S + m << endl;

  return 0;
}