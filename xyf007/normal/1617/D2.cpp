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
    out << ' ' << *it;
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
int Query(int x, int y, int z) {
  std::cout << "? " << x << ' ' << y << ' ' << z << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}
void Solve() {
  std::cin >> n;
  std::vector<int> c(n + 1, -1), a(n + 1, -1);
  for (int i = 1; i <= n; i += 3) a[i] = Query(i, i + 1, i + 2);
  int v[2] = {-1, -1};
  for (int i = 1; i + 3 <= n; i += 3)
    if (a[i] != a[i + 3]) {
      a[i + 1] = Query(i + 1, i + 2, i + 3);
      a[i + 2] = Query(i + 2, i + 3, i + 4);
      for (int j = i; j < i + 3; j++)
        if (a[j] != a[j + 1]) {
          v[a[j]] = j, v[a[j + 1]] = j + 3;
          c[j] = a[j], c[j + 3] = a[j + 1];
        }
      break;
    }
  for (int i = 1; i <= n; i += 3) {
    if (i == v[0] || i + 1 == v[0] || i + 2 == v[0] || i == v[1] ||
        i + 1 == v[1] || i + 2 == v[1]) {
      for (int j = i; j < i + 3; j++)
        if (c[j] == -1) c[j] = Query(v[0], v[1], j);
    } else {
      if (Query(v[a[i] ^ 1], i, i + 1) != a[i]) {
        c[i] = Query(v[0], v[1], i), c[i + 1] = c[i] ^ 1, c[i + 2] = a[i];
      } else {
        c[i] = c[i + 1] = a[i], c[i + 2] = Query(v[0], v[1], i + 2);
      }
    }
  }
  std::vector<int> ans(n + 1);
  std::iota(ans.begin(), ans.end(), 0);
  ans.erase(
      std::remove_if(ans.begin(), ans.end(), [&c](int x) { return c[x]; }),
      ans.end());
  std::cout << "! " << ans.size() << ans << std::endl;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}