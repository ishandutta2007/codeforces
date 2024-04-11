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
} e[10001];
int n, m, E, head[5001], fa[5001], fe[5001], dep[5001], ans[5001];
std::tuple<int, int, int> b[5001];
void Add(int f, int t) {
  e[E] = {t, head[f]};
  head[f] = E++;
}
void Dfs(int u, int f) {
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == f) continue;
    fa[v] = u, dep[v] = dep[u] + 1, fe[v] = i >> 1, Dfs(v, u);
  }
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
  std::cin >> m;
  auto cov = [](int u, int v, int w) {
    if (dep[u] < dep[v]) std::swap(u, v);
    while (dep[u] > dep[v]) ans[fe[u]] = w, u = fa[u];
    while (u != v) ans[fe[u]] = ans[fe[v]] = w, u = fa[u], v = fa[v];
  };
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    b[i] = {u, v, w};
  }
  std::sort(b + 1, b + m + 1,
            [](const std::tuple<int, int, int> &lhs,
               const std::tuple<int, int, int> &rhs) {
              return std::get<2>(lhs) < std::get<2>(rhs);
            });
  for (int i = 1; i <= m; i++) {
    auto [u, v, w] = b[i];
    cov(u, v, w);
  }
  auto check = [](int u, int v, int w) {
    if (dep[u] < dep[v]) std::swap(u, v);
    int min = 0x3f3f3f3f;
    while (dep[u] > dep[v]) checkmin(min, ans[fe[u]]), u = fa[u];
    while (u != v)
      checkmin(min, std::min(ans[fe[u]], ans[fe[v]])), u = fa[u], v = fa[v];
    return min == w;
  };
  for (int i = 1; i <= m; i++) {
    auto [u, v, w] = b[i];
    if (!check(u, v, w)) {
      std::cout << -1;
      return 0;
    }
  }
  for (int i = 0; i < n - 1; i++) std::cout << (!ans[i] ? 1 : ans[i]) << ' ';
  return 0;
}