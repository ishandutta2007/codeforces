#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> mat(n, -1);
  stack<int> stk;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push(i);
    } else {
      if (!stk.empty()) {
        mat[i] = stk.top();
        mat[stk.top()] = i;
        stk.pop();
      }
    }
  }
  vector<vector<int>> g(n + 1);
  vector<int> id(n);
  vector<fenwick<long long>> f(n + 1, fenwick<long long>(0));
  function<void(int, int)> Build = [&](int l, int r) {
    for (int i = l + 1; i < r; i++) {
      id[i] = (int) g[l].size();
      id[mat[i]] = id[i];
      g[l].push_back(i);
      Build(i, mat[i]);
      i = mat[i];
    }
    f[l].n = g[l].size() + 1;
    f[l].fenw.resize((int) g[l].size() + 1);
    for (int j = 0; j < g[l].size(); j++) {
      f[l].modify(j, 1);
    }
  };
  for (int i = 0; i < n; i++) {
    if (mat[i] == -1) {
      continue;
    }
    id[i] = g[n].size();
    id[mat[i]] = id[i];
    g[n].push_back(i);
    Build(i, mat[i]);
    i = mat[i];
  }
  f[n].n = g[n].size() + 1;
  f[n].fenw.resize(g[n].size() + 1);
  for (int i = 0; i < g[n].size(); i++) {
    f[n].modify(i, 1);
  }
  vector<long long> deg(n + 1);
  vector<long long> val(n + 1);
  fenwick<long long> fenw(n);
  vector<int> par(n);
  function<void(int)> Dfs = [&](int u) {
    deg[u] = (int) g[u].size();
    val[u] = (long long) deg[u] * (deg[u] + 1) / 2;
    if (u != n) {
      fenw.modify(u, val[u]);
    }
    for (int v : g[u]) {
      par[v] = u;
      Dfs(v);
    }
  };
  Dfs(n);
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l; --r;
    if (t == 1) {
      f[par[l]].modify(id[l], -1);
      if (par[l] != n) {
        deg[par[l]] -= 1;
        fenw.modify(par[l], -val[par[l]]);
        val[par[l]] = (long long) deg[par[l]] * (deg[par[l]] + 1) / 2;
        fenw.modify(par[l], val[par[l]]);
      }
    } else {
      long long res = fenw.get(r) - fenw.get(l - 1);
      long long x = f[par[l]].get(id[r]) - f[par[l]].get(id[l] - 1);
      res += x * (x + 1) / 2;
      cout << res << '\n';
    }
  }
  return 0;
}