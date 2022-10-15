#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<std::pair<int, int>>> E(N);
    std::vector<int> deg(N);
    for (int j = 0; j < M; ++j) {
      int u, v;
      std::cin >> u >> v;
      --u, --v;
      ++deg[u];
      ++deg[v];
      E[u].emplace_back(v, j);
      E[v].emplace_back(u, j);
    }
    std::vector<bool> dead(M);
    std::vector<int> from(M), to(M);
    auto go = [&](int u) -> int {
      while (!E[u].empty()) {
        auto [v, j] = E[u].back();
        if (dead[j]) {
          E[u].pop_back();
        } else {
          dead[j] = true;
          --deg[u], --deg[v];
          from[j] = u, to[j] = v;
          return v;
        }
      }
      return -1;
    };
    int ans = N;
    for (int u = 0; u < N; ++u) {
      if (deg[u] % 2) {
        ans -= 2;
        for (int v = u; deg[v] % 2; v = go(v));
      }
    }
    for (int u = 0; u < N; ++u) {
      assert(deg[u] % 2 == 0);
    }
    for (int s = 0; s < N; ++s) {
      for (int v = s; deg[s] > 0; v = go(v));
    }
    std::cout << ans << '\n';
    for (int j = 0; j < M; ++j) {
      std::cout << from[j] + 1 << ' ' << to[j] + 1 << '\n';
    }
  }
  exit(0);
}