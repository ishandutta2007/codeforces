#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> have(m);
    vector<pair<int, int>> mx(m);
    for (int i = 0; i < m; i++) {
      mx[i] = {0, i};
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        have[j].pb(x);
        mx[j].F = max(mx[j].F, x);
      }
    }
    sort(mx.rbegin(), mx.rend());
    int cnt = min(n, m);
    for (int i = 0; i < cnt; i++) {
      for (int j = 0; j < n; j++) {
        have[mx[i].S].pb(have[mx[i].S][j]);
      } 
    }
    vector<vector<int>> calc(cnt + 1, vector<int>(1 << n));
    for (int i = 1; i <= cnt; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        for (int shift = 0; shift < n; shift++) {
          int sum = 0;
          for (int j = 0; j < n; j++) {
            if ((mask >> j) & 1) {
              sum += have[mx[i - 1].S][j + shift];
            }
          }
          calc[i][mask] = max(calc[i][mask], sum);
        }
      }
    }
    vector<vector<int>> dp(cnt + 1, vector<int>(1 << n));
    for (int i = 1; i <= cnt; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        for (int mask2 = mask;; mask2 = (mask2 - 1) & mask) {
          dp[i][mask] = max(dp[i][mask], dp[i - 1][mask2] + calc[i][mask ^ mask2]);
          if (mask2 == 0) {
            break;
          }
        }
      }
    }
    cout << dp[cnt][(1 << n) - 1] << '\n';
  }
}