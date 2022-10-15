#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int>> forward(N), backward(N);
  for (int j = 0; j < M; ++j) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    forward[u].push_back(v);
    backward[v].push_back(u);
  }
  std::vector<bool> taken(N), dead(N);
  for (int u = 0; u < N; ++u) {
    if (!dead[u]) {
      dead[u] = taken[u] = true;
      for (auto v : forward[u]) {
        dead[v] = true;
      }
    }
  }
  for (int u = N - 1; u >= 0; --u) {
    for (auto v : backward[u]) {
      if (taken[v]) {
        taken[u] = false;
      }
    }
  }
  std::vector<int> V;
  for (int u = 0; u < N; ++u) {
    if (taken[u]) {
      V.push_back(u);
    }
  }
  int k = V.size();
  std::cout << k << '\n';
  for (int j = 0; j < k; ++j) {
    std::cout << V[j] + 1 << "\n "[j + 1 < k];
  }
  exit(0);
}