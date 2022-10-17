//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 23;
const int MX = (1 << 23) + 10;

bool dp[N][MX];
vector<pair<int, int>> can[N];

void source() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = j; k < i; k++) {
        if (a[j] + a[k] == a[i]) {
          can[i].pb({j, k});
        }
      }
    }
  }
  dp[0][1] = true;
  for (int i = 0; i + 1 < n; i++) {
    for (int mask = 0; mask < (1 << (i + 1)); mask++) {
      if (!dp[i][mask] || __builtin_popcount(mask) > 15) {
        continue;
      }
      bool ok = false;
      for (auto it : can[i + 1]) {
        if (((mask >> it.F) & 1) && ((mask >> it.S) & 1)) {
          ok = true;
          break;
        } 
      }
      if (ok) {
        //cout << i << ' ' << mask << ' ' << __builtin_popcount(mask) << '\n';
        dp[i + 1][mask | (1 << (i + 1))] = true;
        for (int j = 0; j <= i; j++) {
          if ((mask >> j) & 1) {
            dp[i + 1][(mask ^ (1 << j)) | (1 << (i + 1))] = true;
          }
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < (1 << n); i++) {
    if (dp[n - 1][i]) {
      ans = min(ans, (int)__builtin_popcount(i));
    }
  }
  cout << (ans == INF ? -1 : ans);
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output2.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
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