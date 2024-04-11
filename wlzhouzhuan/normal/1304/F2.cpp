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

template <typename T>
void ckmin(T &a, T b) {
  if (a > b) a = b;
}
template <typename T>
void ckmax(T &a, T b) {
  if (a < b) a = b;
}

const int N = 20005;
struct SegmentTree {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  ll mx[N << 2], lzy[N << 2];
  void clear() {
    mset(mx, 0), mset(lzy, 0);
  }
  void pushup(int u) {
    mx[u] = max(mx[ls], mx[rs]);
  }
  void pushdown(int u) {
    if (lzy[u]) {
      mx[ls] -= lzy[u], mx[rs] -= lzy[u];
      lzy[ls] += lzy[u], lzy[rs] += lzy[u];
      lzy[u] = 0;
    }
  }
  void update(int u, int l, int r, int ql, int qr, ll v) {
    if (ql <= l && r <= qr) {
      mx[u] -= v;
      lzy[u] += v;
      return ;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (ql <= mid) update(ls, l, mid, ql, qr, v);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, v);
    pushup(u);
  }
  void cover(int u, int l, int r, int pos, ll v) {
    if (l == r) {
      mx[u] = v;
      return ;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (pos <= mid) cover(ls, l, mid, pos, v);
    else cover(rs, mid + 1, r, pos, v);
    pushup(u);
  }
  ll query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return mx[u];
    pushdown(u);
    int mid = l + r >> 1; ll ret = 0;
    if (ql <= mid) ret = max(ret, query(ls, l, mid, ql, qr));
    if (qr > mid) ret = max(ret, query(rs, mid + 1, r, ql, qr));
    return ret;
  }
} smt;

ll a[55][20005], row[55][20005];
int n, m, k;
ll dp[55][20005];

void IOI(int x, ll num) {
  int l = max(1, x - k + 1);
  int r = min(m - k + 1, x);
  smt.update(1, 1, m - k + 1, l, r, num);
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (rint i = 1; i <= n; i++) {
    for (rint j = 1; j <= m; j++) {
      scanf("%lld", &a[i][j]);
      row[i][j] = row[i][j - 1] + a[i][j];
      //printf("row[%d][%d] = %lld\n", i, j, row[i][j]);
    }
  }
  for (rint i = 1; i <= n; i++) {
    smt.clear();
    for (rint j = 1; j <= m - k + 1; j++) {
      smt.cover(1, 1, m - k + 1, j, dp[i - 1][j]);
    }
    if (i > 1) {
      for (rint j = 1; j <= k; j++) {
        IOI(j, a[i][j]);
      }
    }
    for (rint j = 1; j <= m - k + 1; j++) {
      if (i > 1 && j > 1) IOI(j - 1, -a[i][j - 1]), IOI(j + k - 1, a[i][j + k - 1]);
      dp[i][j] = smt.query(1, 1, m - k + 1, 1, m - k + 1) + row[i][j + k - 1] - row[i][j - 1] + row[i + 1][j + k - 1] - row[i + 1][j - 1]; 
    }
  }
  long long ans = 0;
  for (rint i = 1; i <= m - k + 1; i++) ans = max(ans, dp[n][i]);
  printf("%lld\n", ans);
  return 0;
}