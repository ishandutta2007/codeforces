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
int n, v, m, sum[100001];
std::vector<std::pair<int, int>> a[3];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> v;
  for (int i = 1; i <= n; i++) {
    int c, w;
    std::cin >> c >> w;
    a[c].emplace_back(w, i);
  }
  m = a[1].size();
  std::sort(a[1].begin(), a[1].end(), std::greater<std::pair<int, int>>());
  std::sort(a[2].begin(), a[2].end(), std::greater<std::pair<int, int>>());
  for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + a[1][i - 1].first;
  int ans = sum[std::min(m, v)], s = 0, p = 0;
  for (int i = 0; i < static_cast<int>(a[2].size()) && 2 * i + 2 <= v; i++) {
    s += a[2][i].first;
    if (int ns = s + sum[std::min(m, v - 2 * i - 2)]; ns > ans) {
      ans = ns;
      p = i + 1;
    }
  }
  std::cout << ans << '\n';
  for (int i = 0; i < std::min(m, v - 2 * p); i++)
    std::cout << a[1][i].second << ' ';
  for (int i = 0; i < p; i++) std::cout << a[2][i].second << ' ';
  return 0;
}