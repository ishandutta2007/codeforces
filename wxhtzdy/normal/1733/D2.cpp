/**
 *    author:  wxhtzdy
 *    created: 19.09.2022 16:48:00
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (a[i] != b[i]);
    }
    if (cnt % 2 == 1) {
      cout << -1 << '\n';
      continue;      
    }
    vector<int> ids;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ids.push_back(i);
      }
    }
    int k = (int) ids.size();
    if (k == 0) {      
      cout << 0 << '\n';
      continue;
    }
    if (k == 2) {
      if (ids[0] + 1 == ids[1]) {
        cout << min(x, 2 * y) << '\n';
      } else {
        cout << min((ids[1] - ids[0]) * 1LL * x, 1LL * y) << '\n';
      }
      continue;
    }
    vector<vector<int>> dp(k, vector<int>(k + 1, n + 1));
    dp[0][0] = 0;
    for (int i = 0; i < k; i++) {
      if (i > 0) {
        dp[i] = dp[i - 1];
      }
      if (i > 0) {
        for (int c = 0; c < k; c++) { 
          int prv_dp = (i > 1 ? dp[i - 2][c] : (c == 0 ? 0 : n + 1));
          dp[i][c + 1] = min(dp[i][c + 1], prv_dp + ids[i] - ids[i - 1]);  
        }
      }
    }
    long long ans = dp[k - 1][k / 2] * 1LL * x;
    for (int i = 0; i * 2 <= k; i++) {
      if (k - 2 * i == 2) {
        long long cost = y;
        ans = min(ans, dp[k - 1][i] * 1LL * x + cost);
        continue;
      }
      if (dp[k - 1][i] != n + 1) {
        ans = min(ans, dp[k - 1][i] * 1LL * x + ((k - 2 * i) / 2) * 1LL * y);
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}