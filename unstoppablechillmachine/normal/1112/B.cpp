#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int nxt = k + 1, sum = 0;
  vector<pair<int, int> > cur(k + 1);
  for (int i = 1; i <= k; i++) {
    if (i <= n) cur[i] = {i, 1};
    else cur[i] = {0, 0};
  }
  vector<bool> ok(n + 1);
  for (int i = 1;; i++) {
    if (sum == n && i % 2 == 0) break;
    if (i % 2 == 1) {
        for (int j = 1; j <= k; j++) {
        if (cur[j].F == 0) continue;
        if (cur[j].S == int(ld(100.0 * (ld)sum / (ld)n + 0.5))) {
          ok[cur[j].F] = true;
        }
      }
    }
    if (i % 2 == 0) {
      for (int j = 1; j <= k; j++) {
        if (cur[j].F == 0) continue;
        if (cur[j].S == a[cur[j].F]) {
          sum++;
          if (nxt <= n) {
            cur[j] = {nxt, 1};
            nxt++;
          }
          else {
            cur[j] = {0, 0};
          }
        }
        else {
          cur[j].S++;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (ok[i]) {
      ans++;
    }
  }
  cout << ans;
}
signed main() {
#ifdef extraterrestrial_
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}