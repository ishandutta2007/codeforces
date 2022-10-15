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
int n, m, k, dep[100001], fa[100001];
bool vis[100001];
std::vector<int> g[100001];
void Dfs(int u) {
  vis[u] = true;
  for (auto &&v : g[u]) {
    if (vis[v]) continue;
    dep[v] = dep[u] + 1, fa[v] = u;
    Dfs(v);
  }
}
void SolveTree() {
  std::vector<int> a[2];
  for (int i = 1; i <= n; i++) a[dep[i] & 1].emplace_back(i);
  int l = (k + 1) >> 1;
  if (a[0].size() < a[1].size()) std::swap(a[0], a[1]);
  std::cout << "1\n";
  for (int i = 0; i < l; i++) std::cout << a[0][i] << ' ';
  std::exit(0);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  Dfs(1);
  if (m == n - 1) SolveTree();
  for (int u = 1; u <= n; u++)
    for (auto &&v : g[u]) {
      int d = std::abs(dep[u] - dep[v]);
      if (d > 1 && d < k) {
        int x = dep[u] > dep[v] ? u : v, y = dep[u] < dep[v] ? u : v;
        std::vector<int> a;
        while (x != y) a.emplace_back(x), x = fa[x];
        a.emplace_back(y);
        std::cout << "2\n" << a.size() << '\n';
        for (auto &&i : a) std::cout << i << ' ';
        return 0;
      }
    }
  int l = (k + 1) >> 1;
  for (int i = 1; i <= n; i++)
    if (dep[i] >= k) {
      std::cout << "1\n";
      for (int j = 1; j <= l; j++) std::cout << i << ' ', i = fa[fa[i]];
      return 0;
    }
  return 0;
}