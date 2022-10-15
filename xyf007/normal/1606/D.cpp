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
int T, n, m;
void Solve() {
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) std::cin >> a[i][j];
  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(),
            [&a](int x, int y) { return a[x][0] < a[y][0]; });
  std::vector<std::vector<int>> premax(n, std::vector<int>(m + 1, 0)),
      premin(n, std::vector<int>(m + 1, 0x3f3f3f3f)),
      sufmax(n, std::vector<int>(m + 1, 0)),
      sufmin(n, std::vector<int>(m + 1, 0x3f3f3f3f));
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= m; j++) {
      premax[i][j] = std::max(premax[i][j - 1], a[p[i]][j - 1]);
      premin[i][j] = std::min(premin[i][j - 1], a[p[i]][j - 1]);
    }
  for (int i = 0; i < n; i++)
    for (int j = m - 1; j >= 0; j--) {
      sufmax[i][j] = std::max(sufmax[i][j + 1], a[p[i]][j]);
      sufmin[i][j] = std::min(sufmin[i][j + 1], a[p[i]][j]);
    }
  int ansx = -1, ansy;
  for (int j = 1; j < m; ++j) {
    std::vector<int> pmx(n + 1, 0), pmn(n + 1, 0x3f3f3f3f), smx(n + 1, 0),
        smn(n + 1, 0x3f3f3f3f);
    for (int i = 0; i < n; ++i) {
      pmx[i + 1] = std::max(pmx[i], premax[i][j]);
      pmn[i + 1] = std::min(pmn[i], sufmin[i][j]);
    }
    for (int i = n - 1; ~i; --i) {
      smn[i] = std::min(smn[i + 1], premin[i][j]);
      smx[i] = std::max(smx[i + 1], sufmax[i][j]);
    }
    for (int i = 1; i < n; ++i)
      if (pmx[i] < smn[i] && pmn[i] > smx[i]) {
        ansx = i, ansy = j;
        break;
      }
    if (ansx != -1) break;
  }
  if (ansx != -1) {
    std::cout << "YES\n";
    std::string ans(n, ' ');
    for (int i = 0; i < n; ++i) {
      if (i < ansx)
        ans[p[i]] = 'B';
      else
        ans[p[i]] = 'R';
    }
    std::cout << ans << ' ' << ansy << '\n';
  } else {
    std::cout << "NO\n";
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}