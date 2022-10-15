#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, a[51], p;
double fac[51], dp[51][51][51];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::cin >> p;
  if (std::accumulate(a + 1, a + n + 1, 0) <= p) {
    std::cout << n;
    return 0;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i;
  }
  double ans = 0.0;
  for (int x = 1; x <= n; x++) {
    std::memset(dp, 0.0, sizeof(dp));
    dp[0][0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= p; k++) {
          if (i == x) {
            dp[i][j][k] = dp[i - 1][j][k];
            continue;
          }
          dp[i][j][k] = dp[i - 1][j][k];
          if (k >= a[i] && j) {
            dp[i][j][k] += dp[i - 1][j - 1][k - a[i]];
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = std::max(0, p - a[x] + 1); j <= p; j++) {
        ans += i * fac[i] * fac[n - i - 1] * dp[n][i][j];
      }
    }
  }
  std::cout << std::setprecision(6) << std::fixed << ans / fac[n];
  return 0;
}