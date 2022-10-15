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
constexpr int kDt[4][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, bj, ans, di[1000001], c, st[1000001], cnt[1000001], E, head[1000001],
    nxt[4000001], f[1005][1005], to[4000001];
char a[1005][1005];
bool vis[1000001];
auto S = [](char ch) {
  if (ch == 'D') return 1;
  if (ch == 'I') return 2;
  if (ch == 'M') return 3;
  if (ch == 'A') return 4;
};
auto F = [](int x, int y) { return (x - 1) * m + y; };
void Add(int s, int e) {
  nxt[++E] = head[s];
  to[E] = e;
  head[s] = E;
}
auto nt = [](int x) { return x == 4 ? 1 : x + 1; };
void Dfs(int u) {
  if (di[u]) return;
  vis[u] = true;
  di[u] = 1;
  for (int i = head[u]; i != -1; i = nxt[i]) {
    int v = to[i];
    if (vis[v]) {
      std::cout << "Poor Inna!";
      std::exit(0);
    }
    Dfs(v);
    checkmax(di[u], di[v] + 1);
  }
  vis[u] = false;
}
int main(int argc, char const *argv[]) {
  memset(head, -1, sizeof(head));
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (int j = 0; j <= m - 1; j++) f[i][j + 1] = S(a[i][j]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k <= 3; k++) {
        int dx = i + kDt[k][0], dy = j + kDt[k][1];
        if (dx < 1 || dx > n || dy < 1 || dy > m) continue;
        if (nt(f[i][j]) == f[dx][dy]) Add(F(i, j), F(dx, dy));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (f[i][j] != 1) continue;
      Dfs(F(i, j));
      checkmax(ans, di[F(i, j)]);
    }
  }
  ans = ans / 4;
  if (ans != 0)
    std::cout << ans;
  else
    std::cout << "Poor Dima!";
  return 0;
}