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
int n, m;
long long a[17][10001], b[17][17], b2[17][17], dp[17][65536];
void Init() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      long long s = 0x7fffffffffffffffLL;
      for (int k = 1; k <= m; k++) checkmin(s, std::abs(a[i][k] - a[j][k]));
      b[i][j] = s;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      b2[i][j] = 0x7fffffffffffffffLL;
      for (int k = 2; k <= m; k++)
        checkmin(b2[i][j], std::abs(a[i][k] - a[j][k - 1]));
    }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= m; j++) std::cin >> a[i][j];
  Init();
  long long ans = 0LL;
  for (int st = 0; st < n; st++) {
    std::memset(dp, 0, sizeof(dp));
    dp[st][1 << st] = 0x7fffffffffffffffLL;
    for (int S = 0; S < (1 << n); S++)
      for (int i = 0; i < n; i++)
        if ((S >> i) & 1)
          for (int j = 0; j < n; j++)
            if (!((S >> j) & 1))
              checkmax(dp[j][S | (1 << j)], std::min(dp[i][S], b[i][j]));
    for (int i = 0; i < n; i++)
      checkmax(ans, std::min(dp[i][(1 << n) - 1], b2[st][i]));
  }
  std::cout << ans;
  return 0;
}