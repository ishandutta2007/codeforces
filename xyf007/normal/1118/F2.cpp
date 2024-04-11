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
constexpr int kMod = 998244353;
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, k, c[300001], dep[300001], fa[300001], sz[300001], son[300001],
    top[300001], id[300001], tot, dp[300001][2];
std::vector<int> g[300001], a[300001], g2[300001];
void Dfs(int u, int f) {
  dep[u] = dep[fa[u] = f] + 1, sz[u] = 1;
  for (auto &&v : g[u]) {
    if (v == f) continue;
    Dfs(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void Dfs2(int u, int t) {
  top[u] = t;
  if (son[u]) Dfs2(son[u], t);
  for (auto &&v : g[u]) {
    if (v == fa[u] || v == son[u]) continue;
    Dfs2(v, v);
  }
}
int GetLca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}
void Solve(int u, int f) {
  int t = 1;
  for (auto &&v : g2[u]) {
    if (v == f) continue;
    Solve(v, u);
    Mul(t, add(dp[v][0], dp[v][1]));
  }
  if (u <= tot) {
    dp[u][0] = t;
    for (auto &&v : g2[u]) {
      if (v == f) continue;
      Add(dp[u][1], mul(t, dp[v][1], Ksm(add(dp[v][0], dp[v][1]), kMod - 2)));
    }
  } else {
    dp[u][0] = 0, dp[u][1] = t;
  }
}
std::vector<std::pair<int, int>> e;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> c[i], a[c[i]].emplace_back(i);
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
    e.emplace_back(u, v);
  }
  Dfs(1, 0), Dfs2(1, 1);
  for (int i = 1; i <= k; i++) {
    int lca = a[i][0];
    for (std::size_t j = 1; j < a[i].size(); j++) lca = GetLca(lca, a[i][j]);
    for (auto &&u : a[i]) {
      int now = fa[u];
      while (dep[now] >= dep[lca]) {
        if (c[now] && c[now] != i) {
          std::cout << 0;
          return 0;
        }
        if (c[now] == i) break;
        c[now] = i, now = fa[now];
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (!c[i]) id[i] = ++tot;
  for (int i = 1; i <= n; i++)
    if (c[i]) id[i] = tot + c[i];
  for (auto &&[u, v] : e)
    if (id[u] != id[v])
      g2[id[u]].emplace_back(id[v]), g2[id[v]].emplace_back(id[u]);
  Solve(1, 0);
  std::cout << dp[1][1];
  return 0;
}