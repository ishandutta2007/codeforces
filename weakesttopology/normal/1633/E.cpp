#include <bits/stdc++.h>

struct Edge {
  int w;
  std::array<int, 2> e;
  int cost(int x) const {
    return std::abs(w - x);
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
  int N, M;
  std::cin >> N >> M;
  std::vector<Edge> edges;
  for (int j = 0; j < M; ++j) {
    int u, v, w;
    std::cin >> u >> v >> w;
    --u, --v;
    edges.push_back({w, {u, v}});
  }
  std::sort(edges.begin(), edges.end(),
      [](auto e, auto f) { return e.w < f.w; });
  std::vector<int> pts = {0};
  for (int j = 0; j < M; ++j) {
    auto e = edges[j];
    pts.push_back(e.w);
    for (int i = j + 1; i < M; ++i) {
      auto f = edges[i];
      pts.push_back((e.w + f.w) / 2 + 1);
    }
  }
  std::sort(pts.begin(), pts.end());
  pts.erase(std::unique(pts.begin(), pts.end()), pts.end());
  int K = pts.size();
  std::vector<int64_t> a(K), b(K);
  for (int k = 0; k < K; ++k) {
    int x = pts[k];
    std::sort(edges.begin(), edges.end(),
        [&](auto e, auto f) { return e.cost(x) < f.cost(x); });
    DSU dsu(N);
    for (auto e : edges) {
      int u[2];
      for (int t : {0, 1}) {
        u[t] = dsu.find(e.e[t]);
      }
      if (u[0] != u[1]) {
        dsu.unite(u[0], u[1]);
        if (x < e.w) {
          a[k] -= 1;
          b[k] += e.w;
        } else {
          a[k] += 1;
          b[k] -= e.w;
        }
      }
    }
  }
  int P, Q, A, B, C;
  std::cin >> P >> Q >> A >> B >> C;
  std::vector<int> q(Q);
  for (int j = 0; j < P; ++j) {
    std::cin >> q[j];
  }
  for (int j = P; j < Q; ++j) {
    q[j] = (1LL * q[j - 1] * A + B) % C;
  }
  int64_t xorsum = 0;
  for (int j = 0; j < Q; ++j) {
    int k = std::upper_bound(pts.begin(), pts.end(), q[j]) - pts.begin() - 1;
    int64_t ans = a[k] * q[j] + b[k];
    xorsum ^= ans;
    //std::cout << ans << '\n';
  }
  std::cout << xorsum << '\n';
  exit(0);
}