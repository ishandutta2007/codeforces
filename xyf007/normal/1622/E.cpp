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
int T, n, m, x[11], c[10001], b[10001], p[10001];
char s[11][10005];
void Work(int S) {
  std::memset(c + 1, 0, 4 * m);
  std::memset(p + 1, 0, 4 * m);
  for (int i = 0; i < n; i++) {
    int t = S >> i & 1 ? 1 : -1;
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '1') c[j] += t;
  }
  std::iota(b + 1, b + m + 1, 1);
  std::sort(b + 1, b + m + 1, [](int x, int y) { return c[x] > c[y]; });
  for (int i = m; i >= 1; i--) p[b[i]] = i;
}
void Solve() {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) std::cin >> x[i];
  for (int i = 0; i < n; i++) std::cin >> (s[i] + 1);
  int ans = 0, sol = 0;
  for (int S = 0; S < (1 << n); S++) {
    Work(S);
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 1; j <= m; j++)
        if (s[i][j] == '1') sum += p[j];
      tmp += std::abs(sum - x[i]);
    }
    if (tmp > ans) ans = tmp, sol = S;
  }
  Work(sol);
  for (int i = 1; i <= m; i++) std::cout << p[i] << " \n"[i == m];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}