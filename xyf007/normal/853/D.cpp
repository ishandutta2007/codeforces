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
int n, a[300001], dp[2][301];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::memset(dp, 0x3f, sizeof(dp)), dp[0][0] = 0;
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i], a[i] /= 1000;
  for (int i = 1; i <= n; i++) {
    int c = i & 1;
    std::memset(dp[c], 0x3f, sizeof(dp[c]));
    for (int j = 0; j <= 300; j++)
      if (dp[c ^ 1][j] < 1e9) {
        if (j + a[i] <= 300)
          checkmin(dp[c][j + a[i]], dp[c ^ 1][j] + a[i] * 1000);
        if (j >= a[i] * 10)
          checkmin(dp[c][j - a[i] * 10], dp[c ^ 1][j]);
        else
          checkmin(dp[c][0], dp[c ^ 1][j] + (a[i] * 10 - j) * 100);
      }
  }
  std::cout << dp[n & 1][0];
  return 0;
}