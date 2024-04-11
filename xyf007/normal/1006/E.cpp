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
int n, q, fa[200001], sz[200001], dfn[200001], tot, r[200001];
std::vector<int> g[200001];
void Dfs(int u) {
  sz[r[dfn[u] = ++tot] = u] = 1;
  for (auto &&v : g[u]) Dfs(v), sz[u] += sz[v];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  for (int i = 2; i <= n; i++) std::cin >> fa[i], g[fa[i]].emplace_back(i);
  Dfs(1);
  while (q--) {
    int u, k;
    std::cin >> u >> k;
    if (k > sz[u])
      std::cout << "-1\n";
    else
      std::cout << r[dfn[u] + k - 1] << '\n';
  }
  return 0;
}