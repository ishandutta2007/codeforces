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
struct Edge {
  int to, nxt;
} e[20001];
int n, m, E, head[10001], dep[10001], fae[10001], a[10001], b[10001], c1, c2;
bool vis[10001];
void Add(int f, int t) {
  e[E] = {t, head[f]};
  head[f] = E++;
}
void Dfs(int u, int fe) {
  vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    if (i == (fe ^ 1)) continue;
    int v = e[i].to;
    if (!vis[v]) {
      dep[v] = dep[u] + 1, fae[v] = i, Dfs(v, i);
    } else if (dep[v] < dep[u]) {
      if ((dep[u] - dep[v]) & 1)
        c2++, b[u]++, b[v]--;
      else
        c1++, a[u]++, a[v]--;
    }
  }
}
std::vector<int> ans;
void Dfs(int u) {
  vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    if (i == (fae[u] ^ 1)) continue;
    int v = e[i].to;
    if (vis[v]) {
      if (c1 == 1 && dep[v] < dep[u] && !((dep[u] - dep[v]) & 1))
        ans.emplace_back((i >> 1) + 1);
      continue;
    }
    Dfs(v), a[u] += a[v], b[u] += b[v];
  }
  if (a[u] == c1 && !b[u]) ans.emplace_back((fae[u] >> 1) + 1);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  std::memset(head + 1, -1, 4 * n), std::memset(fae + 1, -1, 4 * n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    Add(u, v), Add(v, u);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) Dfs(i, -1);
  if (!c1) {
    std::cout << m << '\n';
    for (int i = 1; i <= m; i++) std::cout << i << ' ';
    return 0;
  }
  std::memset(vis + 1, 0, n);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) Dfs(i);
  std::sort(ans.begin(), ans.end());
  std::cout << ans.size() << '\n';
  for (auto &&x : ans) std::cout << x << ' ';
  return 0;
}