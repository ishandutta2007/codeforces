#include <bits/stdc++.h>

using namespace std;

struct segtree {
  vector<pair<int, int>> st;
  void build(int n) {
    st.resize(5 * n);
  }
  void modify(int node, int l, int r, int x, int y) {
    if (l > r || l > x || r < x) return;
    if (l == r) {
      st[node] = {y, l};
      return;
    }
    int mid = l + r >> 1;
    modify(node + node, l, mid, x, y);
    modify(node + node + 1, mid + 1, r, x, y);
    st[node] = max(st[node + node], st[node + node + 1]);
  }
  pair<int, int> get(int node, int l, int r, int ll, int rr) {
    if (l > r || l > rr || r < ll) return {0, 0};
    if (ll <= l && r <= rr) return st[node];
    int mid = l + r >> 1;
    return max(get(node + node, l, mid, ll, rr), get(node + node + 1, mid + 1, r, ll, rr));
  }
} st;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }
  vector<vector<int>> g(n + q + 5);
  vector<int> par(n);
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
  function<int(int)> root = [&](int u) {
    return par[u] == u ? u : par[u] = root(par[u]);
  };
  function<void(int, int)> Merge = [&](int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) {
      return;
    }
    par.push_back(n);
    par[u] = n;
    par[v] = n;
    g[n].push_back(u);
    g[n].push_back(v);
    n++;
  };
  vector<int> tin(n + q + 5), tout(n + q + 5);
  int T = 0;
  function<void(int)> Dfs = [&](int u) {
    //cerr << "node " << u << endl;
    tin[u] = ++T;
    for (int v : g[u]) {
      Dfs(v);
    }
    tout[u] = T;
  };
  vector<int> t(q);
  vector<int> v(q);
  vector<int> id(q);
  vector<bool> del(m, false);
  for (int i = 0; i < q; i++) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> v[i];
      --v[i];
    } else {
      cin >> id[i];
      --id[i];
      del[id[i]] = true;
    }
  }
  for (int i = 0; i < m; i++) {
    if (del[i]) {
      continue;
    }
    Merge(a[i], b[i]);
  }
  for (int i = q - 1; i >= 0; i--) {
    if (t[i] == 1) {
      v[i] = root(v[i]);
    } else {
      Merge(a[id[i]], b[id[i]]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (root(i) == i) {
      Dfs(i);
    }
  }
  int x = p.size();
  //cerr << "start n = " << x << endl;
  st.build(n + 5);
  for (int i = 0; i < x; i++) {
    st.modify(1, 1, n, tin[i], p[i]);
  }
  for (int i = 0; i < q; i++) {
    if (t[i] == 2) {
      continue;
    }
    auto cc = st.get(1, 1, n, tin[v[i]], tout[v[i]]);
    cout << cc.first << '\n';
    if (cc.first != 0) {
      st.modify(1, 1, n, cc.second, 0);
    }
  }
  return 0;
}