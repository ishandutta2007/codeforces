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
} e[1000001];
int n, q, E, head[500001], dep[500001], sz[500001], son[500001], fa[500001],
    dfn[500001], tot, top[500001], tag[2000001];
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u, int f) {
  sz[u] = 1;
  dep[u] = dep[fa[u] = f] + 1;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == f) continue;
    Dfs(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void Dfs2(int u, int t) {
  dfn[u] = ++tot;
  top[u] = t;
  if (son[u]) Dfs2(son[u], t);
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa[u] || v == son[u]) continue;
    Dfs2(v, v);
  }
}
void Pushdown(int x) {
  if (~tag[x]) {
    tag[x + x] = tag[x + x + 1] = tag[x];
    tag[x] = -1;
  }
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    tag[x] = v;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, v, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, v, x + x + 1);
}
void Modify(int u) {
  while (u) {
    Modify(dfn[top[u]], dfn[u], 1, n, 0, 1);
    u = fa[top[u]];
  }
}
int Query(int l, int r, int p, int x) {
  if (l == r) return tag[x];
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (p <= mid)
    return Query(l, mid, p, x + x);
  else
    return Query(mid + 1, r, p, x + x + 1);
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
  Dfs2(1, 1);
  Read(q);
  while (q--) {
    int op, x;
    Read(op, x);
    if (op == 1)
      Modify(dfn[x], dfn[x] + sz[x] - 1, 1, n, 1, 1);
    else if (op == 2)
      Modify(x);
    else
      std::printf("%d\n", Query(1, n, dfn[x], 1));
  }
  return 0;
}