#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int>> I(M);
  std::vector<int> f(M), c(N);
  for (int i = 0; i < N; ++i) {
    int p;
    std::cin >> p >> c[i];
    --p;
    ++f[p];
    I[p].push_back(i);
  }
  for (int j = 0; j < M; ++j) {
    std::sort(I[j].begin(), I[j].end(), [&](int i, int j) { return c[i] < c[j]; });
  }
  std::vector<int> S(N);
  std::iota(S.begin(), S.end(), 0);
  std::sort(S.begin(), S.end(), [&](int i, int j) { return c[i] < c[j]; });
  int64_t ans = std::numeric_limits<int64_t>::max();
  for (int k = 1; k <= N; ++k) {
    std::vector<bool> dead(N);
    for (auto i : I[0]) {
      dead[i] = true;
    }
    int nf = f[0];
    int64_t cost = 0;
    for (int j = 1; j < M; ++j) {
      int take = std::max(0, f[j] - (k - 1));
      for (int l = 0; l < take; ++l) {
        int i = I[j][l];
        dead[i] = true;
        ++nf;
        cost += c[i];
      }
    }
    if (nf < k) {
      for (auto i : S) {
        if (!dead[i]) {
          cost += c[i];
          ++nf;
          if (nf == k) break;
        }
      } 
    }
    ans = std::min(ans, cost);
  }
  std::cout << ans << '\n';
  exit(0);
}