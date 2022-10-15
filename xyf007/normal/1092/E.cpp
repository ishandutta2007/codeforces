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
int n, m, x, y, dep[1001], a[1001], mid, cen[1001], tot, rt;
std::vector<int> g[1001];
bool vis[1001];
void Dfs1(int u, int fa) {
  vis[u] = true;
  dep[u] = dep[fa] + 1;
  if (!x || dep[u] > dep[x]) x = u;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs1(v, u);
  }
}
void Dfs2(int u, int fa) {
  a[dep[u] = dep[fa] + 1] = u;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs2(v, u);
  }
  if (g[u].size() <= 1 && (!y || dep[u] > dep[y]))
    mid = a[(dep[y = u] + 1) >> 1];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      x = 0;
      Dfs1(i, 0);
      y = 0;
      Dfs2(x, 0);
      cen[++tot] = mid;
      if (!rt || dep[mid] > dep[cen[rt]]) rt = tot;
    }
  std::vector<std::pair<int, int>> ans;
  for (int i = 1; i <= tot; i++)
    if (i != rt) {
      ans.emplace_back(cen[i], cen[rt]);
      g[cen[i]].emplace_back(cen[rt]), g[cen[rt]].emplace_back(cen[i]);
    }
  x = 0;
  Dfs1(1, 0);
  y = 0;
  Dfs2(x, 0);
  std::cout << dep[y] - 1 << '\n';
  for (auto &&[u, v] : ans) std::cout << u << ' ' << v << '\n';
  return 0;
}