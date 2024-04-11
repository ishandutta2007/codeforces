#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll modpow(ll x, ll p, ll mod) {
  ll ret = 1;
  while (p > 0) {
    if (p & 1) {
      ret = (ret * x)%mod;
    }
    x = (x * x)%mod;
    p >>= 1;
  }
  return ret;
}

ll dp[5001][5001];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll mod = 998244353;
  ll N; cin >> N;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());
  vector<ll> cnt(N+1);
  rep(i, N) {
    cnt[A[i]] += 1;
  }
  A.erase(unique(A.begin(), A.end()), A.end());
  
  ll ans = 0;
  vector<ll> cs(N+1);
  ll a, inv;
  dp[0][0] = 1;
  rep(i, N) {
    inv = modpow(N-i, mod-2, mod);
    cs[0] = dp[i][0];
    rep(j, N) {
      cs[j+1] = (cs[j] + dp[i][j+1])%mod;
    }
    rep(k, A.size()) {
      a = A[k];
      if (cnt[a] > 1) {
        ans = (ans + ((dp[i][a] * (cnt[a] - 1))%mod * inv)%mod)%mod;
      }
      dp[i+1][a] = (dp[i+1][a] + ((cs[a-1] * cnt[a])%mod * inv)%mod)%mod;
    }
  }
  
  cout << ans << endl;

}