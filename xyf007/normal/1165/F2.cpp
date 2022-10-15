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
int n, m, a[200001], c[200001];
std::vector<int> d[200001];
bool Check(int x) {
  std::memcpy(c + 1, a + 1, 4 * n);
  std::vector<std::pair<int, int>> b;
  for (int i = 1; i <= n; i++) {
    auto it = std::upper_bound(d[i].begin(), d[i].end(), x);
    if (it != d[i].begin()) b.emplace_back(*--it, i);
  }
  std::sort(b.begin(), b.end());
  int pre = 0, rem = 0;
  for (auto &&[t, i] : b) {
    rem += t - pre, pre = t;
    int cnt = std::min(c[i], rem);
    rem -= cnt, c[i] -= cnt;
  }
  rem += x - pre;
  return 2 * std::accumulate(c + 1, c + n + 1, 0) <= rem;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int x, t;
    std::cin >> t >> x;
    d[x].emplace_back(t);
  }
  for (int i = 1; i <= n; i++) std::sort(d[i].begin(), d[i].end());
  int l = 0, r = 400000, best = r;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (Check(mid))
      best = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  std::cout << best;
  return 0;
}