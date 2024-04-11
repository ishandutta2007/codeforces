#include <bits/stdc++.h>

template <typename T, typename F>
struct LazySegmentTree {
  struct Node {
    T value = T();
    F lazy = F();
    int l, r;
  };
  int N;
  std::vector<Node> st;
  int left(int p) const {
    return 2 * p + 1;
  }
  int right(int p) const {
    return 2 * p + 2;
  }
  void push(int p) {
    if (st[p].l + 1 == st[p].r) return;
    for (int q : {left(p), right(p)}) {
      st[p].lazy.apply(st[q]);
      st[q].lazy.compose(st[p].lazy);
    }
    st[p].lazy = F();
  }
  void update(int p, int ql, int qr, F f) {
    if (st[p].r <= ql || qr <= st[p].l || f.can_break(st[p])) {
      return;
    } else if (ql <= st[p].l && st[p].r <= qr && f.can_apply(st[p])) {
      f.apply(st[p]);
      st[p].lazy.compose(f);
    } else {
      push(p);
      update(left(p), ql, qr, f);
      update(right(p), ql, qr, f);
      st[p].value = st[left(p)].value + st[right(p)].value;
    }
  }
  T query(int p, int ql, int qr) {
    if (st[p].r <= ql || qr <= st[p].l) {
      return T();
    } else if (ql <= st[p].l && st[p].r <= qr) {
      return st[p].value;
    } else {
      push(p);
      return query(left(p), ql, qr) + query(right(p), ql, qr);
    }
  }
  template <typename Iterator>
  void build(int p, int l, int r, Iterator first) {
    st[p].l = l, st[p].r = r;
    if (l + 1 == r) {
      st[p].value = first[l];
    } else {
      int m = l + (r - l) / 2;
      build(left(p), l, m, first), build(right(p), m, r, first);
      st[p].value = st[left(p)].value + st[right(p)].value;
    }
  }
  void partition(std::vector<int>& q, int p, int ql, int qr) {
    if (st[p].r <= ql || qr <= st[p].l) {
      return;
    } else if (ql <= st[p].l && st[p].r <= qr) {
      q.push_back(p);
    } else {
      push(p);
      partition(q, left(p), ql, qr);
      partition(q, right(p), ql, qr);
    }
  }
  template <typename Pred>
  int binary_search(int p, T prefix, Pred&& pred) {
    if (st[p].l + 1 == st[p].r) {
      return st[p].l;
    } else {
      push(p);
      T nprefix = prefix + st[left(p)].value;
      if (pred(nprefix)) {
        return binary_search(right(p), nprefix, pred);
      } else {
        return binary_search(left(p), prefix, pred);
      }
    }
  }
  template <typename Iterator>
  LazySegmentTree(Iterator first, Iterator last) : N(last - first), st(4 * N) {
    build(0, 0, N, first);
  }
  T query(int l, int r) {
    return query(0, l, r);
  }
  void update(int l, int r, F f) {
    update(0, l, r, f);
  }
  int lower_bound(int l, int r, T target) {
    return find_right(l, r, [target](T value) { return value < target; });
  }
  // Returns largest i in [l, r] with pred(query(l, i)) == true.
  template <typename Pred>
  int find_right(int l, int r, Pred&& pred) {
    static std::vector<int> q;
    partition(q, 0, l, r);
    int res = r;
    T prefix = T();
    for (auto p : q) {
      T nprefix = prefix + st[p].value;
      if (pred(nprefix)) {
        prefix = nprefix;
      } else {
        res = binary_search(p, prefix, pred);
        break;
      }
    }
    q.clear();
    return res;
  }
};

constexpr int inf = std::numeric_limits<int>::max();
struct M {
  int max_active, max;
  int min_active, min;
  M() :
    max_active(-inf), max(-inf),
    min_active(+inf), min(+inf) {} 
  M(int x) :
    max_active(-inf), max(x),
    min_active(+inf), min(x) {} 
  M operator+(const M& rhs) const {
    M res;
    res.max_active = std::max(max_active, rhs.max_active);
    res.max = std::max(max, rhs.max);
    res.min_active = std::min(min_active, rhs.min_active);
    res.min = std::min(min, rhs.min);
    return res;
  }
};

enum Operation {activate, deactivate, nothing};
struct F {
  Operation op;
  F(Operation op = nothing) : op(op) {}
  template <typename Node>
  bool can_break(const Node& p) const {
    return op == nothing;
  }
  template <typename Node>
  bool can_apply(const Node& p) const {
    return true;
  }
  template <typename Node>
  void apply(Node& p) const {
    if (op == nothing) {
      return;
    } else if (op == activate) {
      p.value.max_active = p.value.max;
      p.value.min_active = p.value.min;
    } else {
      assert(op == deactivate);
      p.value.max_active = -inf;
      p.value.min_active = +inf;
    }
  }
  void compose(F upd) {
    if (upd.op != nothing) {
      op = upd.op;
    }
  }
};

// K > floor(log(tree height))
template <int K>
struct LCA {
  const std::vector<std::vector<int>>& E;
  int N;
  std::vector<int> L, R, inv, h;
  std::vector<std::array<int, K>> up;
  int timer = 0;
  void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 0; i + 1 < K; ++i) up[u][i + 1] = up[up[u][i]][i];
    inv[L[u] = timer++] = u;
    for (int v : E[u]) {
      if (v == p) continue;
      h[v] = h[u] + 1;
      dfs(v, u);
    }
    R[u] = timer;
  }
  LCA(const std::vector<std::vector<int>>& E, int root)
      : E(E), N(E.size()), L(N), R(N), inv(N), h(N), up(N) {
    dfs(root, root);
  }
  bool is_ancestor(int u, int v) const {
    return L[u] <= L[v] && R[v] <= R[u];
  }
  int lca(int u, int v) const {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = K - 1; i >= 0; --i) {
      if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
  }
  int dist(int u, int v) const {
    int w = lca(u, v);
    return h[u] + h[v] - 2 * h[w];
  }
};

struct DSU {
  std::vector<int> p, rk;
  DSU(int N) : p(N), rk(N) {
    std::iota(p.begin(), p.end(), 0);
  }
  int find(int u) {
    return p[u] == u ? u : p[u] = find(p[u]);
  }
  void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (rk[u] < rk[v]) {
      std::swap(u, v);
    }
    p[v] = u, rk[u] += (rk[u] == rk[v]);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<std::tuple<int, int, int>> edges(N - 1);
  for (auto& [w, u, v] : edges) {
    std::cin >> u >> v >> w;
    --u, --v;
  }
  std::sort(edges.begin(), edges.end());
  std::vector<int> label(N);
  std::iota(label.begin(), label.end(), 0);
  DSU dsu(N);
  std::vector<std::vector<int>> E(2 * N - 1);
  for (int i = 0; i < N - 1; ++i) {
    auto [w, u, v] = edges[i];
    u = dsu.find(u), v = dsu.find(v);
    E[N + i].push_back(label[u]);
    E[N + i].push_back(label[v]);
    label[u] = label[v] = N + i;
    dsu.unite(u, v);
  }
  int root = 2 * N - 2;
  LCA<20> lca(E, root);
  std::vector<int> t(N), inv(N);
  int timer = 0;
  auto tour = [&](auto& self, int u) -> void {
    if (u < N) {
      t[u] = timer++;
      inv[t[u]] = u;
    }
    for (auto v : E[u]) {
      self(self, v);
    }
  };
  tour(tour, root);
  LazySegmentTree<M, F> st(t.begin(), t.end());
  for (int q = 0; q < Q; ++q) {
    int type;
    std::cin >> type;
    if (type == 3) {
      int x;
      std::cin >> x;
      --x;
      auto info = st.query(0, x) + st.query(x + 1, N);
      int ans = -1;
      if (info.max_active != -inf) {
        int il = lca.lca(x, inv[info.min_active]);
        int ir = lca.lca(x, inv[info.max_active]);
        assert(il >= N);
        assert(ir >= N);
        ans = std::max(std::get<0>(edges[il - N]), std::get<0>(edges[ir - N]));
      }
      std::cout << ans << '\n';
    } else {
      int l, r;
      std::cin >> l >> r;
      --l;
      st.update(l, r, (type == 1 ? activate : deactivate));
    }
  }
  exit(0);
}