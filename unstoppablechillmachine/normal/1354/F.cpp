#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].F.S >> a[i].F.F;
      a[i].S = i + 1;
    }
    sort(all(a));
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1e9));
    vector<vector<int>> from(n + 1, vector<int>(k + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        if (dp[i][j] + a[i].F.F * (k - 1) > dp[i + 1][j]) {
          dp[i + 1][j] = dp[i][j] + a[i].F.F * (k - 1);
          from[i + 1][j] = j;
        }
        if (j < k) {
          if (dp[i][j] + a[i].F.S + a[i].F.F * j > dp[i + 1][j + 1]) {
            dp[i + 1][j + 1] = dp[i][j] + a[i].F.S + a[i].F.F * j;
            from[i + 1][j + 1] = j;
          }
        }
      }
    }
    int now = k;
    vector<int> rez;
    vector<bool> used(n + 1);
    for (int i = n; i >= 1; i--) {
      int tnow = from[i][now];
      if (tnow < now) {
        rez.pb(a[i - 1].S);
        used[a[i - 1].S] = true;
      }
      now = tnow;
    }
    reverse(all(rez));
    cout << 2 * n - k << '\n';
    for (int i = 0; i + 1 < k; i++) {
      cout << rez[i] << ' ';
    }
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        cout << i << ' ' << -i << ' ';
      }
    }
    cout << rez.back() << '\n';
  }
}