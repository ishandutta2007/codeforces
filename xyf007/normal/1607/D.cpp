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
int T, n, a[200005];
char col[200005];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::cin >> (col + 1);
  std::vector<int> blu, re;
  for (int i = 1; i <= n; i++)
    if (col[i] == 'B')
      blu.push_back(a[i]);
    else
      re.push_back(a[i]);
  std::sort(blu.begin(), blu.end());
  std::sort(re.begin(), re.end(), std::greater<int>());
  int c1 = blu.size(), c2 = n - c1;
  for (int i = 1; i <= c1; i++)
    if (blu[i - 1] < i) {
      std::cout << "NO\n";
      return;
    }
  for (int i = 0; i < c2; i++)
    if (re[i] > n - i) {
      std::cout << "NO\n";
      return;
    }
  std::cout << "YES\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}