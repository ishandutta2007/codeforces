#include <bits/stdc++.h>
constexpr int Mmax = 2000;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::vector<bool> is_prime(Mmax, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p <= Mmax; ++p) {
    if (!is_prime[p]) continue;
    for (int n = 2 * p; n <= Mmax; n += p) {
      is_prime[n] = false;
    }
  }
  int N;
  std::cin >> N;
  int M = N;
  while (!is_prime[M]) ++M;
  assert(M - N <= N / 2);
  std::vector<std::array<int, 2>> edges;
  for (int i = 0; i < N; ++i) {
    edges.push_back({i, (i + 1) % N});
  }
  for (int i = 0; i < M - N; ++i) {
    edges.push_back({i, i + N / 2});
  }
  std::cout << M << '\n';
  for (auto [u, v] : edges) {
    std::cout << u + 1 << ' ' << v + 1 << '\n';
  }
  exit(0);
}