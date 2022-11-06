#include <bits/stdc++.h>
using namespace std;

int64_t Solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  vector<vector<int64_t>> dp(n, vector<int64_t>(2));

  function<void(int, int)> Dfs = [&](int x, int p) {
    vector<int64_t> v;
    int64_t sum = 0;
    for (auto &e : g[x]) {
      int u = e.first, w = e.second;
      if (u == p) continue;
      Dfs(u, x);
      v.push_back(dp[u][0] + w - max(dp[u][1], dp[u][0]));
      sum += max(dp[u][1], dp[u][0]);
    }
    sort(v.rbegin(), v.rend());
    dp[x][1] = dp[x][0] = sum;
    for (int i = 0; i < min((int)v.size(), k); ++i) dp[x][1] += max(v[i], 0LL);
    for (int i = 0; i < min((int)v.size(), k - 1); ++i) dp[x][0] += max(v[i], 0LL);
  };

  Dfs(0, -1);
  return max(dp[0][0], dp[0][1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) cout << Solve() << "\n";
}