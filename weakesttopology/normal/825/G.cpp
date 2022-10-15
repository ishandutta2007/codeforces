#include <bits/stdc++.h>

constexpr int inf = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<std::vector<int>> E(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  std::vector<int> h(N), min(N, inf);
  auto dfs = [&](auto& self, int u, int p) -> void {
    for (auto v : E[u]) {
      if (v == p) continue;
      min[v] = h[v] = std::min(h[u], v);
      self(self, v, u);
      min[u] = std::max(min[u], min[v]);
    }
  };
  int root;
  std::cin >> root >> root;
  root %= N;
  min[root] = h[root] = root;
  dfs(dfs, root, -1);
  int last = 0;
  int globalmin = inf;
  for (int q = 1; q < Q; ++q) {
    int t, z;
    std::cin >> t >> z;
    int x = (last + z) % N;
    if (t == 1) {
      globalmin = std::min(globalmin, h[x]);
    } else {
      last = std::min(globalmin, h[x]) + 1;
      std::cout << last << '\n';
    }
  }
  exit(0);
}