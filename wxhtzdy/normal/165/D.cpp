#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> u(n), v(n);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    cin >> u[i] >> v[i];
    --u[i]; --v[i];
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
  }
  const int L = 25;
  vector<vector<int>> par(n, vector<int>(L));
  vector<int> dep(n);
  function<void(int, int)> Dfs = [&](int u, int p) {
    par[u][0] = p;
    for (int j = 1; j < L; j++) {
      if (par[u][j - 1] != -1) {
        par[u][j] = par[par[u][j - 1]][j - 1];
      }
    }
    for (int v : g[u]) {
      if (v != p) {
        dep[v] = dep[u] + 1;
        Dfs(v, u);
      }
    }
  };
  auto Lca = [&](int u, int v) {
    if (dep[u] < dep[v]) {
      swap(u, v);
    }
    for (int i = L - 1; i >= 0; i--) {
      if (par[u][i] != -1 && dep[par[u][i]] >= dep[v]) {
        u = par[u][i];
      }
    }
    for (int i = L - 1; i >= 0; i--) {
      if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
      }
    }
    if (u == v) {
      return u;
    } else {
      return par[u][0];
    }
  };
  Dfs(0, -1);
  auto Dist = [&](int u, int v) {
    return dep[u] + dep[v] - 2 * dep[Lca(u, v)];
  };
  int q;
  cin >> q;
  vector<int> t(q);
  vector<int> a(q), b(q);
  vector<int> id(q);
  vector<vector<int>> qs(n);
  for (int i = 0; i < q; i++) {
    cin >> t[i];
    if (t[i] == 1 || t[i] == 2) {
      cin >> id[i];
      qs[id[i]].push_back(i);
    } else {
      cin >> a[i] >> b[i];
      --a[i]; --b[i];
    }
  }
  vector<vector<int>> act(4 * q);
  function<void(int, int, int, int, int, int)> Update = [&](int node, int l, int r, int ll, int rr, int x) {
    if (l > r || l > rr || r < ll) return;
    if (ll <= l && r <= rr) {
      act[node].push_back(x);
      return;
    }
    int mid = l + r >> 1;
    Update(node * 2 + 1, l, mid, ll, rr, x);
    Update(node * 2 + 2, mid + 1, r, ll, rr, x);
  };
  for (int i = 1; i < n; i++) {
    if (qs[i].empty()) {
      Update(0, 0, q - 1, 0, q - 1, i);
      continue;
    }
    if (qs[i][0] > 0) {
      Update(0, 0, q - 1, 0, qs[i][0] - 1, i);
    }
    for (int j = 1; j < qs[i].size(); j += 2) {
      int nxt = (j + 1 == qs[i].size() ? q - 1 : qs[i][j + 1] - 1);
      Update(0, 0, q - 1, qs[i][j], nxt, i);
    }
  }
  vector<int> same(q);
  vector<int> r(n);
  iota(r.begin(), r.end(), 0);
  vector<int> sz(n, 1);
  function<int(int)> root = [&](int x) {
    return r[x] == x ? x : root(r[x]);
  };
  stack<tuple<int, int, int, int>> stk;
  function<void(int, int)> unite = [&](int u, int v) {
    u = root(u);
    v = root(v);
    stk.push({u, v, sz[u], sz[v]});
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    r[v] = u;
  };
  function<void()> rollback = [&]() {
    auto op = stk.top();
    stk.pop();
    r[get<0>(op)] = get<0>(op);
    r[get<1>(op)] = get<1>(op);
    sz[get<0>(op)] = get<2>(op);
    sz[get<1>(op)] = get<3>(op);
  };
  function<void(int, int, int)> Solve = [&](int node, int l, int r) {
    for (int p : act[node]) {
      unite(u[p], v[p]);
    }
    if (l == r) {
      if (t[l] == 3) {
        same[l] = (root(a[l]) == root(b[l]));
      }
    } else {
      int mid = l + r >> 1;
      Solve(node * 2 + 1, l, mid);
      Solve(node * 2 + 2, mid + 1, r);
    }
    for (int p : act[node]) {
      rollback();
    }
  };
  Solve(0, 0, q - 1);
  for (int i = 0; i < q; i++) {
    if (t[i] == 3) {
      if (same[i]) {
        cout << Dist(a[i], b[i]) << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}