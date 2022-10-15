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
int n, dep[200001];
long long s, a[200001], sum[200001], dp[200001];
std::vector<int> g[200001];
void Dfs(int u, int fa) {
  sum[u] = a[u];
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    dep[v] = dep[u] + 1;
    Dfs(v, u);
    sum[u] += sum[v];
  }
}
void Dfs2(int u, int fa) {
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    dp[v] = dp[u] + s - 2 * sum[v];
    Dfs2(v, u);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  s = std::accumulate(a + 1, a + n + 1, 0LL);
  Dfs(1, 0);
  dp[1] = std::inner_product(dep + 1, dep + n + 1, a + 1, 0LL);
  Dfs2(1, 0);
  std::cout << *std::max_element(dp + 1, dp + n + 1);
  return 0;
}