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
int T, n, x, a[5001], ans[5001];
void Solve() {
  std::cin >> n >> x;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::partial_sum(a + 1, a + n + 1, a + 1);
  std::fill(ans, ans + n + 1, 0);
  for (int len = 1; len <= n; len++) {
    int max = 0xc0c0c0c0;
    for (int i = len; i <= n; i++) checkmax(max, a[i] - a[i - len]);
    for (int i = 0; i <= len; i++) checkmax(ans[i], max + i * x);
    checkmax(ans[len], ans[len - 1]);
  }
  for (int i = 0; i <= n; i++) std::cout << ans[i] << " \n"[i == n];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}