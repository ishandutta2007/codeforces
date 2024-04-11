#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> mx(n);
  vector<int> smx(n);
  vector<long long> dp(n);
  function<void(int, int)> Dfs = [&](int u, int p) {
    for (int v : g[u]) {
      if (v != p) {
        Dfs(v, u);
        int he = max(mx[v], h[v]);
        if (mx[u] < he) {
          smx[u] = mx[u];
          mx[u] = he;
        } else {
          smx[u] = max(smx[u], he);
        }
        dp[u] += dp[v];
      }
    }
    dp[u] += max(0, h[u] - mx[u]);
  };
  Dfs(0, 0);
  long long ans = (long long) 1e18;
  function<void(int, int)> Solve = [&](int u, int p) {
    ans = min(ans, dp[u]);
    for (int v : g[u]) {
      if (v == p) {
        continue;
      }
      int he = mx[u];
      if (he == max(h[v], mx[v])) {
        he = smx[u];
      }
      int old_mx = mx[v];
      int old_smx = smx[v];
      dp[u] -= max(0, h[u] - mx[u]);
      dp[u] += max(0, h[u] - he);
      dp[u] -= dp[v];
      dp[v] += dp[u];
      int his = max(he, h[u]);
      if (mx[v] < his) {
        mx[v] = his;
      } else {
        smx[v] = max(smx[v], his);
      }
      dp[v] -= max(0, h[v] - old_mx);
      dp[v] += max(0, h[v] - mx[v]);
      Solve(v, u);
      dp[v] -= max(0, h[v] - mx[v]);
      dp[v] += max(0, h[v] - old_mx);
      dp[v] -= dp[u];
      dp[u] -= max(0, h[u] - he);
      dp[u] += dp[v];
      dp[u] += max(0, h[u] - mx[u]);
      mx[v] = old_mx;
      smx[v] = old_smx;
    }
  };
  Solve(0, 0);
  cout << ans + *max_element(h.begin(), h.end()) << '\n';                           
  return 0;
}