#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<long long> dp(n, 1);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j : g[i]) if (i > j) {
      dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i] * (long long) g[i].size());
  }
  cout << ans << '\n';
  return 0;
}