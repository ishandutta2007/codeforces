//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define int ll
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(4, INF));
  dp[2][0] = a[1] + a[2];
  dp[2][1] = (a[2] ? a[1] : INF);
  dp[2][2] = (a[1] ? a[2] : INF);
  if (a[1] && a[2]) {
    dp[2][3] = 0;
  }
  for (int i = 2; i < n; i++) {
    for (int mask = 0; mask < 4; mask++) {
      for (int j = 0; j < 2; j++) {
        if ((j && !a[i + 1]) || (mask == 2 && j == 1)) {
          continue;
        }
        dp[i + 1][(mask % 2) * 2 + j] = min(dp[i + 1][(mask % 2) * 2 + j], dp[i][mask] + (a[i + 1] - j));
      }
    }
  }
  int ans = INF;
  for (int i = 0; i< 4; i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}