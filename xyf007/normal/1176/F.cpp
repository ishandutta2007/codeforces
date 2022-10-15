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
int n;
long long dp[200001][11];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::memset(dp, 0xcf, sizeof(dp));
  dp[0][0] = 0LL;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int k;
    std::vector<long long> a[4];
    std::cin >> k;
    while (k--) {
      int c;
      long long w;
      std::cin >> c >> w;
      a[c].emplace_back(w);
    }
    for (int j = 1; j <= 3; j++)
      std::sort(a[j].begin(), a[j].end(), std::greater<long long>());
    if (a[1].size() >= 3) {
      long long s = a[1][0] + a[1][1] + a[1][2];
      for (int j = 0; j < 10; j++)
        checkmax(dp[i][(j + 3) % 10], dp[i - 1][j] + s + (j >= 7) * a[1][0]);
    }
    if (!a[1].empty() && !a[2].empty()) {
      long long s = a[1][0] + a[2][0], db = std::max(a[1][0], a[2][0]);
      for (int j = 0; j < 10; j++)
        checkmax(dp[i][(j + 2) % 10], dp[i - 1][j] + s + (j >= 8) * db);
    }
    if (!a[3].empty()) {
      long long s = a[3][0];
      for (int j = 0; j < 10; j++)
        checkmax(dp[i][(j + 1) % 10], dp[i - 1][j] + s + (j == 9) * s);
    }
    if (!a[2].empty()) {
      long long s = a[2][0];
      for (int j = 0; j < 10; j++)
        checkmax(dp[i][(j + 1) % 10], dp[i - 1][j] + s + (j == 9) * s);
    }
    if (a[1].size() >= 2) {
      long long s = a[1][0] + a[1][1];
      for (int j = 0; j < 10; j++)
        checkmax(dp[i][(j + 2) % 10], dp[i - 1][j] + s + (j >= 8) * a[1][0]);
    }
    if (!a[1].empty()) {
      long long s = a[1][0];
      for (int j = 0; j < 10; j++)
        checkmax(dp[i][(j + 1) % 10], dp[i - 1][j] + s + (j == 9) * s);
    }
    for (int j = 0; j < 10; j++) checkmax(dp[i][j], dp[i - 1][j]);
  }
  std::cout << *std::max_element(dp[n], dp[n] + 10);
  return 0;
}