#include <bits/stdc++.h>

using namespace std;

class dsu {
  public:
  vector<int> p;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> a(m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }
  vector<int> op(q);
  vector<int> id(q);
  for (int i = 0; i < q; i++) {
    cin >> op[i] >> id[i];
    --id[i];
  }
  vector<bool> removed(m, false);
  for (int i = 0; i < q; i++) {
    if (op[i] == 2) {
      removed[id[i]] = true;
    }
  }
  for (int i = 0; i < m; i++) {
    if (!removed[i]) {
      op.push_back(2);
      id.push_back(i);
    }
  }
  q = (int) op.size();
  dsu d(n + q);
  vector<vector<int>> g(n + q + 1);
  for (int i = q - 1; i >= 0; i--) {
    if (op[i] == 1) {
      id[i] = d.get(id[i]);
    } else {
      if (d.get(a[id[i]]) == d.get(b[id[i]])) {
        continue;
      }
      g[n].push_back(d.get(a[id[i]]));
      g[n].push_back(d.get(b[id[i]]));
      d.unite(a[id[i]], n);
      d.unite(b[id[i]], n);
      n += 1;
    }
  }
  int timer = 0;
  vector<int> tin(n);
  vector<int> tout(n);
  function<void(int)> Dfs = [&](int u) {
    tin[u] = ++timer;
    for (int v : g[u]) {
      Dfs(v);
    }
    tout[u] = timer;
  };
  for (int i = n - 1; i >= 0; i--) {
    if (!tout[i]) {
      Dfs(i);
    }
  }
  vector<pair<int, int>> st(8 * timer, make_pair(-1, 0));
  function<void(int, int, int, int, int)> modify = [&](int node, int l, int r, int i, int x) {
    if (l == r) {
      st[node] = {x, l};
      return;
    }
    int mid = l + r >> 1;
    if (i <= mid) {
      modify(node + node, l, mid, i, x);
    } else {
      modify(node + node + 1, mid + 1, r, i, x);
    }
    st[node] = max(st[node + node], st[node + node + 1]);
  };
  function<pair<int, int>(int, int, int, int, int)> query = [&](int node, int l, int r, int ll, int rr) {
    if (l > r || l > rr || r < ll) return make_pair(-1, 0);
    if (ll <= l && r <= rr) return st[node];
    int mid = l + r >> 1;
    return max(query(node + node, l, mid, ll, rr), query(node + node + 1, mid + 1, r, ll, rr));
  };
  for (int i = 0; i < p.size(); i++) {
    modify(1, 1, timer, tout[i], p[i]);
  }
  for (int i = 0; i < q; i++) {
    if (op[i] == 2) {
      continue;
    }
    auto it = query(1, 1, timer, tin[id[i]], tout[id[i]]);
    cout << it.first << '\n';
    modify(1, 1, timer, it.second, 0);
  }
  return 0;
}