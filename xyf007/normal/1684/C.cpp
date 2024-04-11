#include <iterator>
#include <utility>
#include <vector>
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
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
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
int T, n, m;
void Solve() {
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) std::cin >> a[i][j];
  std::vector<std::vector<int>> b = a;
  for (int i = 1; i <= n; i++) std::sort(b[i].begin(), b[i].end());
  std::pair<int, int> sol;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= m; j++) cnt += a[i][j] != b[i][j];
    if (cnt > 2) {
      std::cout << "-1\n";
      return;
    }
    if (cnt == 2) {
      int x = 0, y = 0;
      for (int j = 1; j <= m; j++)
        if (a[i][j] != b[i][j]) (x ? y : x) = j;
      if (sol.first && (sol.first != x || sol.second != y)) {
        std::cout << "-1\n";
        return;
      }
      sol = {x, y};
    }
  }
  auto [x, y] = sol;
  if (!x) {
    std::cout << "1 1\n";
    return;
  }
  for (int i = 1; i <= n; i++) std::swap(a[i][x], a[i][y]);
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= m; j++)
      if (a[i][j] < a[i][j - 1]) {
        std::cout << "-1\n";
        return;
      }
  std::cout << x << ' ' << y << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}