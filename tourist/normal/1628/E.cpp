/**
 *    author:  tourist
 *    created: 22.01.2022 18:17:55       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class forest : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  forest(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable() {}

  void init(const vector<T>& a, const F& f) {
    func = f;
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

function<int(int, int)> GetMax;

SparseTable<int> saux;

class segtree {
 public:
  struct node {
    int mx = -1;
    int put = 0;
    int L = -1;
    int R = -1;

    void apply(int l, int r, int v) {
      if (v == -1) {
        mx = put = L = R = -1;
      } else {
        assert(v == 1);
        mx = (l == r ? -1 : saux.get(l, r - 1));
        put = 1;
        L = l;
        R = r;
      }
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.mx = max(a.mx, b.mx);
    res.L = (a.L != -1 ? a.L : b.L);
    res.R = (b.R != -1 ? b.R : a.R);
    if (a.R != -1 && b.L != -1) {
      res.mx = max(res.mx, GetMax(a.R, b.L));
    }
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].put != 0) {
      tree[x + 1].apply(l, y, tree[x].put);
      tree[z].apply(y + 1, r, tree[x].put);
      tree[x].put = 0;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};


namespace bam {

const int N = 600010;

int dsu[N];

int get(int v) {
  if (v == dsu[v]) {
    return v;
  } else {
    return dsu[v] = get(dsu[v]);
  }
}

vector<int> st[N];
vector<int> w[N];

void uni(int u, int v, int i) {
  u = get(u), v = get(v);
  if (st[u].size() > st[v].size()) {
    swap(u, v);
  }
  w[v].push_back(i);
  for (int x : w[u]) {
    w[v].push_back(x);
  }
  for (int x : st[u]) {
    st[v].push_back(x);
  }
  dsu[u] = v;
}
  
} // bam

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  forest<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    g.add(x, y, z);
  }
  vector<int> order(n - 1);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return g.edges[i].cost < g.edges[j].cost;
  });
  for (int i = 0; i < n; i++) {
    bam::dsu[i] = i;
    bam::st[i].push_back(i);
  }
  for (int i : order) {
    bam::uni(g.edges[i].from, g.edges[i].to, g.edges[i].cost);
  }
  int root = bam::get(0);
  vector<int> ind(n);
  for (int i = 0; i < n; i++) {
    ind[bam::st[root][i]] = i;
  }
  vector<int> ws(n, -1);
  for (int i = 0; i < n - 1; i++) {
    ws[i] = bam::w[root][i];
  }
  SparseTable<int> sm;
  sm.init(ws, [&](int i, int j) { return max(i, j); });
  GetMax = [&](int u, int v) {
    int L = ind[u];
    int R = ind[v];
    if (L > R) {
      swap(L, R);
    }
    if (L == R) {
      return -1;
    }
    return sm.get(L, R - 1);
  };
  vector<int> vaux(n, -1);
  for (int i = 0; i < n - 1; i++) {
    vaux[i] = GetMax(i, i + 1);
  }
  saux.init(vaux, [&](int i, int j) { return max(i, j); });
  segtree st(n);
  while (tt--) {
    int op;
    cin >> op;
    if (op == 1 || op == 2) {
      int l, r;
      cin >> l >> r;
      --l; --r;
      st.modify(l, r, op == 1 ? 1 : -1);
    }
    if (op == 3) {
      int x;
      cin >> x;
      --x;
      auto nd = st.get(0, n - 1);
      int mx = nd.mx;
      if (nd.L != -1) {
        mx = max(mx, GetMax(x, nd.L));
      }
      cout << mx << '\n';
    }
  }
  return 0;
}