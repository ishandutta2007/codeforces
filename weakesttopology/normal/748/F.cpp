#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, K;
  std::cin >> N >> K;
  std::vector<std::vector<int>> E(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  std::vector<bool> on(N);
  std::vector<int> V;
  for (int k = 0; k < 2 * K; ++k) {
    int c;
    std::cin >> c;
    --c;
    on[c] = true;
    V.push_back(c);
  }
  int c = -1;
  auto dfs = [&](auto& self, int u, int p) -> int {
    int tot = on[u], max = 0;
    for (auto v : E[u]) {
      if (v == p) continue;
      int totv = self(self, v, u);
      tot += totv;
      max = std::max(max, totv);
    }
    max = std::max(max, 2 * K - tot);
    if (max <= K) {
      c = u;
    }
    return tot;
  };
  dfs(dfs, 0, -1);
  assert(c != -1);
  std::vector<int> color(N), f(N);
  auto paint = [&](auto& self, int u, int p) -> void {
    ++f[color[u]];
    for (auto v : E[u]) {
      if (v == p) continue;
      color[v] = color[u];
      self(self, v, u);
    }
  };
  f[c] = 1;
  color[c] = c;
  for (auto v : E[c]) {
    color[v] = v;
    paint(paint, v, c);
  }
  std::sort(V.begin(), V.end(),
      [&](int u, int v) { return color[u] < color[v]; });
  std::cout << "1\n" << c + 1 << '\n';
  for (int k = 0; k < K; ++k) {
    std::cout << V[k] + 1 << ' ' << V[K + k] + 1 << ' ' << c + 1 << '\n';
  }
  exit(0);
}