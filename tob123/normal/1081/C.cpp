#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;
const int n = 2010;

ll N, M, K;
ll bin[n][n];

int main(){
  for(int i=0; i<n-2; i++){
    bin[i][0] = 1;
    bin[i][i] = 1;
  }
  for(int i=1; i<=n-2; i++){
    for(int j=1; j<i; j++){
      bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
      bin[i][j] %= MOD;
    }
  }
  cin >> N >> M >> K;
  ll res = M;
  for(ll i=1; i<=K; i++){
    res *= M-1;
    res %= MOD;
  }
  res *= bin[N-1][K];
  res %= MOD;

  cout << res << endl;

  return 0;
}