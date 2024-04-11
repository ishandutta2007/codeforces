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
struct Node {
  int a, b, m, c, l, r, f, id;
} a[200001];
int T, n;
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i].a >> a[i].b >> a[i].m;
  for (int i = 1; i <= n; i++) {
    a[i].l = std::max(a[i].a - a[i].m, 0);
    a[i].r = a[i].a - std::max(a[i].m - a[i].b, 0);
    a[i].c = a[i].a + a[i].b - a[i].m;
    a[i].id = i;
  }
  std::sort(a + 1, a + n + 1, [](const Node &lhs, const Node &rhs) {
    return lhs.c == rhs.c ? lhs.l < rhs.l : lhs.c < rhs.c;
  });
  int ans = n;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    while (r < n && a[r + 1].c == a[l].c) r++;
    int p = a[l].r, cnt = 1, pre = l;
    for (int i = l + 1; i <= r; i++) {
      if (a[i].l <= p)
        checkmin(p, a[i].r);
      else {
        for (int j = pre; j < i; j++) a[j].f = a[j].a - p;
        cnt++, p = a[i].r, pre = i;
      }
    }
    for (int i = pre; i <= r; i++) a[i].f = a[i].a - p;
    ans -= (r - l + 1) - cnt;
  }
  std::cout << ans << '\n';
  std::sort(a + 1, a + n + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.id < rhs.id; });
  for (int i = 1; i <= n; i++)
    std::cout << a[i].f << ' ' << a[i].m - a[i].f << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}