#include <bits/stdc++.h>
std::vector<std::array<int, 2>> solve(int K) {
  if (K == 1) {
    return {};
  } else if (K == 2) {
    return {{0, 1}};
  } else {
    K /= 2;
    auto ops = solve(K);
    int N = ops.size();
    for (int i = 0; i < N; ++i) {
      auto [x, y] = ops[i];
      ops.push_back({x + K, y + K});
    }
    for (int i = 0; i < K; ++i) {
      ops.push_back({i, i + K});
    }
    return ops;
  }
} 
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  int K = 1;
  while (2 * K <= N) K *= 2;
  auto ops = solve(K);
  if (K < N) {
    auto nops = ops;
    for (auto [x, y] : ops) {
      nops.push_back({x + N - K, y + N - K});
    }
    std::swap(ops, nops);
  }
  std::cout << ops.size() << '\n';
  for (auto [x, y] : ops) {
    std::cout << x + 1 << ' ' << y + 1 << '\n';
  }
  exit(0);
}