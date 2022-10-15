#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <unordered_set>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) {
      return EOF;
    }
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9') {
    if (c == '-') {
      f = -1;
    }
  }
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') {
    x = x * 10 + c - '0';
  }
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
int n, E, head[100001], ans[100001], cnt[100001];
std::unordered_set<int> g[100001];
bool vis[100001];
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= 2 * n; i++) {
    int u, v;
    Read(u, v);
    g[u].emplace(v);
    g[v].emplace(u);
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() != 4) {
      std::printf("-1");
      return 0;
    }
  }
  ans[1] = 1;
  for (auto &&u : g[1]) {
    cnt[u]++;
    for (auto &&v : g[u]) {
      cnt[v]++;
    }
  }
  for (auto &&u : g[1]) {
    if (cnt[u] >= 3) {
      if (!ans[2]) {
        ans[2] = u;
      } else if (!ans[n]) {
        ans[n] = u;
      }
    }
  }
  std::memset(cnt, 0, sizeof(cnt));
  std::memset(vis, false, sizeof(vis));
  vis[1] = vis[ans[2]] = vis[ans[n]] = true;
  for (int i = 2; i <= n - 2; i++) {
    int pos = -1;
    for (auto &&j : g[ans[i - 1]]) {
      cnt[j]++;
    }
    for (auto &&j : g[ans[i]]) {
      if (++cnt[j] == 2 && !vis[j]) {
        pos = j;
      }
    }
    if (pos == -1) {
      std::printf("-1");
      return 0;
    }
    vis[ans[i + 1] = pos] = true;
    for (auto &&j : g[ans[i - 1]]) {
      cnt[j]--;
    }
    for (auto &&j : g[ans[i]]) {
      cnt[j]--;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::printf("%d ", ans[i]);
  }
  return 0;
}