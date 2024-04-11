#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n, m;
long long a[101][101], b[101][101], dp[101][101];
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) std::cin >> a[i][j];
  long long ans = std::numeric_limits<long long>().max();
  for (int x = 1; x <= n; x++)
    for (int y = 1; y <= m; y++) {
      for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++) b[i][j] = a[x][y] - (x - i) - (y - j);
      for (int i = x; i <= n; i++)
        for (int j = y; j <= m; j++) b[i][j] = a[x][y] + (i - x) + (j - y);
      for (int i = 1; i <= n; i++) std::memset(dp[i] + 1, 0x3f, 8 * m);
      dp[x][y] = 0;
      for (int i = x; i >= 1; i--)
        for (int j = y - (i == x); j >= 1; j--)
          if (b[i][j] > a[i][j]) {
            dp[i][j] = -1;
          } else {
            if (i < x && dp[i + 1][j] != -1) checkmin(dp[i][j], dp[i + 1][j]);
            if (j < y && dp[i][j + 1] != -1) checkmin(dp[i][j], dp[i][j + 1]);
            if (dp[i][j] == 0x3f3f3f3f3f3f3f3fLL)
              dp[i][j] = -1;
            else
              dp[i][j] += a[i][j] - b[i][j];
          }
      for (int i = x; i <= n; i++)
        for (int j = y + (i == x); j <= m; j++)
          if (b[i][j] > a[i][j]) {
            dp[i][j] = -1;
          } else {
            if (i > x && dp[i - 1][j] != -1) checkmin(dp[i][j], dp[i - 1][j]);
            if (j > y && dp[i][j - 1] != -1) checkmin(dp[i][j], dp[i][j - 1]);
            if (dp[i][j] == 0x3f3f3f3f3f3f3f3fLL)
              dp[i][j] = -1;
            else
              dp[i][j] += a[i][j] - b[i][j];
          }
      if (dp[1][1] != -1 && dp[n][m] != -1) checkmin(ans, dp[1][1] + dp[n][m]);
    }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}