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
int n, m, s, dfn[5001], low[5001], tot, st[5001], top, col[5001], c, ind[5001];
bool vis[5001];
std::vector<int> g[5001];
std::unordered_set<int> g2[5001];
void Tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  st[++top] = u, vis[u] = true;
  for (auto &&v : g[u])
    if (!dfn[v])
      Tarjan(v), checkmin(low[u], low[v]);
    else if (vis[v])
      checkmin(low[u], dfn[v]);
  if (low[u] == dfn[u]) {
    c++;
    while (st[top] != u) col[st[top]] = c, vis[st[top--]] = false;
    top--, col[u] = c, vis[u] = false;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) Tarjan(i);
  for (int u = 1; u <= n; u++)
    for (auto &&v : g[u])
      if (col[u] != col[v] && !g2[col[u]].count(col[v]))
        g2[col[u]].emplace(col[v]), ind[col[v]]++;
  int ans = 0;
  for (int i = 1; i <= c; i++) ans += !ind[i];
  ans -= !ind[col[s]];
  std::cout << ans;
  return 0;
}