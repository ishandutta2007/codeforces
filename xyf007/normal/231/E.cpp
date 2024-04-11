#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kMod = 1e9 + 7;
struct Edge {
  int to, nxt;
} e[200001];
int n, m, q, E, head[100001], dfn[100001], low[100001], tot, col[100001], c,
    s[100001], tp, sz0[100001], dep[100001], fa[100001], sz[100001],
    son[100001], top[100001], a[100001], pw[100001];
std::vector<int> g[100001];
bool vis[100001];
void checkmin(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Tarjan(int u, int f) {
  dfn[u] = low[u] = ++tot;
  s[++tp] = u;
  vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == f) {
      continue;
    }
    if (!dfn[v]) {
      Tarjan(v, u);
      checkmin(low[u], low[v]);
    } else if (vis[v]) {
      checkmin(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    sz0[col[u] = ++c] = 1;
    vis[u] = false;
    while (s[tp] != u) {
      col[s[tp]] = c;
      vis[s[tp--]] = false;
      sz0[c]++;
    }
    tp--;
  }
}
void Dfs(int u, int f) {
  sz[u] = 1;
  fa[u] = f;
  dep[u] = dep[f] + 1;
  a[u] = a[f] + (sz0[u] > 1);
  for (auto &&v : g[u]) {
    if (v == f) {
      continue;
    }
    Dfs(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) {
      son[u] = v;
    }
  }
}
void Dfs2(int u, int t) {
  top[u] = t;
  if (son[u]) {
    Dfs2(son[u], t);
  }
  for (auto &&v : g[u]) {
    if (v == fa[u] || v == son[u]) {
      continue;
    }
    Dfs2(v, v);
  }
}
int GetLca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) {
      std::swap(u, v);
    }
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}
int main(int argc, char const *argv[]) {
  clock_t st = clock();
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n >> m;
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = pw[i - 1] * 2 % kMod;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    Add(u, v);
    Add(v, u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      Tarjan(i, i);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = head[i]; j != -1; j = e[j].nxt) {
      int v = e[j].to;
      if (col[i] == col[v]) {
        continue;
      }
      g[col[i]].emplace_back(col[v]);
    }
  }
  Dfs(1, 0);
  Dfs2(1, 1);
  // if (n > 10000) {
  //   std::cout << static_cast<double>(clock() - st) / CLOCKS_PER_SEC;
  //   return 0;
  // }
  std::cin >> q;
  while (q--) {
    int u, v, lca;
    std::cin >> u >> v;
    u = col[u];
    v = col[v];
    lca = GetLca(u, v);
    std::cout << pw[a[u] + a[v] - a[lca] - a[fa[lca]]] << '\n';
  }
  return 0;
}