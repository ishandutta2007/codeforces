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
int n, r, dp[101][60001];
std::vector<std::pair<int, int>> pos, neg;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> r;
  for (int i = 1; i <= n; i++) {
    int a, b;
    std::cin >> a >> b;
    if (b >= 0)
      pos.emplace_back(a, b);
    else
      neg.emplace_back(a, b);
  }
  std::sort(pos.begin(), pos.end());
  std::sort(neg.begin(), neg.end(),
            [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
              return lhs.first + lhs.second > rhs.first + rhs.second;
            });
  int ans = 0;
  for (auto &&[a, b] : pos) {
    if (r < a) break;
    r += b, ans++;
  }
  std::memset(dp, 0xcf, sizeof(dp));
  dp[0][r] = 0;
  int m = neg.size();
  for (int i = 1; i <= m; i++) {
    std::memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
    for (int j = neg[i - 1].first; j <= 60000; j++) {
      if (j + neg[i - 1].second < 0) continue;
      checkmax(dp[i][j + neg[i - 1].second], dp[i - 1][j] + 1);
    }
  }
  std::cout << (*std::max_element(dp[m], dp[m] + 60001) + ans == n ? "YES"
                                                                   : "NO");
  return 0;
}