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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back({v, i});
      g[v].push_back({u, i});
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (g[i].size() > 2) {
        ok = false;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    int root = 0;
    for (int i = 0; i < n; i++) {
      if (g[i].size() == 1) {
        root = i;
      }
    }
    vector<int> order;
    function<void(int, int)> Dfs = [&](int u, int p) {
      for (auto v : g[u]) {
        if (v.first == p) {
          continue;
        }
        order.push_back(v.second);
        Dfs(v.first, u);
      }
    };
    Dfs(root, root);
    vector<int> ans(n);
    for (int i = 0; i < order.size(); i++) {
      ans[order[i]] = (i % 2 == 0 ? 11 : 2);
    }
    for (int i = 1; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}