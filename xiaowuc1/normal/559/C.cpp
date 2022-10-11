#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

typedef long long ll;
typedef pair<int, int> pii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;

ll fact[200005];
ll invfact[200005];

ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e&1) {
      r*=b;
      r%=m;
    }
    b*=b;
    b%=m;
    e/=2;
  }
  return r;
}

ll comb(ll n, ll k) {
  ll r = fact[n];
  r *= invfact[k];
  r %= MOD;
  r *= invfact[n-k];
  r %= MOD;
  return r;
}

pii l[2005];
ll dp[2][2005];
void solve() {
  int r, c;
  scanf("%d%d", &r, &c);
  int n;
  scanf("%d", &n);
  l[0] = pii(1, 1);
  for(int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    l[i] = pii(x, y);
  }
  l[n+1] = pii(r, c);
  n += 2;
  sort(l, l+n);
  dp[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if(l[j].first >= l[i].first && l[j].second >= l[i].second) {
        ll scale = comb(l[j].first + l[j].second - l[i].first - l[i].second, l[j].first - l[i].first);
        dp[1][j] += dp[0][i] * scale;
        dp[1][j] %= MOD;
        dp[0][j] += dp[1][i] * scale;
        dp[0][j] %= MOD;
      }
    }
  }
  printf("%lld\n", (dp[1][n-1] - dp[0][n-1] + MOD) % MOD);
}

void init() {
  fact[0] = 1;
  for(int i = 1; i <= 200000; i++) {
    fact[i] = fact[i-1] * i;
    fact[i] %= MOD;
  }
  invfact[200000] = modpow(fact[200000], MOD-2, MOD);
  for(int i = 199999; i >= 0; i--) {
    invfact[i] = invfact[i+1] * (i+1);
    invfact[i] %= MOD;
    assert((fact[i] * invfact[i]) % MOD == 1);
  }
}

int main() {
  init();
  solve();
  return 0;
}