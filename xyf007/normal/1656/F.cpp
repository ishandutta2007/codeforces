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
  if (x < 0) out << '-', x = -x;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n;
__int128_t a[200005], s[200005];
constexpr __int128_t operator""_LLL(unsigned long long x) { return x; }
void Solve() {
  std::cin >> n;
  int x;
  for (int i = 1; i <= n; i++) std::cin >> x, a[i] = x;
  a[0] = -1e18, a[n + 1] = 1e18;
  std::sort(a + 1, a + n + 1);
  std::partial_sum(a + 1, a + n + 1, s + 1);
  __int128_t sum = 0;
  for (int i = 2; i <= n; i++) sum += a[1] + a[i];
  if (sum > 0) {
    std::cout << "INF\n";
    return;
  }
  sum = 0;
  for (int i = 1; i < n; i++) sum += a[i] + a[n];
  if (sum < 0) {
    std::cout << "INF\n";
    return;
  }
  __int128_t ans = -1_LLL << 120;
  for (int i = 0; i <= n; i++) {
    __int128_t L = -a[i + 1], R = -a[i],
               bs = s[i] * a[n] + (s[n] - s[i]) * a[1],
               coef = i * a[n] + s[i] + (n - i) * a[1] + s[n] - s[i];
    if (i == 0)
      coef -= 2 * a[1];
    else if (i == n)
      coef -= 2 * a[n];
    else
      coef -= a[1] + a[n];
    if (i == 0)
      bs -= a[1] * a[1];
    else if (i == n)
      bs -= a[n] * a[n];
    else
      bs -= a[1] * a[n];
    checkmax(ans, coef * L + bs), checkmax(ans, coef * R + bs);
  }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}