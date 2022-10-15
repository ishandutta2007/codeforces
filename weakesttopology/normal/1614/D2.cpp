#include <bits/stdc++.h>
constexpr int amax = 2e7;
int64_t dp[amax + 1], f[amax + 1], cnt[amax + 1];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int a;
    std::cin >> a;
    ++f[a];
  }
  for (int x = amax; x >= 1; --x) {
    cnt[x] = f[x];
    for (int y = 2 * x; y <= amax; y += x) {
      if (cnt[y] == 0) continue;
      cnt[x] += f[y];
      dp[x] = std::max(dp[x], dp[y] - cnt[y] * x);
    }
    dp[x] += cnt[x] * x;
  }
  std::cout << dp[1] << '\n';
  exit(0);
}