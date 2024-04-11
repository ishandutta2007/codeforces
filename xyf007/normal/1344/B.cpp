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
constexpr int kDx[] = {1, 0, -1, 0}, kDy[] = {0, 1, 0, -1};
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m;
char s[1001][1001];
bool vis[1001][1001], f[1001][1001];
void Bfs(int sx, int sy) {
  std::queue<std::pair<int, int>> q;
  q.emplace(sx, sy);
  vis[sx][sy] = true;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = x + kDx[i], ty = y + kDy[i];
      if (tx < 1 || tx > n || ty < 1 || ty > m || s[tx][ty] == '.' ||
          vis[tx][ty])
        continue;
      q.emplace(tx, ty);
      vis[tx][ty] = true;
    }
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  for (int i = 1; i <= n; i++) {
    int l = 1, r = m;
    while (l <= m && s[i][l] == '.') l++;
    while (r >= 1 && s[i][r] == '.') r--;
    for (int j = l; j <= r; j++)
      if (s[i][j] == '.') {
        std::cout << -1;
        return 0;
      }
    if (l <= r) {
      for (int j = 1; j < l; j++) f[i][j] = true;
      for (int j = r + 1; j <= m; j++) f[i][j] = true;
    }
  }
  for (int j = 1; j <= m; j++) {
    int u = 1, d = n;
    while (u <= n && s[u][j] == '.') u++;
    while (d >= 1 && s[d][j] == '.') d--;
    for (int i = u; i <= d; i++)
      if (s[i][j] == '.') {
        std::cout << -1;
        return 0;
      }
    if (u <= d) {
      for (int i = 1; i < u; i++) f[i][j] = true;
      for (int i = d + 1; i <= n; i++) f[i][j] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    for (int j = 1; j <= m; j++) ok &= f[i][j];
    if (ok) {
      std::cout << -1;
      return 0;
    }
  }
  for (int j = 1; j <= m; j++) {
    bool ok = true;
    for (int i = 1; i <= n; i++) ok &= f[i][j];
    if (ok) {
      std::cout << -1;
      return 0;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#' && !vis[i][j]) {
        ans++;
        Bfs(i, j);
      }
  std::cout << ans;
  return 0;
}