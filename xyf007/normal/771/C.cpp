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
int n, k, sz[200001];
std::vector<int> g[200001];
long long f[200001][5];
void Dfs1(int u, int fa) {
  sz[u] = 1;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs1(v, u);
    sz[u] += sz[v], f[u][0] += f[v][k - 1] + sz[v];
    for (int i = 1; i < k; i++) f[u][i] += f[v][i - 1];
  }
}
void Dfs2(int u, int fa) {
  long long t[5] = {0};
  if (fa) {
    t[0] = f[fa][0] - f[u][k - 1] - sz[u];
    for (int i = 1; i < k; i++) t[i] = f[fa][i] - f[u][i - 1];
  }
  f[u][0] += t[k - 1] + n - sz[u];
  for (int i = 1; i < k; i++) f[u][i] += t[i - 1];
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs2(v, u);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  Dfs1(1, 0), Dfs2(1, 0);
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) ans += f[i][0];
  std::cout << ans / 2;
  return 0;
}