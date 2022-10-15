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
int T, n, m, dp[4000001], to[4000001];
char vis[4000001], s[2005][2005];
auto in = [](int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; };
void Dfs(int u) {
  if (vis[u] == 2) return;
  if (vis[u] == 1) {
    int c = 1;
    for (int i = to[u]; i != u; i = to[i]) c++;
    dp[u] = c;
    for (int i = to[u]; i != u; i = to[i]) dp[i] = c;
    vis[u] = 2;
    return;
  }
  vis[u] = 1;
  if (to[u]) Dfs(to[u]);
  vis[u] = 2;
}
int Dfs2(int u) {
  if (u == 0) return 0;
  if (dp[u]) return dp[u];
  return dp[u] = Dfs2(to[u]) + 1;
}
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  auto id = [](int x, int y) { return (x - 1) * m + y; };
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x = i, y = j;
      if (s[i][j] == 'L') x = i, y = j - 1;
      if (s[i][j] == 'R') x = i, y = j + 1;
      if (s[i][j] == 'U') x = i - 1, y = j;
      if (s[i][j] == 'D') x = i + 1, y = j;
      int u = id(i, j), v = in(x, y) ? id(x, y) : 0;
      to[u] = v;
    }
  std::memset(dp + 1, 0, 4 * n * m);
  std::memset(vis + 1, 0, n * m);
  int ans = 0, px = 0, py = 0;
  for (int i = 1; i <= n * m; i++)
    if (vis[i] == 0) Dfs(i);
  for (int i = 1; i <= n * m; i++)
    if (Dfs2(i) > ans) ans = dp[i], px = (i - 1) / m + 1, py = (i - 1) % m + 1;
  std::cout << px << ' ' << py << ' ' << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}