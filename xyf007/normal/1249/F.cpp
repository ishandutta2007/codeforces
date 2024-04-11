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
int n, k, a[201], dp[201][201], tmp[201], len[201];
std::vector<int> g[201];
void Dfs(int u, int fa) {
  dp[u][0] = a[u];
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u);
    checkmax(len[u], len[v] + 1);
    dp[u][0] += dp[v][k - 1];
    std::memset(tmp, 0, sizeof(tmp));
    std::memcpy(tmp + 1, dp[u] + 1, 4 * len[u]);
    for (int i = 1; i <= len[u]; i++)
      for (int j = i - 1; j <= len[v]; j++)
        checkmax(dp[u][i], dp[v][j] + tmp[std::max(i, k - j - 1)]);
  }
  for (int i = len[u] - 1; i >= 0; i--) checkmax(dp[u][i], dp[u][i + 1]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k, k++;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  Dfs(1, 0);
  std::cout << dp[1][0];
  return 0;
}