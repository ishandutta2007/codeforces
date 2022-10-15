#include <bits/stdc++.h>
void fail() {
    std::cout << "NO\n";
    exit(0);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, D, K;
  std::cin >> N >> D >> K;
  if (N <= D || N > 2 && K == 1) {
    fail();
  }
  std::vector<std::array<int, 2>> edges;
  for (int i = 0; i < D; ++i) {
    edges.push_back({i, i + 1});
  }
  int M = D + 1;
  std::vector<int> d(M), deg(M, 2);
  deg[0] = deg[M - 1] = 1;
  std::queue<int> q;
  for (int u = 0; u < M; ++u) {
    d[u] = std::max(D / 2 - u, u - (D + 1) / 2);
    if (deg[u] < K && d[u] < D / 2) {
      q.push(u);
    }
  }
  while (M < N) {
    if (q.empty()) {
      fail();
    }
    int u = q.front();
    edges.push_back({u, M});
    deg.push_back(1);
    ++deg[u];
    if (deg[u] == K) {
      q.pop();
    }
    d.push_back(d[u] + 1);
    if (d[M] < D / 2) {
      q.push(M);
    }
    ++M;
  }
  std::cout << "YES\n";
  for (auto [u, v] : edges) {
    std::cout << u + 1 << ' ' << v + 1 << '\n';
  }
  exit(0);
}