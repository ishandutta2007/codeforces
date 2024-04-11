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
int T, n, m, min[200005];
long long a[200001], sum[200001];
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::partial_sum(a + 1, a + n + 1, sum + 1);
  std::vector<std::pair<long long, int>> v;
  for (int i = 1; i <= n; i++) v.emplace_back(sum[i], i);
  std::sort(v.begin(), v.end());
  min[n] = 0x3f3f3f3f;
  for (int i = n - 1; i >= 0; i--) min[i] = std::min(min[i + 1], v[i].second);
  for (int i = 1; i <= m; i++) {
    long long x;
    std::cin >> x;
    auto it = std::lower_bound(v.begin(), v.end(), std::make_pair(x, 0));
    if (it != v.end()) {
      std::ptrdiff_t p = it - v.begin();
      std::cout << min[p] - 1 << " \n"[i == m];
      continue;
    }
    if (sum[n] <= 0) {
      std::cout << -1 << " \n"[i == m];
      continue;
    }
    long long rnd = (x - v.back().first - 1) / sum[n] + 1, cc = rnd * n;
    x -= sum[n] * rnd;
    it = std::lower_bound(v.begin(), v.end(), std::make_pair(x, 0));
    std::ptrdiff_t p = it - v.begin();
    std::cout << cc + min[p] - 1 << " \n"[i == m];
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}