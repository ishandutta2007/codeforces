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

const int N = 210;
ld dp[N][N][N];

bool cmp(pii a, pii b) {
  return a.S > b.S;
}

void source() {
  int n, need, free;
  cin >> n >> need >> free;
  vector<pii> kek(n);
  for (auto &it : kek) {
    cin >> it.F;
  }
  for (auto &it : kek) {
    cin >> it.S;
  }
  sort(all(kek), cmp);
  vector<int> p(n), a(n);
  for (int i = 0; i < n; i++) {
    p[i] = kek[i].F;
    a[i] = kek[i].S;
  }
  dp[0][0][min(free, n)] = 1;
  for (int i = 0; i < n; i++) {
    for (int win = 0; win <= i; win++) {
      for (int j = 0; j <= n; j++) {
        int to = min(j + a[i], n);
        if (to >= 0) {
          dp[i + 1][win + 1][to] += dp[i][win][j] * (ld)p[i] / 100.0;
        }
        dp[i + 1][win][j] += dp[i][win][j] * (ld)(100 - p[i]) / 100.0;
      }
    }
  }
  ld ans = 0;
  for (int win = need; win <= n; win++) {
    for (int i = 0; i <= n; i++) {
      ans += dp[n][win][i];
      //cout << win << ' ' << i << ' ' << dp[n][win][i] << '\n';
    }
  }
  cout << fixed << setprecision(10) << ans;
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