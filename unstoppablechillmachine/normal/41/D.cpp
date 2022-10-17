//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
//#define int ll
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
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 110;
const int M = 12;
int dp[N][N][M], arr[N][N];
char from[N][N][M];

void source() {
  int n, m, mod;
  cin >> n >> m >> mod;
  mod++;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      arr[i][j] = c - '0';
    }
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      for (int p = 0; p < mod; p++) {
        dp[i][j][p] = -INF;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    dp[n][i][arr[n][i] % mod] = arr[n][i];
  }
  for (int i = n; i > 1; i--) {
    for (int j = 1; j <= m; j++) {
      for (int p = 0; p < mod; p++) {
        if (dp[i][j][p] < 0) {
          continue;
        }
        if (j < m && dp[i][j][p] + arr[i - 1][j + 1] > dp[i - 1][j + 1][(dp[i][j][p] + arr[i - 1][j + 1]) % mod]) {
          dp[i - 1][j + 1][(dp[i][j][p] + arr[i - 1][j + 1]) % mod] = dp[i][j][p] + arr[i - 1][j + 1];
          from[i - 1][j + 1][(dp[i][j][p] + arr[i - 1][j + 1]) % mod] = 'R';
        }
        if (j > 1 && dp[i][j][p] + arr[i - 1][j - 1] > dp[i - 1][j - 1][(dp[i][j][p] + arr[i - 1][j - 1]) % mod]) {
          dp[i - 1][j - 1][(dp[i][j][p] + arr[i - 1][j - 1]) % mod] = dp[i][j][p] + arr[i - 1][j - 1];
          from[i - 1][j - 1][(dp[i][j][p] + arr[i - 1][j - 1]) % mod] = 'L';
        }
      }
    }
  }
  pair<int, int> best = {-INF, 0};
  for (int i = 1; i <= m; i++) {
    best = max(best, MP(dp[1][i][0], i));
  }
  if (best.F < 0) {
    cout << -1;
    exit(0);
  }
  cout << best.F << '\n';
  vector<char> ans;
  int sum = best.F;
  for (int i = 1; i < n; i++) {
    ans.pb(from[i][best.S][sum % mod]);
    sum -= arr[i][best.S];
    if (ans.back() == 'L') {
      best.S++;
    }
    else {
      best.S--;
    }
  }
  cout << best.S << '\n';
  reverse(all(ans));
  for (auto it : ans) {
    cout << it;
  }
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