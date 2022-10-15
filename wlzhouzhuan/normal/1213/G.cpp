// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void ckmax(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
inline void ckmin(T &a, T b) {
  if (a > b) a = b;
}

const int N = 200003;

struct Edge {
  int u, v, w;
  void inp() { u = read(), v = read(), w = read(); }
  friend bool operator < (const Edge &a, const Edge &b) {
    return a.w < b.w;
  }
} edge[N];
struct ele {
  int x, id;
  friend bool operator < (const ele &a, const ele &b) {
    return a.x < b.x;
  }
} q[N];
long long ans[N];
int n, m;

int f[N], sz[N];
long long _ans = 0;
int find(int k) { return f[k] == k ? k : f[k] = find(f[k]); }
long long sqr(int x) { return 1ll * x * (x - 1) / 2; }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (sz[x] > sz[y]) swap(x, y);
  _ans += sqr(sz[x] + sz[y]) - sqr(sz[x]) - sqr(sz[y]);
  f[x] = y, sz[y] += sz[x];
}

int main() {
  n = read(), m = read();
  for (rint i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
  for (rint i = 1; i < n; i++) edge[i].inp();
  for (rint i = 1; i <= m; i++) q[i].x = read(), q[i].id = i;
  sort(edge + 1, edge + n); sort(q + 1, q + m + 1);
  int tail = 1;
  for (rint i = 1; i <= m; i++) {
    while (tail <= n && edge[tail].w <= q[i].x) merge(edge[tail].u, edge[tail].v), tail++;
    ans[q[i].id] = _ans;
  }
  for (rint i = 1; i <= m; i++) printf("%lld ", ans[i]); puts("");
  return 0;
}