/**
 *    author:  tourist
 *    created: 18.07.2022 18:37:21       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      --c[i];
    }
    vector<vector<int>> dp(n, vector<int>(2));
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int x = c[i];
      int p = i % 2;
      dp[x][p] = max(dp[x][p], dp[x][p ^ 1] + 1);
      ans[x] = max(ans[x], dp[x][p]);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}