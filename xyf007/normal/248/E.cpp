#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, q, a[100001], now[100001];
double C[500101][6], dp[100001][106];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  for (int i = 0; i <= 500100; i++) {
    C[i][0] = 1.0;
    for (int j = 1; j <= 5; j++) {
      C[i][j] = C[i][j - 1] * (i - j + 1) / j;
    }
  }
  std::cin >> n;
  double ans = 0.0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    dp[i][a[i]] = 1.0;
    if (!a[i]) {
      ans += 1.0;
    }
  }
  std::memcpy(now + 1, a + 1, 4 * n);
  std::cin >> q;
  while (q--) {
    int u, v, k;
    std::cin >> u >> v >> k;
    ans -= dp[u][0];
    for (int i = 0; i <= a[u]; i++) {
      double tmp = 0.0;
      for (int j = i; j <= i + k && j <= now[u]; j++) {
        tmp += dp[u][j] * C[j][j - i] * C[now[u] - j][k + i - j];
      }
      dp[u][i] = tmp / C[now[u]][k];
    }
    now[u] -= k;
    now[v] += k;
    std::cout << std::setprecision(11) << std::fixed << (ans += dp[u][0])
              << '\n';
  }
  return 0;
}