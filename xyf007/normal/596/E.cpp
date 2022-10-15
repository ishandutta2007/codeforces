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
int n, m, q, to[40001], a[201][201], dx[11], dy[11], id[201][201], cnt,
    vis[40001], cntcyc, len;
char s[205][205], t[1000005];
std::vector<int> g[40001][11], cyc[40001];
bool hav[40001][10], incyc[40001], ok;
auto in = [](int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; };
void Dfs(int u) {
  if (vis[u] == 2) return;
  if (vis[u] == 1) {
    cyc[++cntcyc].push_back(u), incyc[u] = true;
    int x = (u - 1) / m + 1, y = (u - 1) % m + 1;
    hav[cntcyc][a[x][y]] = true;
    for (int i = to[u]; i != u; i = to[i]) {
      cyc[cntcyc].push_back(i), incyc[i] = true;
      x = (i - 1) / m + 1, y = (i - 1) % m + 1;
      hav[cntcyc][a[x][y]] = true;
    }
    vis[u] = 2;
    return;
  }
  vis[u] = 1;
  Dfs(to[u]);
  vis[u] = 2;
}
bool Find(int u, int pos) {
  if (pos == len + 1) return true;
  for (int i = 0; i <= 9; i++)
    for (auto &&v : g[u][i])
      if (Find(v, pos + (i == t[pos] - '0'))) return true;
  return false;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = s[i][j] - '0';
  for (int i = 0; i <= 9; i++) std::cin >> dx[i] >> dy[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) id[i][j] = ++cnt;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x = i + dx[a[i][j]], y = j + dy[a[i][j]];
      if (!in(x, y)) x = i, y = j;
      to[id[i][j]] = id[x][y];
    }
  for (int i = 1; i <= n * m; i++)
    if (!vis[i]) Dfs(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x = i + dx[a[i][j]], y = j + dy[a[i][j]];
      if (!in(x, y)) x = i, y = j;
      if (!incyc[id[i][j]]) g[id[x][y]][a[i][j]].push_back(id[i][j]);
    }
  while (q--) {
    std::cin >> (t + 1), len = std::strlen(t + 1);
    std::reverse(t + 1, t + len + 1);
    ok = false;
    int fir[10];
    for (int i = 0; i <= 9; i++) fir[i] = len + 1;
    for (int i = 1; i <= len; i++) checkmin(fir[t[i] - '0'], i);
    for (int i = 1; i <= cntcyc && !ok; i++) {
      int unmatch = len + 1;
      for (int j = 0; j <= 9; j++)
        if (!hav[i][j]) checkmin(unmatch, fir[j]);
      if (unmatch == len + 1) {
        std::cout << "YES\n";
        ok = true;
        break;
      }
      for (auto &&u : cyc[i])
        if (Find(u, unmatch)) {
          std::cout << "YES\n";
          ok = true;
          break;
        }
    }
    if (!ok) std::cout << "NO\n";
  }
  return 0;
}