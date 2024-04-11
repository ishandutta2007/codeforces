#pragma GCC optimize("O3,unroll-loops")
#include <utility>
#include <vector>
#include <iostream>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, m, a[1001], b[1001], c[1001], cur, vis[1001], match[1001], cl, cr;
bool g[1001][1001];
bool Dfs(int u) {
  for (int v = 1; v <= cr; v++)
    if (g[u][v] && vis[v] != cur) {
      vis[v] = cur;
      if (!match[v] || Dfs(match[v])) {
        match[v] = u;
        return true;
      }
    }
  return false;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  int lim = m / 3;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) (a[i] > lim ? b[++cl] : c[++cr]) = a[i];
  for (int i = 1; i <= cl; i++)
    for (int j = 1; j <= cr; j++)
      g[i][j] = 2 * b[i] + c[j] <= m && b[i] % c[j] == 0;
  int ans = 0;
  for (cur = 1; cur <= cl; cur++) ans += Dfs(cur);
  if (ans < cl) {
    std::cout << -1;
    return 0;
  }
  std::vector<std::pair<int, int>> sol;
  for (int i = 1; i <= cr; i++)
    if (!match[i])
      sol.emplace_back(3 * c[i], 2 * c[i]);
    else
      sol.emplace_back(2 * b[match[i]] + c[i], b[match[i]] + c[i]);
  std::cout << sol.size() << '\n';
  for (const auto &[x, y] : sol) std::cout << x << ' ' << y << '\n';
  return 0;
}