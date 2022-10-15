#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
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
void Read(T &x, Args &...args) {
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
struct Edge {
  int to, nxt;
} e[200001];
int n, m, d, E, head[100001], a[100001], in[100001], out[100001], tot,
    dis[100001], max[18][100001], lg[100001], ans;
bool vis[100001];
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u, int fa) {
  in[u] = ++tot;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    dis[v] = dis[u] + 1;
    Dfs(v, u);
  }
  out[u] = tot;
}
int Query(int l, int r) {
  if (l > r) return -1;
  int len = lg[r - l + 1];
  return std::max(max[len][l], max[len][r - (1 << len) + 1]);
}
void Dfs(int u, int fa, int md) {
  if (std::max(md, Query(in[u], out[u]) - dis[u]) <= d) ans++;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    int tt =
        std::max(Query(in[u], in[v] - 1), Query(out[v] + 1, out[u])) - dis[u];
    Dfs(v, u, (tt >= 0 || md >= 0) ? std::max(tt, md) + 1 : -1);
  }
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n, m, d);
  for (int i = 1; i <= m; i++) Read(a[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    Read(u, v);
    Add(u, v);
    Add(v, u);
  }
  Dfs(1, 0);
  std::memset(max[0] + 1, -1, 4 * n);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= m; i++) max[0][in[a[i]]] = dis[a[i]];
  for (int i = 1; i <= lg[n]; i++)
    for (int j = 1; j + (1 << i) - 1 <= n; j++)
      max[i][j] = std::max(max[i - 1][j], max[i - 1][j + (1 << (i - 1))]);
  Dfs(1, 0, -1);
  std::printf("%d", ans);
  return 0;
}