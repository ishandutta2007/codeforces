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
int T, n, m, tot;
long long a[200001], dp[200001][2];
std::pair<long long, long long> b[200001];
std::vector<std::pair<long long, long long>> c[200001];
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    int pos = std::lower_bound(a + 1, a + n + 1, l) - a;
    if (pos <= n && a[pos] <= r) continue;
    b[++tot] = {l, r};
  }
  std::sort(b + 1, b + tot + 1);
  m = 0;
  for (int i = 1; i <= tot; i++) {
    while (m && b[i].second <= b[m].second) m--;
    b[++m] = b[i];
  }
  for (int i = 1; i <= m; i++) {
    int pos = std::lower_bound(a + 1, a + n + 1, b[i].first) - a;
    c[pos - 1].emplace_back(b[i]);
  }
  std::memset(dp, 0x3f, sizeof(dp));
  long long max = c[0].empty() ? 0LL : a[1] - c[0].front().second;
  dp[0][0] = max, dp[0][1] = 2 * max;
  for (int i = 1; i < n; i++) {
    if (c[i].empty()) {
      dp[i][0] = dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]);
      continue;
    }
    long long dl = 0LL, dr = a[i + 1] - c[i].front().second;
    checkmin(dp[i][0], std::min(dp[i - 1][0], dp[i - 1][1]) + dr);
    checkmin(dp[i][1], std::min(dp[i - 1][0], dp[i - 1][1]) + 2 * dr);
    for (std::size_t j = 0; j < c[i].size(); j++) {
      dl = c[i][j].first - a[i];
      dr = j + 1 < c[i].size() ? a[i + 1] - c[i][j + 1].second : 0LL;
      checkmin(dp[i][0], dp[i - 1][0] + 2 * dl + dr);
      checkmin(dp[i][0], dp[i - 1][1] + dl + dr);
      checkmin(dp[i][1], dp[i - 1][0] + 2 * dl + 2 * dr);
      checkmin(dp[i][1], dp[i - 1][1] + dl + 2 * dr);
    }
  }
  max = c[n].empty() ? 0LL : c[n].back().first - a[n];
  std::cout << std::min(dp[n - 1][0] + 2 * max, dp[n - 1][1] + max) << '\n';
  tot = 0;
  for (int i = 0; i <= n; i++) c[i].clear();
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}