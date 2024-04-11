/**
 *    author:  tourist
 *    created: 24.05.2021 17:34:47       
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
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<vector<long long>> dp(n, vector<long long>(2, -1));
    function<void(int, int)> Dfs = [&](int v, int pr) {
      dp[v][0] = 0;
      dp[v][1] = 0;
      for (int u : g[v]) {
        if (u == pr) {
          continue;
        }
        Dfs(u, v);
        for (int x = 0; x < 2; x++) {
          dp[v][x] += max(dp[u][0] + abs(a[v][x] - a[u][0]), dp[u][1] + abs(a[v][x] - a[u][1]));
        }
      }
    };
    Dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
  }
  return 0;
}