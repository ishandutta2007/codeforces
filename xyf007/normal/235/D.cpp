#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
struct Edge {
  int u, v;
} e[3001];
int n, col[3001], dep[3001], fa[3001][13], lg[3001];
std::vector<int> g[3001], cur, cyc;
bool vis[3001], in_cyc[3001];
bool Dfs(int u, int fe) {
  if (vis[u]) {
    while (!cur.empty() && cur.back() != u)
      cyc.emplace_back(cur.back()), cur.pop_back();
    cyc.emplace_back(u);
    return true;
  }
  cur.emplace_back(u), vis[u] = true;
  for (const auto eid : g[u]) {
    if (eid == fe) continue;
    int v = u ^ e[eid].u ^ e[eid].v;
    if (Dfs(v, eid)) return true;;
  }
  cur.pop_back();
  return false;
}
void Dfs2(int u, int fe, int c) {
  col[u] = c;
  for (const auto eid : g[u]) {
    if (eid == fe) continue;
    int v = u ^ e[eid].u ^ e[eid].v;
    if (!in_cyc[v]) dep[v] = dep[u] + 1, fa[v][0] = u, Dfs2(v, eid, c);
  }
}
int GetLca(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  while (dep[u] > dep[v]) u = fa[u][lg[dep[u] - dep[v]]];
  if (u == v) return u;
  for (int i = lg[dep[u]]; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, v;
    std::cin >> u >> v, u++, v++;
    e[i] = {u, v};
    g[u].emplace_back(i), g[v].emplace_back(i);
  }
  Dfs(1, 0);
  for (const auto i : cyc) in_cyc[i] = true;
  for (std::size_t i = 0; i < cyc.size(); i++) Dfs2(cyc[i], 0, i);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= lg[n]; i++)
    for (int j = 1; j <= n; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  double ans = 0.0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (col[i] == col[j]) {
        int lca = GetLca(i, j), l = dep[i] + dep[j] - 2 * dep[lca] + 1;
        ans += 1.0 / l;
      } else {
        int x = dep[i] + dep[j] + 2, y = std::abs(col[i] - col[j]) - 1,
            z = cyc.size() - y - 2;
        ans += 1.0 / (x + y) + 1.0 / (x + z) - 1.0 / (x + y + z);
      }
  std::cout << std::setprecision(8) << std::fixed << ans;
  return 0;
}