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
int n, k, m, a[201];
long long dp[201][201][201];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memset(dp, 0xcf, sizeof(dp));
  dp[0][0][0] = 0LL;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      for (int u = 0; u < i; u++) dp[i][j][u] = dp[i - 1][j][u];
      if (!j) continue;
      int l = std::max(0, i - k);
      long long max = 0xcfcfcfcfcfcfcfcfLL;
      for (int u = l; u < i; u++) checkmax(max, dp[i - 1][j - 1][u]);
      dp[i][j][i] = max + a[i];
    }
  long long ans = *std::max_element(dp[n][m] + n - k + 1, dp[n][m] + n + 1);
  std::cout << (ans < 0 ? -1 : ans);
  return 0;
}