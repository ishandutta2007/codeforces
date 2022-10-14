#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> s(n);
  map<string, int> val;
  int id = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (!val.count(s[i])) {
      val[s[i]] = id++;
    }
  }
  vector<int> par(n);
  iota(par.begin(), par.end(), 0);
  function<int(int)> root = [&](int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
  };
  auto unite = [&](int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) {
      return false;
    }
    par[v] = u;
    return true;
  };
  vector<vector<pair<int, int>>> g(n);
  vector<int> t(m);
  vector<int> u(m), v(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i];
    t[i] -= 1;
    string x, y;
    cin >> x >> y;
    u[i] = val[x];
    v[i] = val[y];
    if (unite(u[i], v[i])) {
      g[u[i]].emplace_back(v[i], t[i]);
      g[v[i]].emplace_back(u[i], t[i]);
    }
  }
  vector<int> dep(n);
  function<void(int, int)> Dfs = [&](int u, int p) {
    for (auto e : g[u]) {
      int v = e.first;
      if (v == p) {
        continue;
      }
      dep[v] = dep[u] ^ e.second;
      Dfs(v, u);
    }
  };
  for (int i = 0; i < n; i++) {
    if (root(i) == i) {
      Dfs(i, i);
    }
  }
  for (int i = 0; i < m; i++) {
    if (root(u[i]) != root(v[i])) {
      cout << "NO" << '\n';
    } else {
      int val = dep[u[i]] ^ dep[v[i]];
      if (val == t[i]) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
  while (q--) {
    string x, y;
    cin >> x >> y;
    int a = val[x];
    int b = val[y];
    if (root(a) != root(b)) {
      cout << 3 << '\n';
    } else {
      int ans = dep[a] ^ dep[b];
      cout << ans + 1 << '\n';
    }
  }
  return 0;
}