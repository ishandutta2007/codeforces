#include <bits/stdc++.h>
constexpr int Nmax = 500;
int64_t dp[Nmax + 1][Nmax + 1];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, L, K;
  std::cin >> N >> L >> K;
  std::vector<int> d(N + 1), a(N + 1);
  for (int i = 0; i < N; ++i) {
    std::cin >> d[i];
  }
  d[N] = L;
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < N; ++i) {
    for (int k = 0; k <= K; ++k) {
      for (int ni = i + 1, nk = k; ni <= N && nk <= K; ++ni, ++nk) {
        dp[ni][nk] = std::min(dp[ni][nk], dp[i][k] + (d[ni] - d[i]) * a[i]);
      }
    }
  }
  int64_t ans = std::numeric_limits<int64_t>::max();
  for (int k = 0; k <= K; ++k) {
    ans = std::min(ans, dp[N][k]);
  }
  std::cout << ans << '\n';
  exit(0);
}