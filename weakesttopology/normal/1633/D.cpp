#include <bits/stdc++.h>
constexpr int bmax = 1000;
int d[bmax + 1];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  memset(d, 0x3f, sizeof(d));
  std::queue<int> q;
  q.push(1);
  d[1] = 0;
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    int nd = d[a] + 1;
    for (int x = 1; x <= a; x = a / (a / x) + 1) {
      int b = a + a / x;
      if (b <= bmax && nd < d[b]) {
        d[b] = nd;
        q.push(b);
      }
    }
  }
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> b(N), c(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> b[i];
    }
    for (int i = 0; i < N; ++i) {
      std::cin >> c[i];
    }
    int tot = 0;
    for (int i = 0; i < N; ++i) {
      tot += d[b[i]];
    }
    K = std::min(K, tot);
    std::vector<int64_t> dp(tot + 1);
    for (int i = 0; i < N; ++i) {
      int w = d[b[i]];
      for (int k = K - w; k >= 0; --k) {
        dp[k + w] = std::max(dp[k + w], dp[k] + c[i]);
      }
    }
    std::cout << dp[K] << '\n';
  }
  exit(0);
}