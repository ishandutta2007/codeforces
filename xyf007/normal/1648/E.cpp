#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, bel[200001], fa[200001], d[200001], ans[200001];
struct Edge {
  int u, v, c, id;
} e[200001];
std::vector<int> adj[200001], com[200001];
std::vector<std::pair<int, int>> g2[200001], rt[200001];
int Find(int x) { return x != fa[x] ? fa[x] = Find(fa[x]) : x; }
void Merge(int x, int y, int w) {
  if (com[y].size() > com[x].size()) std::swap(x, y);
  for (const auto &i : com[y]) {
    int f = Find(i);
    for (const auto &[j, c] : rt[x]) d[j] = 0;
    for (const auto &j : adj[i])
      if (bel[j] == x) d[Find(j)]++;
    int sz = 0;
    std::vector<std::pair<int, int>> tmp;
    for (const auto &[j, c] : rt[x])
      if (d[j] != c || j == f) {
        if (j != f) g2[j].emplace_back(f, w), g2[f].emplace_back(j, w);
        fa[j] = f, sz += c;
      } else {
        tmp.emplace_back(j, c);
      }
    tmp.emplace_back(f, sz);
    rt[x].swap(tmp);
  }
  for (const auto &i : com[y])
    bel[i] = x, com[x].emplace_back(i), rt[x].emplace_back(Find(i), 1);
  std::sort(rt[x].begin(), rt[x].end());
  std::vector<std::pair<int, int>> tmp;
  for (std::size_t l = 0, r = 0; l < rt[x].size(); l = r) {
    int sz = 0;
    while (r < rt[x].size() && rt[x][r].first == rt[x][l].first)
      sz += rt[x][r++].second;
    tmp.emplace_back(rt[x][l].first, sz);
  }
  rt[x].swap(tmp);
}
int dep[200001], f[200001][19], g[200001][19];
void Dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  for (const auto &[v, w] : g2[u]) {
    if (v == fa) continue;
    f[v][0] = u, g[v][0] = w;
    Dfs(v, u);
  }
}
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++)
    std::cin >> e[i].u >> e[i].v >> e[i].c, e[i].id = i;
  std::sort(e + 1, e + m + 1,
            [](const Edge &lhs, const Edge &rhs) { return lhs.c < rhs.c; });
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 1; i <= n; i++) com[i] = {i};
  for (int i = 1; i <= n; i++) g2[i].clear();
  for (int i = 1; i <= n; i++) rt[i] = {{i, 1}};
  std::iota(fa + 1, fa + n + 1, 1), std::iota(bel + 1, bel + n + 1, 1);
  for (int i = 1; i <= m; i++)
    adj[e[i].u].emplace_back(e[i].v), adj[e[i].v].emplace_back(e[i].u);
  for (int i = 1; i <= m; i++) {
    int u = bel[e[i].u], v = bel[e[i].v];
    if (u != v) Merge(u, v, e[i].c);
  }
  Dfs(1, 0);
  for (int i = 1; i <= 18; i++)
    for (int j = 1; j <= n; j++) f[j][i] = f[f[j][i - 1]][i - 1];
  for (int i = 1; i <= 18; i++)
    for (int j = 1; j <= n; j++)
      g[j][i] = std::max(g[j][i - 1], g[f[j][i - 1]][i - 1]);
  for (int i = 1; i <= m; i++) {
    int max = 0, u = e[i].u, v = e[i].v;
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int j = 18; j >= 0; j--)
      if (dep[f[u][j]] >= dep[v]) checkmax(max, g[u][j]), u = f[u][j];
    if (u != v) {
      for (int j = 18; j >= 0; j--)
        if (f[u][j] != f[v][j])
          checkmax(max, std::max(g[u][j], g[v][j])), u = f[u][j], v = f[v][j];
      checkmax(max, std::max(g[u][0], g[v][0]));
    }
    ans[e[i].id] = max;
  }
  for (int i = 1; i <= m; i++) std::cout << ans[i] << " \n"[i == m];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) Solve();
  return 0;
}