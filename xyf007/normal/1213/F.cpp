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
int n, k, p[200001], q[200001], dfn[200001], low[200001], tot, s[200001], top,
    col[200001], c, ind[200001], ans[200001], ccc;
std::vector<int> g[200001], g2[200001];
bool vis[200001];
void Tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  s[++top] = u, vis[u] = true;
  for (auto &&v : g[u])
    if (!dfn[v])
      Tarjan(v), checkmin(low[u], low[v]);
    else if (vis[v])
      checkmin(low[u], dfn[v]);
  if (low[u] == dfn[u]) {
    c++;
    while (s[top] != u) col[s[top]] = c, vis[s[top--]] = false;
    top--, col[u] = c, vis[u] = false;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> p[i];
  for (int i = 1; i <= n; i++) std::cin >> q[i];
  for (int i = 1; i < n; i++) g[p[i]].emplace_back(p[i + 1]);
  for (int i = 1; i < n; i++) g[q[i]].emplace_back(q[i + 1]);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) Tarjan(i);
  for (int u = 1; u <= n; u++)
    for (auto &&v : g[u])
      if (col[u] != col[v]) g2[col[u]].emplace_back(col[v]), ind[col[v]]++;
  std::queue<int> q;
  for (int i = 1; i <= c; i++)
    if (!ind[i]) q.emplace(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans[u] = ++ccc;
    for (auto &&v : g2[u])
      if (!--ind[v]) q.emplace(v);
  }
  if (ccc < k) {
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES\n";
  for (int i = 1; i <= n; i++)
    std::cout << static_cast<char>(std::min(ans[col[i]], 26) - 1 + 'a');
  return 0;
}