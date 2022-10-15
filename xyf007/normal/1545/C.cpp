#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
constexpr int kMod = 998244353;
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &... args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int t, n, a[1001][501], cnt[501][501], col[1001];
bool vis[1001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n);
    for (int i = 1; i <= 2 * n; i++)
      for (int j = 1; j <= n; j++) {
        Read(a[i][j]);
        cnt[j][a[i][j]]++;
      }
    std::vector<int> ans;
    while (true) {
      int c = -1;
      for (int i = 1; i <= n; i++)
        if (std::count(cnt[i] + 1, cnt[i] + n + 1, 1)) {
          c = i;
          break;
        }
      if (c == -1) break;
      int r = -1;
      for (int i = 1; i <= 2 * n; i++)
        if (!vis[i] && cnt[c][a[i][c]] == 1) r = i;
      vis[r] = true;
      ans.emplace_back(r);
      for (int i = 1; i <= n; i++) cnt[i][a[r][i]]--;
      for (int i = 1; i <= 2 * n; i++) {
        if (vis[i]) continue;
        bool f = false;
        for (int j = 1; j <= n; j++)
          if (a[r][j] == a[i][j]) {
            f = true;
            break;
          }
        if (f) {
          vis[i] = true;
          for (int j = 1; j <= n; j++) cnt[j][a[i][j]]--;
        }
      }
    }
    int s = 1;
    std::memset(col, -1, sizeof(col));
    for (int i = 1; i <= 2 * n; i++) {
      if (vis[i]) continue;
      col[i] = 0;
      std::queue<int> q;
      q.emplace(i);
      vis[i] = true;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!col[u]) ans.emplace_back(u);
        for (int v = 1; v <= 2 * n; v++) {
          if (vis[v]) continue;
          bool f = false;
          for (int j = 1; j <= n; j++)
            if (a[u][j] == a[v][j]) {
              f = true;
              break;
            }
          if (f) {
            col[v] = col[u] ^ 1;
            q.emplace(v);
            vis[v] = true;
          }
        }
      }
      s = s * 2 % kMod;
    }
    std::printf("%d\n", s);
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) std::printf("%d%c", ans[i], " \n"[i == n - 1]);
    std::memset(vis, false, sizeof(vis));
    std::memset(cnt, 0, sizeof(cnt));
  }
  return 0;
}