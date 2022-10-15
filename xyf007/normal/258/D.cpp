#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, m, a[1001];
double dp[1001][1001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = a[i] > a[j];
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    for (int j = 1; j <= n; j++) {
      if (j == x || j == y) {
        continue;
      }
      dp[x][j] = dp[y][j] = (dp[x][j] + dp[y][j]) / 2;
      dp[j][x] = dp[j][y] = 1 - dp[x][j];
    }
    dp[x][y] = dp[y][x] = 0.5;
  }
  double ans = 0.0;
  for (int i = 1; i <= n; i++) {
    ans += std::accumulate(dp[i] + i, dp[i] + n + 1, 0.0);
  }
  std::cout << std::setprecision(8) << std::fixed << ans;
  return 0;
}