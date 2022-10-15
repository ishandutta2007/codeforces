#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> h(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> h[i];
  }
  std::vector<std::vector<int>> E(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  std::vector<int64_t> cost(N);
  std::vector<int> maxh(N);
  auto dfs = [&](auto& self, int u, int p) -> void {
    for (auto v : E[u]) {
      if (v == p) continue;
      self(self, v, u);
      cost[u] += cost[v];
      cost[u] += std::min(maxh[u], maxh[v]);
      maxh[u] = std::max(maxh[u], maxh[v]);
    }
    maxh[u] = std::max(maxh[u], h[u]);
  };
  int root = std::max_element(h.begin(), h.end()) - h.begin();
  int64_t ans = 2 * h[root];
  for (auto v : E[root]) {
    dfs(dfs, v, root);
    ans += cost[v];
  }
  std::sort(E[root].begin(), E[root].end(), [&](int u, int v) { return maxh[u] > maxh[v]; });
  for (int i = 2; i < E[root].size(); ++i) {
    int v = E[root][i];
    ans += maxh[v];
  }
  std::cout << ans << '\n';
  exit(0);
}