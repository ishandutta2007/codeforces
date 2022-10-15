#include <bits/stdc++.h>
constexpr int64_t inf = std::numeric_limits<int64_t>::max();
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
      std::cin >> b[i];
    }
    int64_t offset = 0;
    for (int i = 0; i < N; ++i) {
      offset += a[i] * a[i] + b[i] * b[i];
    }
    offset *= N - 1;
    int maxsum = 100 * N;
    std::vector<int64_t> dp(maxsum + 1, inf);
    dp[0] = 0;
    int tot = 0;
    for (int i = 0; i < N; ++i) {
      std::vector<int64_t> ndp(maxsum + 1, inf);
      for (int sum = 0; sum <= maxsum; ++sum) {
        if (dp[sum] == inf) continue;
        for (int t = 0; t < 2; ++t) {
          std::swap(a[i], b[i]);
          int64_t cost = a[i] * sum + b[i] * (tot - sum);
          int nsum = sum + a[i];
          ndp[nsum] = std::min(ndp[nsum], dp[sum] + cost);
        }
      }
      tot += a[i] + b[i];
      std::swap(dp, ndp);
    }
    int64_t ans = offset + 2 * *std::min_element(dp.begin(), dp.end());
    std::cout << ans << '\n';
  }
  exit(0);
}