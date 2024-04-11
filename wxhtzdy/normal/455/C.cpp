#include <bits/stdc++.h>

using namespace std;

struct dsu{
  vector<int> p;
  dsu(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  void unite(int x, int y) {
    x = get(x);
    y = get(y);
    p[x] = y;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  dsu d(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    d.unite(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> was(n, false);
  vector<int> dist(n);
  function<void(int, int, int, int&)> Dfs = [&](int u, int p, int dep, int& nxt) {
    was[u] = true;
    dist[u] = dep;
    if (dist[u] > dist[nxt]) {
      nxt = u;
    }
    for (int v : g[u]) {
      if (v != p) {
        Dfs(v, u, dep + 1, nxt);
      }
    }
  };
  vector<int> diam(n);
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      int nxt = i;
      Dfs(i, -1, 0, nxt);
      Dfs(nxt, -1, 0, nxt);
      diam[d.get(i)] = dist[nxt];
    }
  }
  while (q--) {
    int foo;
    cin >> foo;
    if (foo == 1) {
      int x;
      cin >> x;
      --x;
      cout << diam[d.get(x)] << '\n';
    } else {
      int x, y;
      cin >> x >> y;
      --x, --y;
      x = d.get(x);
      y = d.get(y);
      if (x != y) {
        int r = max({diam[x], diam[y], (diam[x] + 1) / 2 + (diam[y] + 1) / 2 + 1});
        diam[x] = diam[y] = r;
        d.unite(x, y);
      }
    }
  }
  return 0;
}