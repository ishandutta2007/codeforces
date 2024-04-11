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
int n, q, max[19][200001], lg[200001];
std::vector<std::pair<int, int>> a[200001];
std::pair<int, int> b[200001];
int Query(int l, int r) {
  int len = lg[r - l + 1];
  return std::max(max[len][l], max[len][r - (1 << len) + 1]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    a[x].emplace_back(i, y);
    b[i] = {x, y};
  }
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++) max[0][i] = a[i].empty() ? 0 : a[i].back().first;
  for (int j = 1; j <= lg[n]; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      max[j][i] = std::max(max[j - 1][i], max[j - 1][i + (1 << (j - 1))]);
  std::cin >> q;
  while (q--) {
    int m;
    std::set<int> s;
    s.emplace(0), s.emplace(n + 1);
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
      int x;
      std::cin >> x, s.emplace(x);
    }
    int lst = 0, x = 0;
    for (auto it = s.begin(), nx = ++s.begin(); nx != s.end(); ++it, ++nx) {
      int l = *it + 1, r = *nx - 1;
      if (l <= r) checkmax(lst, Query(l, r));
    }
    if (!lst) {
      std::cout << "0 0\n";
      continue;
    }
    x = b[lst].first, s.emplace(x);
    lst = 0;
    for (auto it = s.begin(), nx = ++s.begin(); nx != s.end(); ++it, ++nx) {
      int l = *it + 1, r = *nx - 1;
      if (l <= r) checkmax(lst, Query(l, r));
    }
    std::cout << x << ' '
              << std::lower_bound(a[x].begin(), a[x].end(),
                                  std::make_pair(lst, 0))
                     ->second
              << '\n';
  }
  return 0;
}