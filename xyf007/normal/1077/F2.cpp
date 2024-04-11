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
int n, k, m, a[5001];
long long dp[5001][5001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memset(dp, 0xcf, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= m; i++) {
    std::deque<int> q;
    for (int j = 0; j <= n; j++) {
      while (!q.empty() && q.front() < j - k) q.pop_front();
      if (!q.empty()) dp[i][j] = dp[i - 1][q.front()] + a[j];
      while (!q.empty() && dp[i - 1][j] >= dp[i - 1][q.back()]) q.pop_back();
      q.emplace_back(j);
    }
  }
  long long ans = *std::max_element(dp[m] + n - k + 1, dp[m] + n + 1);
  if (ans < 0) ans = -1;
  std::cout << ans;
  return 0;
}