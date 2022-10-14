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
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<vector<long long>> dp(n, vector<long long>(2));
    function<void(int, int)> Dfs = [&](int u, int p) {
      for (int v : g[u]) {
        if (v == p) {
          continue;
        }
        Dfs(v, u);
        dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
        dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
      }
    };
    Dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
  }
  return 0;
}