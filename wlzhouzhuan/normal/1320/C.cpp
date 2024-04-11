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

#define int long long
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

struct ele {
  int x, val;
  friend bool operator < (const ele &a, const ele &b) {
    return a.x < b.x;
  }
} a[N], b[N];

struct pp {
  int x, y, z;
  friend bool operator < (const pp &a, const pp &b) {
    return a.x < b.x;
  }
} c[N];

int n, m, p;

const ll inf = 1e18;
int ff[N << 2];
struct SegmentTree {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  long long val[N << 2];
  int tag[N << 2];
  void pu(int u) {
    val[u] = max(val[ls], val[rs]);
  }
  void pushdown(int u) {
    if (tag[u]) {
      val[ls] += tag[u], tag[ls] += tag[u];
      val[rs] += tag[u], tag[rs] += tag[u];
      tag[u] = 0;
    }
  }
  void build(int u, int l, int r) {
    if (l == r) {
      if (!ff[l]) {
        val[u] = -inf;
      } else {
        val[u] = -ff[l];
      }
      return ;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pu(u);
  }
  void update(int u, int l, int r, int ql, int qr, int x) {
    if (l > r || ql > qr) {
      return ;
    } 
    if (ql <= l && r <= qr) {
      tag[u] += x, val[u] += x;
      return ;
    }
    pushdown(u);
    int mid=  l + r >> 1;
    if (ql <= mid) update(ls, l, mid, ql, qr, x);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, x);
    pu(u);
  }
} smt;

signed main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; i++) {
    a[i].x = read();
    a[i].val = read();
  } 
  for (int i = 1; i <= m; i++) {
    b[i].x = read();
    b[i].val = read();
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  for (rint i = 1; i <= m; i++) {
    if (!ff[b[i].x] || b[i].val < ff[b[i].x]) {
      ff[b[i].x] = b[i].val;
    }
  }
  for (rint i = 1; i <= p; i++) {
    c[i].x = read();
    c[i].y = read();
    c[i].z = read();
  }
  sort(c + 1, c + p + 1);
  
  long long ans = -1e18;
  int cur = 0;
  smt.build(1, 1, 1e6);
  
  for (rint i = 1; i <= n; i++)  {
    while (cur < p && c[cur + 1].x < a[i].x) {
      cur++;
      smt.update(1, 1, 1e6, c[cur].y + 1, 1e6, c[cur].z);
    }
    ans = max(ans, smt.val[1] - a[i].val);
  }
  printf("%lld\n", ans);
  return 0; 
}