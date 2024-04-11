#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int l[20];

ll dp[55];
ll ndp[55];
ll inv[55];

const int MOD = 1000000007;

ll contrib(ll a, int p, int iter) {
  memset(dp, 0, sizeof(dp));
  dp[p] = 1;
  while(iter--) {
    memset(ndp, 0, sizeof(ndp));
    for(int i = 0; i <= p; i++) {
      if(!dp[i]) continue;
      for(int j = 0; j <= i; j++) {
        ndp[j] += dp[i] * inv[i+1];
        ndp[j] %= MOD;
      }
    }
    memcpy(dp, ndp, sizeof(dp));
  }
  ll ret = 0;
  ll curr = 1;
  for(int i = 0; i <= p; i++) {
    ret += curr * dp[i];
    curr *= a;
    curr %= MOD;
    ret %= MOD;
  }
  return ret;
}

ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r*=b;
      r%=m;
    }
    e/=2;
    if(e) {
      b*=b;
      b%=m;
    }
  }
  return r;
}

void solve() {
  for(int i = 1; i <= 50; i++) {
    inv[i] = modpow(i, MOD-2, MOD);
  }
  ll n;
  int k;
  cin >> n >> k;
  ll ret = 1;
  for(ll i = 2; i * i <= n; i++) {
    if(n%i) continue;
    int p = 0;
    while(n%i==0) {
      n/=i;
      p++;
    }
    ret *= contrib(i, p, k);
    ret %= MOD;
  }
  if(n > 1) {
    ret *= contrib(n, 1, k);
    ret %= MOD;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}