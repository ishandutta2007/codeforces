#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

int N, K;
vector<ll> A;

int main(){
  cin >> N >> K;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=N-2; i>=0; i--){
    A[i] += A[i+1];
  }
  ll res = 0;
  res += A[0];
  A[0] = -1000000000000ll;
  sort(A.rbegin(), A.rend());
  for(int i=0; i<K-1; i++){
    res += A[i];
  }

  cout << res << endl;

  return 0;
}