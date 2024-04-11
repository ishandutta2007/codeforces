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
int n, m, d, c[2001], w[2001], dp[2001][2001];
bool f[2001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> d >> n >> m;
  for (int i = 1; i <= n; i++) {
    int l, r;
    std::cin >> l >> r;
    for (int j = l + 1; j <= r; j++) f[j] = true;
  }
  w[0] = 0x3f3f3f3f;
  for (int i = 1; i <= m; i++) {
    int p;
    std::cin >> p >> w[i];
    if (w[i] < w[c[p]]) c[p] = i;
  }
  std::memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= d; i++)
    for (int j = 0; j <= m; j++) {
      if (!f[i]) checkmin(dp[i][0], dp[i - 1][j]);
      if (j) checkmin(dp[i][j], dp[i - 1][j] + w[j]);
      if (c[i - 1]) checkmin(dp[i][c[i - 1]], dp[i - 1][j] + w[c[i - 1]]);
    }
  int ans = *std::min_element(dp[d], dp[d] + m + 1);
  std::printf("%d", ans == 0x3f3f3f3f ? -1 : ans);
  return 0;
}