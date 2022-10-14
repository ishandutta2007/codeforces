/**
 *    author:  milos
 *    created: 23.03.2021 14:56:16       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;         
    g[u][v] = g[v][u] = 1;
  }
  long long ans = 0;
  auto Solve = [&](int k) {
    vector<vector<long long>> dp(1 << k, vector<long long>(n, 0LL));
    for (int i = 0; i < k; i++) {
      if (g[i][k] == 1) {
        dp[1 << i][i] = 1;
      }
    }
    for (int i = 0; i < (1 << k); i++) {
      for (int j = 0; j < k; j++) {
        if (i & (1 << j)) {
          if (__builtin_popcount(i) >= 2 && g[j][k]) {
            ans += dp[i][j];
          }
          for (int l = 0; l < k; l++) {
            if ((i & (1 << l)) == 0 && g[l][j]) {
              dp[i ^ (1 << l)][l] += dp[i][j];
            }
          }
        }
      }
    }
  };                
  for (int i = 1; i < n; i++) {
    Solve(i);
  }
  cout << ans / 2 << '\n';
  return 0;
}