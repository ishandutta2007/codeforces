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
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n;
long long m, a[200001], b[200001], l[200001], r[200001];
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i] >> b[i];
  for (int i = 1; i <= n; i++)
    l[i] = std::max(0LL, a[i] - m), r[i] = a[i] - std::max(m - b[i], 0LL);
  long long rem = std::accumulate(a + 1, a + n + 1, 0LL) +
                  std::accumulate(b + 1, b + n + 1, 0LL) - n * m,
            aim = rem >> 1;
  aim -= std::accumulate(l + 1, l + n + 1, 0LL);
  if (aim > 0) {
    for (int i = 1; i <= n; i++)
      if (aim > r[i] - l[i]) {
        aim -= r[i] - std::exchange(l[i], r[i]);
      } else {
        l[i] += aim;
        break;
      }
  }
  long long sa = std::accumulate(l + 1, l + n + 1, 0LL), sb = rem - sa;
  std::cout << std::abs(sa - sb) << '\n';
  for (int i = 1; i <= n; i++)
    std::cout << a[i] - l[i] << ' ' << m - (a[i] - l[i]) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}