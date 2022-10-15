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

const int inf = 1e9;
const int N = 300005;
// Max - Min + j = i 
// ->  min(Max - Min + j)
struct SegmentTree {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  int val[N << 2], cnt[N << 2], tag[N << 2];
  void pushup(int u) {
    val[u] = min(val[ls], val[rs]), cnt[u] = 0;
    if (val[ls] < val[u]) val[u] = val[ls], cnt[u] = cnt[ls];
    else if (val[ls] == val[u]) cnt[u] += cnt[ls];
    if (val[rs] < val[u]) val[u] = val[rs], cnt[u] = cnt[rs];
    else if (val[rs] == val[u]) cnt[u] += cnt[rs]; 
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
      val[u] = l, cnt[u] = 1;
      return ;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(u);
  }
  void update(int u, int l, int r, int ql, int qr, int x) {
    if (ql > qr || qr < l || ql > r) return ;
    if (ql <= l && r <= qr) {
      val[u] += x, tag[u] += x;
      return ;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (ql <= mid) update(ls, l, mid, ql, qr, x);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, x);
    pushup(u);
  }
  int query() {
    return cnt[1];
  }
} smt;
int a[N], n;
int st1[N], tp1; // 
int st2[N], tp2; // 
 
int main() {
  scanf("%d", &n);
  for (rint i = 1; i <= n; i++) {
    int x = read(), y = read();
    a[x] = y;
  }
  smt.build(1, 1, n);
  long long ans = 0ll;
  for (rint i = 1; i <= n; i++) { // Max - Min + j
    //  
    while (tp1 > 0 && a[st1[tp1]] < a[i]) {
      smt.update(1, 1, n, st1[tp1 - 1] + 1, st1[tp1], -a[st1[tp1]]);
      tp1--; 
    }
    smt.update(1, 1, n, st1[tp1] + 1, i, a[i]); st1[++tp1] = i;
    // 
    while (tp2 > 0 && a[st2[tp2]] > a[i]) {
      smt.update(1, 1, n, st2[tp2 - 1] + 1, st2[tp2], a[st2[tp2]]);
      tp2--;
    } 
    smt.update(1, 1, n, st2[tp2] + 1, i, -a[i]); st2[++tp2] = i;
    ans += smt.query();
  }
  printf("%lld\n", ans);
  return 0;
}