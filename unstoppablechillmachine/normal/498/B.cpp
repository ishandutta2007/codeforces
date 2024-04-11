//author: extraterrestrial_
#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
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

const int N = 5010;
ld pp[N];
double dp[N][N];
double dp1[N], dp2[N];

void source() {
  int n, T;
  cin >> n >> T;
  vector<pair<ld, int>> arr(n);
  for (auto &it : arr) {
    cin >> it.F >> it.S;
    it.F /= 100.0;
  }
  for (int i = 0; i < n; i++) {
    pp[i] = 1;
    for (int j = 1; j <= arr[i].S - 1; j++) {
      pp[i] *= (1.0 - arr[i].F);
    }
  }
  dp[0][0] = 1;
  ld ans = 0;
  for (int time = 0; time < T; time++) {
    for (int i = 0; i < n; i++) {
      if (arr[i].S == 1) {
        dp[time + 1][i + 1] += dp[time][i];
      }
      else {
        dp[time + 1][i + 1] += dp[time][i] * arr[i].F;
        dp2[i] += dp[time][i] * (1.0 - arr[i].F);
        ld ver1 = dp1[i], ver2 = 0;
        if (time - arr[i].S + 1 >= 0) {
          ver1 -= dp[time - arr[i].S + 1][i] * pp[i];
          ver2 += dp[time - arr[i].S + 1][i] * pp[i];
        }
        dp[time + 1][i + 1] += ver2 + ver1 * arr[i].F;
        dp2[i] += ver1 * (1.0 - arr[i].F);
      }
    }
    ans += dp[time][n] * n;
    for (int i = 0; i <= n; i++) {
      dp1[i] = dp2[i];
      dp2[i] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += (dp[T][i] + dp1[i]) * i;
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