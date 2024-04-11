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
int n, m, k, a[200001], sum[2001], b[2001], dp[2001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::sort(a + 1, a + n + 1), n = k;
  std::partial_sum(a + 1, a + n + 1, sum + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (x > k) continue;
    checkmax(b[x], y);
  }
  std::memset(dp, 0x3f, sizeof(dp)), dp[0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 1; i + j <= n; j++)
      checkmin(dp[i + j], dp[i] + sum[n - i] - sum[n - i - j + b[j]]);
  std::cout << dp[n];
  return 0;
}