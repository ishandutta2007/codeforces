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
int n, E, head[100001], sz[100001], maxp[100001], rt, SZ;
bool vis[100001];
char ans[100001];
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void GetRoot(int u, int fa) {
  sz[u] = 1;
  maxp[u] = 0;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa || vis[v]) continue;
    GetRoot(v, u);
    sz[u] += sz[v];
    checkmax(maxp[u], sz[v]);
  }
  checkmax(maxp[u], SZ - sz[u]);
  if (!rt || maxp[u] < maxp[rt]) rt = u;
}
void Solve(int u, char c) {
  ans[u] = c;
  vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (vis[v]) continue;
    SZ = sz[v];
    rt = 0;
    GetRoot(v, u);
    Solve(rt, c + 1);
  }
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
  SZ = n;
  GetRoot(1, 0);
  Solve(rt, 'A');
  for (int i = 1; i <= n; i++) std::printf("%c ", ans[i]);
  return 0;
}