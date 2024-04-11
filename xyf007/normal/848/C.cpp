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
struct Node {
  int x, y, v, op, id;
} b[1000001];
int n, m, tot, a[100001], pre[100001], nxt[100001];
std::set<int> s[100001];
long long t[100002], ans[100001];
void Modify(int x, int y) {
  b[++tot] = {x, pre[x], pre[x] - x, 0, 0};
  pre[x] = y;
  b[++tot] = {x, pre[x], x - pre[x], 0, 0};
}
void Add(int x, int v) {
  x++;
  while (x <= n + 1) {
    t[x] += v;
    x += x & -x;
  }
}
long long Query(int x) {
  x++;
  long long s = 0LL;
  while (x) {
    s += t[x];
    x -= x & -x;
  }
  return s;
}
auto cmp = [](const Node &lhs, const Node &rhs) {
  if (lhs.op != rhs.op) return lhs.op < rhs.op;
  if (lhs.op) return lhs.y < rhs.y;
  return lhs.x < rhs.x;
};
void Cdq(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1, p = l;
  Cdq(l, mid), Cdq(mid + 1, r);
  for (int i = mid + 1; i <= r; i++)
    if (b[i].op) {
      while (p <= mid && (b[p].op || b[p].x <= b[i].y)) {
        if (!b[p].op) Add(b[p].y, b[p].v);
        p++;
      }
      ans[b[i].id] += Query(n) - Query(b[i].x - 1);
    }
  for (int i = l; i < p; i++)
    if (!b[i].op) Add(b[i].y, -b[i].v);
  std::sort(b + l, b + r + 1, cmp);
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) s[i].emplace(0), s[i].emplace(n + 1);
  for (int i = 1; i <= n; i++) Read(a[i]), s[a[i]].emplace(i);
  auto calcpre = [](int x, int c) { return *--s[c].lower_bound(x); };
  auto calcnxt = [](int x, int c) { return *s[c].upper_bound(x); };
  for (int i = 1; i <= n; i++) {
    pre[i] = calcpre(i, a[i]), nxt[i] = calcnxt(i, a[i]);
    b[++tot] = {i, pre[i], i - pre[i], 0, 0};
  }
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    Read(op, x, y);
    if (op == 1) {
      if (y == a[x]) continue;
      int pr = calcpre(x, y), nx = calcnxt(x, y);
      s[a[x]].erase(x), s[a[x] = y].emplace(x);
      if (nxt[x] != n + 1) Modify(nxt[x], pre[x]);
      if (pre[x]) nxt[pre[x]] = nxt[x];
      if (nx != n + 1) Modify(nx, x);
      if (pr) nxt[pr] = x;
      nxt[x] = nx;
      Modify(x, pr);
    } else {
      b[++tot] = {x, y, 0, 1, ++cnt};
    }
  }
  Cdq(1, tot);
  for (int i = 1; i <= cnt; i++) std::printf("%lld\n", ans[i]);
  return 0;
}