#include <bits/stdc++.h>
using namespace std;

struct union_find {

  vector<array<int, 2>> operations;
  vector<int> add;
  vector<int> par;
  vector<int> sz;

  union_find(int n) {
    par.resize(n);
    sz.assign(n, 1);
    add.assign(n, 0);
    iota(par.begin(), par.end(), 0);
  }

  int find(int u) {
    if (par[u] != u) {
      return find(par[u]);
    }
    return par[u];
  }

  int index(int u) {
    if (par[u] != u) {
      return index(par[u]) + add[u];
    }
    return add[u];
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;

    if (sz[u] > sz[v]) {
      swap(u, v);
    }
    par[u] = v;
    add[u] += sz[v];
    sz[v] += sz[u];
    operations.push_back({u, v});
    return true;
  }

  void undo() {
    auto [u, v] = operations.back();
    operations.pop_back();
    sz[v] -= sz[u];
    par[u] = u;
  }

};

struct node {

  node* right;
  node* left;

  array<int, 2> max_a;

  void apply(int l, int a) {
    max_a = {a, l};
  }

  void pull() {
    max_a = max(right->max_a, left->max_a);
  }

};

struct segtree {

  node* root;
  int n;

  segtree(int n) : n(n) {
    root = new node();
    build(root, 0, n - 1);
  }

  void build(node* u, int l, int r) {
    if (l == r) {
      return;
    } else {
      u->left = new node();
      u->right = new node();
      int m = (l + r) / 2;
      build(u->left, l, m);
      build(u->right, m + 1, r);
      u->pull();
    }
  }

  void update(node* u, int l, int r, int a, int val) {
    if (l == r) {
      u->apply(a, val);
    } else {
      int m = (l + r) / 2;
      if (a <= m) {
        update(u->left, l, m, a, val);
      } else {
        update(u->right, m + 1, r, a, val);
      }
      u->pull();
    }
  }

  array<int, 2> query(node* u, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return u->max_a;
    } else {
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return max(query(u->left, l, m, a, b), query(u->right, m + 1, r, a, b));
      } else if (a <= m) {
        return query(u->left, l, m, a, b);
      } else {
        return query(u->right, m + 1, r, a, b);
      }
    }
  }

  void update(int a, int val) {
    update(root, 0, n - 1, a, val);
  }

  array<int, 2> query(int a, int b) {
    return query(root, 0, n - 1, a, b);
  }

};

const int N = 500'000;

array<int, 2> query[N];
int p[N];
int u[N];
int v[N];

bool deleted[N];
int ndx[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    --u[i], --v[i];
  }

  for (int i = 0; i < q; ++i) {
    cin >> query[i][0] >> query[i][1];
    --query[i][1];

    if (query[i][0] == 2) {
      deleted[query[i][1]] = true;
    }
  }

  union_find dsu(n);
  for (int i = 0; i < m; ++i) {
    if (!deleted[i]) {
      dsu.unite(u[i], v[i]);
    }
  }

  for (int i = q - 1; i >= 0; --i) {
    auto &[t, x] = query[i];
    if (t == 2) {
      x = dsu.unite(u[x], v[x]);
    }
  }

  int extra = 0;
  for (int i = 1; i < n; ++i) {
    if (dsu.find(i) != dsu.find(0)) {
      extra += dsu.unite(i, 0);
    }
  }

  segtree st(n);
  for (int i = 0; i < n; ++i) {
    ndx[i] = dsu.index(i);
    st.update(ndx[i], p[i]);
  }

  while (extra--) {
    dsu.undo();
  }

  for (int i = 0; i < q; ++i) {
    auto [t, x] = query[i];
    if (t == 1) {
      x = dsu.find(x);
      auto [a, j] = st.query(ndx[x], ndx[x] + dsu.sz[x] - 1);
      st.update(j, 0);
      cout << a << "\n";
    } else if (x == 1) {
      dsu.undo();
    }
  }
}