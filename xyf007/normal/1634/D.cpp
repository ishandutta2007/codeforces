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
int T, n;
bool vis[1001];
int Ask(int a, int b, int c) {
  std::cout << "? " << a << ' ' << b << ' ' << c << std::endl;
  int x;
  std::cin >> x;
  return x;
}
std::pair<int, int> Solve(const std::array<int, 4> &a) {
  int b[4] = {Ask(a[1], a[2], a[3]), Ask(a[0], a[2], a[3]),
              Ask(a[0], a[1], a[3]), Ask(a[0], a[1], a[2])},
      c[4] = {0, 1, 2, 3};
  std::sort(c, c + 4, [&](int x, int y) { return b[x] < b[y]; });
  return {a[c[0]], a[c[1]]};
}
void Solve() {
  std::cin >> n;
  std::pair<int, int> res(1, 2);
  for (int i = 3; i + 1 <= n; i += 2)
    res = Solve({res.first, res.second, i, i + 1});
  if (n & 1) {
    for (int i = 1; i <= n; i++)
      if (i != res.first && i != res.second) {
        res = Solve({res.first, res.second, n, i});
        break;
      }
  }
  std::cout << "! " << res.first << ' ' << res.second << std::endl;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}