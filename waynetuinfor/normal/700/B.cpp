#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> sz(n);
  for (int i = 0; i < k + k; ++i) {
    int u;
    cin >> u;
    sz[u - 1] = 1;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<pair<int, int>> ed;

  function<void(int, int)> Dfs = [&](int x, int p) {
    for (int u : g[x]) {
      if (u == p) continue;
      ed.emplace_back(x, u);
      Dfs(u, x);
      sz[x] += sz[u];
    }
  };

  Dfs(0, -1);
  int64_t res = 0;
  for (int i = 0; i < n - 1; ++i) {
    int a = sz[ed[i].second];
    int b = k + k - sz[ed[i].second];
    res += min(a, b);
  }
  cout << res << "\n";
}