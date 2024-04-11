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
int n, m;
long long k, a[21][21];
std::vector<long long> f[21][21], g[21][21];
bool vis[21][21];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) std::cin >> a[i][j];
  f[1][1].emplace_back(0LL);
  std::queue<std::pair<int, int>> q;
  q.emplace(1, 1);
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto &&s : f[x][y]) s ^= a[x][y];
    if (x + y == n + 1) continue;
    if (x < n)
      for (auto &&s : f[x][y]) f[x + 1][y].emplace_back(s);
    if (y < m)
      for (auto &&s : f[x][y]) f[x][y + 1].emplace_back(s);
    if (x < n && !vis[x + 1][y]) q.emplace(x + 1, y), vis[x + 1][y] = true;
    if (y < m && !vis[x][y + 1]) q.emplace(x, y + 1), vis[x][y + 1] = true;
  }
  std::memset(vis, false, sizeof(vis));
  g[n][m].emplace_back(0LL);
  q.emplace(n, m);
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (x + y == n + 1) continue;
    for (auto &&s : g[x][y]) s ^= a[x][y];
    if (x > 1)
      for (auto &&s : g[x][y]) g[x - 1][y].emplace_back(s);
    if (y > 1)
      for (auto &&s : g[x][y]) g[x][y - 1].emplace_back(s);
    if (x > 1 && !vis[x - 1][y]) q.emplace(x - 1, y), vis[x - 1][y] = true;
    if (y > 1 && !vis[x][y - 1]) q.emplace(x, y - 1), vis[x][y - 1] = true;
  }
  long long ans = 0LL;
  for (int i = 1, j = n - i + 1; i <= n; i++, j--)
    if (j <= m) {
      std::unordered_map<long long, int> mp;
      for (auto &&s : g[i][j]) mp[s]++;
      for (auto &&s : f[i][j])
        if (mp.count(s ^ k)) ans += mp[s ^ k];
    }
  std::cout << ans;
  return 0;
}