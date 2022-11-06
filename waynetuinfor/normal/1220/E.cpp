#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> w(n), deg(n);
  for (int i = 0; i < n; ++i) cin >> w[i];
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  int s;
  cin >> s;
  s--;
  vector<int> que;
  vector<int64_t> dp(w.begin(), w.end());
  vector<bool> pushed(n);
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 1) {
      que.push_back(i);
      pushed[i] = true;
    }
  }
  vector<vector<int>> f(n);
  vector<int> fa(n, -1);
  for (int it = 0; it < que.size(); ++it) {
    int x = que[it];
    int64_t k = 0;
    for (int u : f[x]) k = max(k, dp[u]);
    dp[x] += k;
    for (int u : g[x]) {
      if (pushed[u]) continue;
      fa[x] = u;
      f[u].push_back(x);
      if (--deg[u] == 1) {
        que.push_back(u);
        pushed[u] = true;
      }
    }
  }
  if (!pushed[s]) {
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
      if (pushed[i]) continue;
      sum += w[i];
    }
    int64_t res = sum;
    for (int i = 0; i < n; ++i) {
      if (pushed[i]) continue;
      for (int u : g[i]) {
        if (!pushed[u]) continue;
        res = max(res, sum + dp[u]);
      }
    }
    cout << res << "\n";
  } else {
    int64_t res = 0; 
    function<void(int, int, int64_t)> Dfs = [&](int x, int p, int64_t d) {
      d += w[x];
      res = max(res, d);
      for (int u : g[x]) {
        if (u == p) continue;
        if (!pushed[u]) continue;
        Dfs(u, x, d);
      }
    };

    Dfs(s, -1, 0);
    int64_t up = 0;
    int t = -1;
    while (s != -1 && pushed[s]) {
      up += w[s];
      t = s;
      s = fa[s];
    }
    if (s == -1) {
      cout << res << "\n"; 
    } else {
      int64_t sum = 0;
      for (int i = 0; i < n; ++i) {
        if (pushed[i]) continue;
        sum += w[i];
      }
      res = max(res, sum + up);
      for (int i = 0; i < n; ++i) {
        if (pushed[i]) continue;
        for (int u : g[i]) {
          if (!pushed[u] || u == t) continue;
          res = max(res, sum + up + dp[u]);
        }
      }
      res = max(res, sum + dp[t]);
      cout << res << "\n";
    }
  }
  return 0;
}