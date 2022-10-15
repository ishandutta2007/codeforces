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
int T, n, m, k;
char s[11][21];
bool vis[11][21];
auto in = [](int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; };
bool Check(int x, int y, int len) {
  for (int i = 0; i <= len; i++, x++, y++) {
    if (!in(x, y)) return false;
    if (s[x][y] != '*') return false;
  }
  x--, y--;
  for (int i = 0; i <= len; i++, x--, y++) {
    if (!in(x, y)) return false;
    if (s[x][y] != '*') return false;
  }
  return true;
}
void Paint(int x, int y, int len) {
  for (int i = 0; i <= len; i++, x++, y++) vis[x][y] = true;
  x--, y--;
  for (int i = 0; i <= len; i++, x--, y++) vis[x][y] = true;
}
void Solve() {
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  std::memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int l = k; l <= n; l++)
        if (Check(i, j, l)) Paint(i, j, l);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '*' && !vis[i][j]) {
        std::cout << "NO\n";
        return;
      }
  std::cout << "YES\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}