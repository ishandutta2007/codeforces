#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
template <class T, typename = decltype(std::declval<T>().begin()),
          typename = decltype(std::declval<T>().end()),
          typename = typename std::enable_if<!std::is_base_of<
              std::string, typename std::decay<T>::type>::value>::type,
          typename value_type = typename T::value_type>
std::ostream &operator<<(std::ostream &out, const T &container) {
  for (auto it = container.begin(); it != container.end(); ++it)
    out << *it << ' ';
  return out;
}
std::ostream &operator<<(std::ostream &out, __int128_t x) {
  if (!x) return out << 0;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n, m, d[300001], tot;
long long a[300001];
void Solve() {
  std::cin >> n >> m;
  std::map<int, int> c;
  for (int i = 1; i <= n; i++) std::cin >> a[i], c[a[i]]++;
  std::set<std::pair<long long, int>> bl;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    bl.emplace(x, y);
  }
  std::vector<std::vector<long long>> b(n + 1);
  for (const auto &[x, cnt] : c) b[cnt].push_back(x);
  tot = 0;
  for (int i = 1; i <= n; i++)
    if (!b[i].empty()) {
      d[++tot] = i;
      std::sort(b[i].begin(), b[i].end(), std::greater());
    }
  std::priority_queue<std::tuple<long long, std::pair<int, int>, int, int>> q;
  std::set<std::tuple<std::pair<int, int>, int, int>> vis;
  for (int i = 1; i <= tot; i++) {
    if (b[i].size() >= 2) {
      long long x = b[d[i]][0], y = b[d[i]][1];
      q.emplace((d[i] + d[i]) * (x + y), std::make_pair(i, i), 0, 1);
    }
    for (int j = i + 1; j <= tot; j++) {
      long long x = b[d[i]][0], y = b[d[j]][0];
      q.emplace((d[i] + d[j]) * (x + y), std::make_pair(i, j), 0, 0);
    }
  }
  while (true) {
    auto [val, pos, p1, p2] = q.top();
    q.pop();
    auto [i, j] = pos;
    long long x = b[d[i]][p1], y = b[d[j]][p2];
    if (!bl.count({x, y}) && !bl.count({y, x})) {
      std::cout << val << '\n';
      return;
    }
    if (i == j) {
      if (p1 + 1 != p2) {
        if (!vis.count({{i, i}, p1 + 1, p2})) {
          x = b[d[i]][p1 + 1], y = b[d[i]][p2];
          q.emplace((d[i] + d[j]) * (x + y), std::make_pair(i, i), p1 + 1, p2);
          vis.emplace(std::make_pair(i, i), p1 + 1, p2);
        }
      }
      if (p2 + 1 < static_cast<int>(b[d[i]].size())) {
        if (!vis.count({{i, i}, p1, p2 + 1})) {
          x = b[d[i]][p1], y = b[d[i]][p2 + 1];
          q.emplace((d[i] + d[j]) * (x + y), std::make_pair(i, i), p1, p2 + 1);
          vis.emplace(std::make_pair(i, i), p1, p2 + 1);
        }
      }
    } else {
      if (p1 + 1 < static_cast<int>(b[d[i]].size())) {
        if (!vis.count({{i, j}, p1 + 1, p2})) {
          x = b[d[i]][p1 + 1], y = b[d[j]][p2];
          q.emplace((d[i] + d[j]) * (x + y), std::make_pair(i, j), p1 + 1, p2);
          vis.emplace(std::make_pair(i, j), p1 + 1, p2);
        }
      }
      if (p2 + 1 < static_cast<int>(b[d[j]].size())) {
        if (!vis.count({{i, j}, p1, p2 + 1})) {
          x = b[d[i]][p1], y = b[d[j]][p2 + 1];
          q.emplace((d[i] + d[j]) * (x + y), std::make_pair(i, j), p1, p2 + 1);
          vis.emplace(std::make_pair(i, j), p1, p2 + 1);
        }
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}