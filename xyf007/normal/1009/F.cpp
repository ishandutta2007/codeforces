#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Edge {
  int to, nxt;
} e[2000001];
int n, E, head[1000001], F[1000005], *f[1000001],
    *pf = F, fa[1000001], l[1000001], son[1000001], ans[1000001];
void Add(int f, int t) { e[E] = {t, head[f]}, head[f] = E++; }
void Dfs(int u, int f) {
  l[u] = 1, fa[u] = f;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == f) continue;
    Dfs(v, u), checkmax(l[u], l[v] + 1);
    if (l[v] > l[son[u]]) son[u] = v;
  }
}
void Dfs2(int u) {
  f[u] = pf++;
  if (son[u]) Dfs2(son[u]), ans[u] = ans[son[u]] + 1;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa[u] || v == son[u]) continue;
    Dfs2(v);
    for (int j = 1; j <= l[v]; j++) {
      f[u][j] += f[v][j - 1];
      if (f[u][j] > f[u][ans[u]] || (f[u][j] == f[u][ans[u]] && j < ans[u]))
        ans[u] = j;
    }
  }
  if ((f[u][0] = 1) >= f[u][ans[u]]) ans[u] = 0;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  std::memset(head + 1, -1, 4 * n);
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    Add(u, v), Add(v, u);
  }
  Dfs(1, 0);
  Dfs2(1);
  for (int i = 1; i <= n; i++) std::cout << ans[i] << '\n';
  return 0;
}