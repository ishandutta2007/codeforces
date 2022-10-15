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
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>

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

const int N = 1000005;
struct SegmentTree {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  int mx[N << 2], lzy[N << 2];
  
  void pushup(int u) {
    mx[u] = max(mx[ls], mx[rs]);
  }
  void pushdown(int u) {
    if (lzy[u]) {
      mx[ls] += lzy[u], lzy[ls] += lzy[u];
      mx[rs] += lzy[u], lzy[rs] += lzy[u];
      lzy[u] = 0;
    }
  }
  void build(int u, int l, int r) {
    mx[u] = lzy[u] = 0;
    if (l == r) {
      mx[u] = l - 1;
      return ; 
    }  
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(u);
  }
  void update(int u, int l, int r, int ql, int qr, int dlt) {
    if (ql <= l && r <= qr) {
      mx[u] += dlt;
      lzy[u] += dlt;
      return ;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (ql <= mid) update(ls, l, mid, ql, qr, dlt);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, dlt);
    pushup(u);
  }
  int query(int u, int l, int r, int ql, int qr) {
    if (ql > qr) return 0;
    if (ql <= l && r <= qr) {
      return mx[u];
    }
    pushdown(u);
    pushup(u);
    int mid = l + r >> 1;
    int ret = 0;
    if (ql <= mid) ret = max(ret, query(ls, l, mid, ql, qr));
    if (qr > mid) ret = max(ret, query(rs, mid + 1, r, ql, qr));
    return ret;
  }
} smt;

int cnt[N], n, k, m;
set <pii> come;
set <int> row;

int main() {
  n = read(), k = read(), m = read();
  smt.build(1, 1, 2 * n + m);
  for (rint _ = 1; _ <= m; _++) {
    int x = read(), y = read();
    int s = y + abs(x - k), dlt;
    if (come.count(make_pair(x, y))) {
      come.erase(make_pair(x, y));
      if (--cnt[s] == 0) row.erase(s);
      dlt = -1;
    } else {
      come.insert(make_pair(x, y));
      if (cnt[s]++ == 0) row.insert(s);
      dlt = 1; 
    }
    //printf("now s = %d, dlt = %d\n", s, dlt);
    //printf("row = %d\n", *row.rbegin());
    smt.update(1, 1, 2 * n + m, 1, s, dlt);
    if (row.empty()) {
      puts("0");
      continue;
    }
    printf("%d\n", max(smt.query(1, 1, 2 * n + m, 1, *row.rbegin()) - n, 0));
    //smt.print(1, 1, 2 * n + m);
  }
  return 0;
}