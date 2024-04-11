#include <bits/stdc++.h>

template <int N>
struct Z2GaussianElimination {
  using V = std::bitset<N>;
  V basis[N], alpha[N];
  int dim = 0, first[N];
  std::pair<int, V> reduce(V& x) const {
    V coef;
    for (int i = N - 1; i >= 0; --i) {
      if (x[i] == 0) continue;
      if (basis[i] == 0) return std::pair(i, coef);
      x ^= basis[i], coef ^= alpha[i];
    }
    return std::pair(-1, coef);
  }
  bool insert(V x) {
    auto [i, coef] = reduce(x);
    if (i == -1) return false;
    basis[i] = x;
    alpha[i] = coef;
    alpha[i][dim] = 1;
    first[dim] = i;
    ++dim;
    return true;
  }
  std::pair<bool, V> solve(V x) const {
    auto [i, coef] = reduce(x);
    return std::pair(i == -1, coef);
  }
  void exchange(int r, V x) {
    auto [k, coef] = reduce(x);
    assert(k == -1);
    assert(coef[r] == 1);
    for (int i = 0; i < N; ++i) {
      if (alpha[i][r]) {
        alpha[i] ^= coef;
        alpha[i][r] = 1;
      }
    }
  }
};

constexpr int K = 30;
using V = std::bitset<K>;

struct DSU {
  std::vector<int> p, rk;
  std::vector<V> c;
  DSU(int N) : p(N), rk(N), c(N) {
    std::iota(p.begin(), p.end(), 0);
  }
  int find(int u) {
    if (p[u] != u) {
      int v = find(p[u]);
      c[u] ^= c[p[u]];
      p[u] = v;
    }
    return p[u];
  }
  V query(int u) {
    find(u);
    return c[u];
  }
  bool unite(int u, int v, V x) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return false;
    if (rk[pu] < rk[pv]) {
      std::swap(pu, pv);
    }
    p[pv] = pu;
    c[pv] = x ^ c[u] ^ c[v];
    rk[pu] += rk[pu] == rk[pv];
    return true;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  DSU dsu(N);
  Z2GaussianElimination<K> g;
  for (int j = 0; j < M; ++j) {
    int x, y, w;
    std::cin >> x >> y >> w;
    --x, --y;
    if (!dsu.unite(x, y, w)) {
      g.insert(V(w) ^ dsu.query(x) ^ dsu.query(y));
    }
  }
  V x = dsu.query(0) ^ dsu.query(N - 1);
  V cost;
  while (true) {
    auto [k, coef] = g.reduce(x);
    if (k == -1) break;
    cost.flip(k);
    x.flip(k);
  }
  std::cout << cost.to_ullong() << '\n';
  exit(0);
}