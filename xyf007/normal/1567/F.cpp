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
constexpr int kDx[] = {1, 1, 1, 0, -1, -1, -1, 0},
              kDy[] = {1, 0, -1, -1, -1, 0, 1, 1};
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, id[501][501], c, col[250001], ans[501][501];
auto in = [](int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; };
char s[501][501];
std::vector<int> g[250001];
void Dfs(int x, int y) {
  id[x][y] = c;
  for (int i = 0; i < 8; i++) {
    int tx = x + kDx[i], ty = y + kDy[i];
    if (in(tx, ty) && s[tx][ty] == '.' && !id[tx][ty]) Dfs(tx, ty);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++)
      if (s[i][j] == 'X') {
        int cnt = (s[i + 1][j] == '.') + (s[i][j + 1] == '.') +
                  (s[i - 1][j] == '.') + (s[i][j - 1] == '.');
        if (cnt & 1) {
          std::cout << "NO";
          return 0;
        }
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.' && !id[i][j]) c++, Dfs(i, j);
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++)
      if (s[i][j] == 'X') {
        bool lr = s[i][j - 1] == '.' && s[i][j + 1] == '.',
             ud = s[i - 1][j] == '.' && s[i + 1][j] == '.';
        if (lr && id[i][j - 1] != id[i][j + 1]) {
          g[id[i][j - 1]].emplace_back(id[i][j + 1]);
          g[id[i][j + 1]].emplace_back(id[i][j - 1]);
        }
        if (ud && id[i - 1][j] != id[i + 1][j]) {
          g[id[i - 1][j]].emplace_back(id[i + 1][j]);
          g[id[i + 1][j]].emplace_back(id[i - 1][j]);
        }
      }
  for (int i = 1; i <= c; i++) {
    std::sort(g[i].begin(), g[i].end());
    g[i].erase(std::unique(g[i].begin(), g[i].end()), g[i].end());
  }
  for (int i = 1; i <= c; i++)
    if (!col[i]) {
      col[i] = 1;
      std::queue<int> q;
      q.emplace(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &&v : g[u]) {
          if (!col[v]) {
            col[v] = 3 - col[u], q.emplace(v);
          } else if (col[v] != 3 - col[u]) {
            std::cout << "NO";
            return 0;
          }
        }
      }
    }
  for (int j = 1; j <= m; j++) {
    int cur = ans[1][j] = j & 1 ? 1 : 4, pre = col[id[1][j]];
    for (int i = 2; i <= n; i++)
      if (s[i][j] == '.') {
        if (col[id[i][j]] != pre) cur = 5 - cur;
        ans[i][j] = cur, pre = col[id[i][j]];
      }
  }
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++)
      if (s[i][j] == 'X') {
        if (s[i + 1][j] == '.') ans[i][j] += ans[i + 1][j];
        if (s[i][j + 1] == '.') ans[i][j] += ans[i][j + 1];
        if (s[i - 1][j] == '.') ans[i][j] += ans[i - 1][j];
        if (s[i][j - 1] == '.') ans[i][j] += ans[i][j - 1];
      }
  std::cout << "YES\n";
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) std::cout << ans[i][j] << " \n"[j == m];
  return 0;
}