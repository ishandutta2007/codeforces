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
int n, k, deg[200001], a[200001], c[200001];
std::vector<std::pair<int, int>> g[200001];
void Dfs(int u, int fa, int fc) {
  int nc = 1;
  for (auto &&[v, id] : g[u]) {
    if (v == fa) continue;
    if (deg[u] > deg[a[k + 1]]) {
      c[id] = fc, Dfs(v, u, fc);
    } else {
      if (nc == fc) nc++;
      c[id] = nc, Dfs(v, u, nc++);
    }
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v, i), g[v].emplace_back(u, i);
    deg[u]++, deg[v]++;
  }
  std::iota(a + 1, a + n + 1, 1);
  std::sort(a + 1, a + n + 1,
            [](const int &lhs, const int &rhs) { return deg[lhs] > deg[rhs]; });
  std::cout << deg[a[k + 1]] << '\n';
  Dfs(a[k + 1], 0, 0);
  for (int i = 1; i < n; i++) std::cout << c[i] << ' ';
  return 0;
}