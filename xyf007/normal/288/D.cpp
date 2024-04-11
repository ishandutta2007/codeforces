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
} e[160001];
int n, E, head[80001], sz[80001];
long long ans;
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u, int fa) {
  sz[u] = 1;
  long long s1 = 0, s2 = 0;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    Dfs(v, u);
    s1 -= sz[v] * static_cast<long long>(sz[v] - 1) / 2;
    sz[u] += sz[v];
  }
  s1 += sz[u] * static_cast<long long>(sz[u] - 1) / 2;
  s2 = sz[u] * static_cast<long long>(n - sz[u]);
  ans += s1 * s1 + 2 * s1 * s2;
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    Read(u, v);
    Add(u, v);
    Add(v, u);
  }
  Dfs(1, 0);
  unsigned long long t = n * static_cast<unsigned long long>(n - 1) / 2;
  std::printf("%llu", t * t - ans);
  return 0;
}