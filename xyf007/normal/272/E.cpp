#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
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
} e[600001];
int n, m, E, head[300001], deg[300001], d[300001], col[300001];
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n, m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    Read(u, v);
    Add(u, v);
    Add(v, u);
    deg[u]++;
    deg[v]++;
  }
  std::memcpy(d + 1, deg + 1, 4 * n);
  std::queue<int> q;
  for (int i = 1; i <= n; i++)
    if (deg[i] > 1) q.emplace(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (deg[u] <= 1) continue;
    col[u] ^= 1;
    deg[u] = d[u] - deg[u];
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (col[u] == col[v]) {
        if (++deg[v] > 1) q.emplace(v);
      } else {
        deg[v]--;
      }
    }
  }
  for (int i = 1; i <= n; i++) std::printf("%d", col[i]);
  return 0;
}