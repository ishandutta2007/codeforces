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
int n, q, s[300005], a[300005], tot, stk[300005], top, nxt[300005], rev[300005];
long long v[300005];
char ss[300005];
std::vector<int> p[300005];
std::vector<long long> sum[300005];
inline long long Ask(int l, int r, int k) {
  return sum[k][r] - (l ? sum[k][l - 1] : 0LL);
}
long long Solve(int l, int r, int k) {
  int pl = rev[l], pr = rev[r] - 1;
  long long len = pr - pl + 1;
  return Ask(pl, pr, k) + len * (len - 1) / 2;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q >> (ss + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (ss[i] == '(' ? 1 : -1);
  std::memcpy(a + 1, s, 4 * (n + 1)), tot = n + 1;
  std::sort(a + 1, a + tot + 1);
  tot = std::unique(a + 1, a + tot + 1) - a - 1;
  for (int i = 0; i <= n; i++)
    p[std::lower_bound(a + 1, a + tot + 1, s[i]) - a].push_back(i);
  for (int i = 0; i <= n; i++) {
    while (top && s[i] < s[stk[top]]) nxt[stk[top--]] = i;
    stk[++top] = i;
  }
  while (top) nxt[stk[top--]] = n + 1;
  for (int i = 1; i <= tot; i++)
    for (std::size_t j = 0; j < p[i].size(); j++) rev[p[i][j]] = j;
  for (int i = tot; i >= 1; i--) {
    for (std::size_t j = 0; j + 1 < p[i].size(); j++) {
      int x = p[i][j], y = p[i][j + 1];
      if (nxt[x] <= y) continue;
      if (y == x + 2)
        v[x] = 1LL;
      else
        v[x] = Solve(x + 1, y - 1, i + 1) + 1;
    }
    sum[i].resize(p[i].size());
    sum[i][0] = v[p[i][0]];
    for (std::size_t j = 1; j < p[i].size(); j++)
      sum[i][j] = sum[i][j - 1] + v[p[i][j]];
  }
  while (q--) {
    int l, r;
    std::cin >> l >> l >> r, l--;
    int k = std::lower_bound(a + 1, a + tot + 1, s[r]) - a;
    std::cout << Solve(l, r, k) << '\n';
  }
  return 0;
}