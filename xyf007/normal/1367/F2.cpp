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
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  for (auto &&x : v) out << x << ' ';
  return out;
}
int T, n, a[200001], b[200001];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memcpy(b + 1, a + 1, 4 * n);
  std::sort(b + 1, b + n + 1);
  int nn = std::unique(b + 1, b + n + 1) - b - 1;
  std::vector<int> pos[nn + 1], dp(nn + 1);
  std::vector<std::size_t> cnt(nn + 1);
  for (int i = 1; i <= n; i++)
    cnt[a[i] = std::lower_bound(b + 1, b + nn + 1, a[i]) - b]++;
  for (int i = 1; i <= nn; i++) pos[i].reserve(cnt[i]);
  for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);
  dp[1] = pos[1].size();
  for (int i = 2; i <= nn; i++)
    if (pos[i][0] > pos[i - 1].back())
      dp[i] = dp[i - 1] + pos[i].size();
    else
      dp[i] =
          std::lower_bound(pos[i - 1].begin(), pos[i - 1].end(), pos[i][0]) -
          pos[i - 1].begin() + pos[i].size();
  int ans = *std::max_element(dp.begin(), dp.end());
  for (int i = 1; i < nn; i++)
    checkmax(ans, dp[i] + static_cast<int>(pos[i + 1].end() -
                                           std::upper_bound(pos[i + 1].begin(),
                                                            pos[i + 1].end(),
                                                            pos[i].back())));
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    checkmax(
        ans,
        static_cast<int>(
            (pos[x].end() - std::lower_bound(pos[x].begin(), pos[x].end(), i) +
             (std::lower_bound(pos[x - 1].begin(), pos[x - 1].end(), i) -
              pos[x - 1].begin()))));
  }
  std::cout << n - ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}