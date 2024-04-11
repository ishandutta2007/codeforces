//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
#define int ll
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1 << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 1e5 + 10;
int dp[N][5];

void source() {
  string s = "hard";
  int n;
  cin >> n;
  vector<char> c(n);
  vector<int> cost(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 4; j++) {
      dp[i][j] = BINF;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int pref = 0; pref < 4; pref++) {
      if (c[i] != s[pref]) {
        dp[i + 1][pref] = min(dp[i + 1][pref], dp[i][pref]);
      }
      else {
        dp[i + 1][pref] = min(dp[i + 1][pref], dp[i][pref] + cost[i]);
        dp[i + 1][pref + 1] = min(dp[i + 1][pref + 1], dp[i][pref]);
      }
    }
  }
  int ans = BINF;
  for (int i = 0; i < 4; i++) {
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