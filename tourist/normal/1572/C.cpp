/**
 *    author:  tourist
 *    created: 18.09.2021 18:35:24       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<vector<int>> at(n);
    for (int i = 0; i < n; i++) {
      at[a[i]].push_back(i);
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        dp[i][j] = (i == j ? 1 : dp[i + 1][j] + 1);
        for (int k : at[a[i]]) {
          if (k > i && k <= j) {
            int cur = (i + 1 <= k - 1 ? dp[i + 1][k - 1] : 0);
            cur += dp[k][j];
            dp[i][j] = min(dp[i][j], cur);
          }
        }
      }
    }
    cout << dp[0][n - 1] - 1 << '\n';
  }
  return 0;
}