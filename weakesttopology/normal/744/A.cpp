#include <bits/stdc++.h>
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
  int N, M, K;
  std::cin >> N >> M >> K;
  std::vector<int> c(K);
  for (int j = 0; j < K; ++j) {
    std::cin >> c[j];
    --c[j];
  }
  DSU dsu(N);
  for (int j = 0; j < M; ++j) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    dsu.unite(u, v);
  }
  std::vector<int> sz(N);
  for (int u = 0; u < N; ++u) {
    ++sz[dsu.find(u)];
  }
  std::vector<bool> on(N);
  int max = 0;
  for (int j = 0; j < K; ++j) {
    int u = dsu.find(c[j]);
    on[u] = true;
    max = std::max(max, sz[u]);
  }
  int64_t ans = 0;
  for (int u = 0; u < N; ++u) {
    if (u == dsu.find(u)) {
      ans += sz[u] * (sz[u] - 1) / 2;
      if (!on[u]) {
        ans += sz[u] * max;
        max += sz[u];
      }
    }
  }
  ans -= M;
  std::cout << ans << '\n';
  exit(0);
}