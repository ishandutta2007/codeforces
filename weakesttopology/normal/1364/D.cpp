#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M, K;
  std::cin >> N >> M >> K;
  std::vector<std::vector<int>> E(N);
  for (int j = 0; j < M; ++j) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  std::vector<int> p(N, -1), h(N, -1);
  std::vector<bool> leaf(N);
  int r = -1;
  std::vector<int> V[2];
  auto dfs = [&](auto& self, int u) -> void {
    V[h[u] % 2].push_back(u);
    leaf[u] = true;
    for (auto v : E[u]) {
      if (v == p[u]) continue;
      if (h[v] == -1) {
        leaf[u] = false;
        p[v] = u;
        h[v] = h[u] + 1;
        self(self, v);
      } else if (h[v] < h[u]) {
        if (h[u] - h[v] < K) {
          int c = h[u] - h[v] + 1;
          std::cout << "2\n" << c << '\n';
          for (int w = u; true; w = p[w]) {
            std::cout << w + 1 << ' ';
            if (w == v) break;
          }
          std::cout << '\n';
          exit(0);
        } else {
          r = u;
        }
      }
    }
  };
  h[0] = 0;
  dfs(dfs, 0);
  std::vector<int> U;
  if (r == -1) {
    int o = V[1].size() >= V[0].size();
    assert(V[o].size() >= (K + 1) / 2);
    V[o].resize((K + 1) / 2);
    U = V[o];
  } else {
    int v = r;
    for (int i = 0; i < K; ++i) {
      if (i % 2 == 0) {
        U.push_back(v);
      }
      assert(v != -1);
      v = p[v];
    }
  }
  std::cout << "1\n";
  for (auto v : U) {
    std::cout << v + 1 << ' ';
  }
  std::cout << '\n';
  exit(0);
}