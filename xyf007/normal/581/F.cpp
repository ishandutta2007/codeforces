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
int n, dp[5001][5001][2], sz[5001], f[5001][2];
std::vector<int> g[5001];
void Dfs(int u, int fa) {
  sz[u] = g[u].size() == 1;
  if (sz[u]) dp[u][0][1] = dp[u][1][0] = 0x3f3f3f3f;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u);
    for (int i = 0; i <= sz[u] + sz[v]; i++) f[i][0] = f[i][1] = 0x3f3f3f3f;
    for (int i = 0; i <= sz[u]; i++)
      for (int j = 0; j <= sz[v]; j++) {
        checkmin(f[i + j][0], dp[u][i][0] + dp[v][j][0]);
        checkmin(f[i + j][0], dp[u][i][0] + dp[v][j][1] + 1);
        checkmin(f[i + j][1], dp[u][i][1] + dp[v][j][0] + 1);
        checkmin(f[i + j][1], dp[u][i][1] + dp[v][j][1]);
      }
    sz[u] += sz[v];
    for (int i = 0; i <= sz[u]; i++)
      dp[u][i][0] = f[i][0], dp[u][i][1] = f[i][1];
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  if (n == 2) {
    std::cout << 1;
    return 0;
  }
  int lf = std::count_if(g + 1, g + n + 1, [](const std::vector<int> &x) {
    return x.size() == 1;
  });
  for (int i = 1; i <= n; i++)
    if (g[i].size() > 1) {
      Dfs(i, 0);
      std::cout << std::min(dp[i][lf >> 1][0], dp[i][lf >> 1][1]);
      return 0;
    }
  return 0;
}