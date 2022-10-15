// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
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
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n, fa[101], dis[101][101];
char s[101][101][105];
int vis[101];
std::vector<std::vector<int>> g;
void Dfs(int u, int fa, int rt) {
  for (const auto v : g[u]) {
    if (v == fa) continue;
    dis[rt][v] = dis[rt][u] + 1;
    Dfs(v, u, rt);
  }
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      std::cin >> (s[i][j] + 1);
      std::copy(s[i][j] + 1, s[i][j] + n + 1, s[j][i] + 1);
    }
  for (int x = 2; x <= n; x++) {
    std::vector<std::vector<int>> ee(n + 1), d(n + 1);
    std::fill(vis + 1, vis + n + 1, 0);
    std::fill(fa + 1, fa + n + 1, 0);
    bool ok = true;
    d[1].emplace_back(1), vis[1] = 1;
    ee[1].emplace_back(x), ee[x].emplace_back(1);
    d[2].emplace_back(x), vis[x] = 2, fa[x] = 1;
    for (int i = 2; i <= n; i++) {
      if (i == x) continue;
      if (s[x][i][1] == '1') {
        ee[1].emplace_back(i), ee[i].emplace_back(1);
        d[2].emplace_back(i), vis[i] = 2, fa[i] = 1;
      }
    }
    int cur = 2;
    while (std::any_of(vis + 1, vis + n + 1, [](int x) { return !x; }) &&
           !d[cur].empty()) {
      for (const auto y : d[cur]) {
        for (int i = 2; i <= n; i++) {
          if (vis[i] && vis[i] <= cur) continue;
          if (s[fa[y]][i][y] == '1') {
            if (vis[i] == cur + 1) {
              ok = false;
              goto ed;
            }
            ee[y].emplace_back(i), ee[i].emplace_back(y);
            d[cur + 1].emplace_back(i), fa[i] = y, vis[i] = cur + 1;
          }
        }
      }
      cur++;
    }
    if (d[cur].empty()) continue;
  ed:;
    if (!ok) continue;
    g = ee;
    for (int i = 1; i <= n; i++) std::fill(dis[i] + 1, dis[i] + n + 1, 0);
    for (int i = 1; i <= n; i++) Dfs(i, 0, i);
    for (int i = 1; i < n; i++)
      for (int j = i + 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          if ((dis[i][k] == dis[j][k]) != (s[i][j][k] == '1')) ok = false;
    if (!ok) continue;
    std::cout << "Yes\n";
    for (int i = 1; i <= n; i++)
      for (const auto u : g[i])
        if (u > i) std::cout << i << ' ' << u << '\n';
    return;
  }
  std::cout << "No\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}