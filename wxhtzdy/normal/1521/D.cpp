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
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> rem(n);
    vector<int> par(n);
    function<void(int, int)> Dfs = [&](int u, int p) {
      par[u] = p;
      int deg = 0;
      for (int v : g[u]) {
        if (v == p) {
          continue;
        }
        Dfs(v, u);
      }
      for (int v : g[u]) {
        if (v != p && !rem[v]) {
          deg++;
        }
      }
      if (deg >= 2 && u != p && !rem[u]) {
        rem[u] = 1;
      }
      for (int v : g[u]) {
        if (v == p) {
          continue;
        }
        if (deg > 2 && !rem[v]) {
          rem[v] = 1;
          deg--;
        }
      }
    };
    Dfs(0, 0);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
      if (rem[i] == 1) {
        edges.emplace_back(i, par[i]);
      }
    }
    cout << edges.size() << '\n';
    vector<vector<int>> tree(n);
    function<void(int, int)> Make = [&](int u, int p) {
      for (int v : g[u]) {
        if (v == p) {
          continue;
        }
        Make(v, u);
        if (!rem[v]) {
          tree[u].push_back(v);
          tree[v].push_back(u);
        }
      }
    };
    Make(0, 0);
    vector<int> vis(n);
    vector<int> v;
    int leaf = -1;
    vector<int> L, R;
    function<void(int, int)> DfsDown = [&](int u, int p) {
      vis[u] = 1;
      for (int j = tree[u].size(); j < 2; j++) {
        v.push_back(u);
      }
      for (int v : tree[u]) {
        if (v == p) {
          continue;
        }
        DfsDown(v, u);
      }
    };
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        v.clear();
        DfsDown(i, i);
        L.push_back(v[0]);
        R.push_back(v[1]);
      }
    }
    for (int i = 0; i < edges.size(); i++) {
      cout << edges[i].first + 1 << " " << edges[i].second + 1 << " " << L[i] + 1 << " " << R[(i + 1) % R.size()] + 1 << '\n';
    }
  }
  return 0;
}