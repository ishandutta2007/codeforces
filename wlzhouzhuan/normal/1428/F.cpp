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
#define fir first
#define sec second

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
const int err = 1e9;

struct SegmentTree {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  ll mx[N << 2], sum[N << 2];
  ll minn[N << 2], maxx[N << 2];
  ll lzy[N << 2];
  void pushup(int u) { 
    sum[u] = sum[ls] + sum[rs]; 
    maxx[u] = max(maxx[ls], maxx[rs]);
    minn[u] = min(minn[ls], minn[rs]); 
  }
  void pushdown(int u, int l, int r) {
    if (lzy[u] != 0) {
      lzy[ls] = lzy[u], lzy[rs] = lzy[u];
      maxx[ls] = minn[ls] = lzy[u];
      maxx[rs] = minn[rs] = lzy[u];
      int mid = l + r >> 1; 
      sum[ls] = 1ll * (mid - l + 1) * lzy[u];
      sum[rs] = 1ll * (r - mid) * lzy[u];
      lzy[u] = 0; 
    }
  }
  void cover(int u, int l, int r, int pos, int dlt) {
    if (l == r) {
      sum[u] += dlt;
      maxx[u] = minn[u] = sum[u];
      return ;
    }
    pushdown(u, l, r);
    int mid = l + r >> 1;
    if (pos <= mid) cover(ls, l, mid, pos, dlt);
    else cover(rs, mid + 1, r, pos, dlt);
    pushup(u);
  }
  void cover(int u, int l, int r, int ql, int qr, int dlt) {
    if (ql <= l && r <= qr) {
      maxx[u] = minn[u] = dlt;
      lzy[u] = dlt;
      sum[u] = 1ll * maxx[u] * (r - l + 1);
      return ;
    }
    pushdown(u, l, r);
    int mid = l + r >> 1;
    if (ql <= mid) cover(ls, l, mid, ql, qr, dlt);
    if (qr > mid) cover(rs, mid + 1, r, ql, qr, dlt);
    pushup(u);
  }
  int get(int u, int l, int r, int ql, int qr, int dlt) {
    if (minn[u] > dlt) return err;
    pushdown(u, l, r);
    if (l == r) {
      return sum[u] <= dlt ? l : err;
    }
    int mid = l + r >> 1;
    if (ql <= l && r <= qr) {
      if (minn[u] > dlt) return err;
      if (minn[ls] <= dlt) return get(ls, l, mid, ql, qr, dlt);
      else return get(rs, mid + 1, r, ql, qr, dlt);
    }
    if (qr <= mid) return get(ls, l, mid, ql, qr, dlt);
    if (ql > mid) return get(rs, mid + 1, r, ql, qr, dlt);
    int x = get(ls, l, mid, ql, qr, dlt);
    if (x != err) return x;
    x = get(rs, mid + 1, r, ql, qr, dlt);
    return x;
  }
  void update(int u, int l, int r, int ql, int qr, int dlt) {
    int pos = get(u, l, r, ql, qr, dlt);
    //printf("pos = %d\n", pos);
    if (pos == err) return ;
    cover(u, l, r, pos, qr, dlt);
  }
} smt;
ll S2(ll x) { return x * (x + 1) / 2; }
char s[N];
int n;
long long ans = 0ll;

int main() {
  scanf("%d%s", &n, s + 1);
  int lst = 0;
  for (int i = 1; i <= n; i++) {
    s[i] -= '0';
    if (s[i] == 0) {
      if (!lst) {
        ans += smt.sum[1];
        continue;
      }
      for (int j = lst; j < i; j++) {
        smt.cover(1, 1, n, j, i - j);
      }
      ans += smt.sum[1];
      lst = 0;
    } else {
      if (!lst) lst = i;
      //printf("lst = %d\n", lst);
      if (lst > 1) smt.update(1, 1, n, 1, lst - 1, i - lst + 1);
      ans += smt.sum[1] + S2(i - lst + 1);
    }
    //printf("i = %d, ans = %lld\n", i, ans);
  } 
  printf("%lld\n", ans);
  return 0;
}