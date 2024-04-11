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
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 50;
int dp[N][N];

void source() {
  int n, h;
  cin >> n >> h;
  dp[0][0] = 1;
  dp[1][1] = 1;
  dp[2][2] = 2;
  for (int i = 3; i <= n; i++) {
    for (int root = 1; root <= i; root++) {
      for (int h1 = 0; h1 <= root - 1; h1++) {
        for (int h2 = 0; h2 <= i - root; h2++) {
          dp[i][max(h1, h2) + 1] += dp[root - 1][h1] * dp[i - root][h2];
        }
      }
    }
  }
  int ans = 0;
  for (int i = h; i <= n; i++) {
    ans += dp[n][i];
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