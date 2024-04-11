// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast") 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 200005;
const int inf = 1e9;

vector<int> zip[N];
int ans1[N], ans2[N];
int a[N], n;

struct SMT {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  int opt;
  int maxx[N << 2], lazy[N << 2];
  void pushup(int u) { maxx[u] = max(maxx[ls], maxx[rs]); }
  void pushtag(int u, int xay) {
    lazy[u] += xay, maxx[u] += xay;
  }
  void pushdown(int u) {
    if (lazy[u]) {
      pushtag(ls, lazy[u]), pushtag(rs, lazy[u]);
      lazy[u] = 0;
    }
  }
  void build(int u, int l, int r) {
    if (l == r) {
      maxx[u] = (opt ? -l : l);
      return ;
    } 
    int mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    pushup(u);
  }
  void update(int u, int l, int r, int ql, int qr, int dlt) {
    if (qr < l || ql > r) return ;
    if (ql <= l && r <= qr) {
      pushtag(u, dlt);
      return ;
    }
    pushdown(u);
    int mid = l + r >> 1;
    update(ls, l, mid, ql, qr, dlt);
    update(rs, mid + 1, r, ql, qr, dlt);
    pushup(u);
  } 
  int query(int u, int l, int r, int ql, int qr) {
    if (ql > qr) return -inf;
    if (ql <= l && r <= qr) return maxx[u];
    pushdown(u);
    int mid = l + r >> 1, ret = -inf;
    if (ql <= mid) ret = max(ret, query(ls, l, mid, ql, qr));
    if (qr > mid) ret = max(ret, query(rs, mid + 1, r, ql, qr));
    return ret;
  }
} aL, aR, bL, bR;

/*
struct Bit {
  int c[N];
  void add(int x, int dlt) {
    while (x <= n) {
      c[x] += dlt;
      x += x & -x;
    }
  }
  int qry(int x) {
    int ret = 0;
    while (x) ret += c[x], x ^= x & -x;
    return ret;
  }
  int qry(int l, int r) {
    return qry(r) - qry(l - 1);
  }
} qaq;
*/

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    ans1[i] = ans2[i] = -50;
    zip[a[i]].pb(i);
  }
  aL.opt = 0, aL.build(1, 1, n);
  aR.opt = 1, aR.build(1, 1, n); 
  bL.opt = 1, bL.build(1, 1, n);
  bR.opt = 0, bR.build(1, 1, n);
  for (int val = n; val >= 1; val--) {
    // > x  a  
    //  max(a - len/2)
    for (auto i: zip[val]) {
      {
        int R = aR.query(1, 1, n, i, n) - aR.query(1, 1, n, i, i);
        int L = aL.query(1, 1, n, 1, i) - aL.query(1, 1, n, i, i);
//        L = max(L, 0), R = max(R, 0);
        ckmax(ans1[i], L + R - 1);
      }
      {
        int R = bR.query(1, 1, n, i, n) - bR.query(1, 1, n, i, i);
        int L = bL.query(1, 1, n, 1, i) - bL.query(1, 1, n, i, i);
//        L = max(L, 0), R = max(R, 0);
        ckmax(ans2[i], L + R - 1);
      }
    }
    for (auto i: zip[val]) {
      aL.update(1, 1, n, 1, i, 2);
      aR.update(1, 1, n, i, n, 2);
      bL.update(1, 1, n, 1, i, -2);
      bR.update(1, 1, n, i, n, -2);
//      qaq.add(i, 2);
    }
    // >= x  b 
    //  max(len/2 - b) 
    for (auto i: zip[val]) {
      {
        int R = bR.query(1, 1, n, i, n) - bR.query(1, 1, n, i, i);
        int L = bL.query(1, 1, n, 1, i) - bL.query(1, 1, n, i, i);
//        L = max(L, 0), R = max(R, 0);
        ckmax(ans2[i], L + R - 1);
      }
      {
        int R = aR.query(1, 1, n, i, n) - aR.query(1, 1, n, i, i);
        int L = aL.query(1, 1, n, 1, i) - aL.query(1, 1, n, i, i);
//        L = max(L, 0), R = max(R, 0);
        ckmax(ans1[i], L + R - 1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
//    printf("ans1[%d] = %d, ans2[%d] = %d\n", i, ans1[i], i, ans2[i]);
    int ans = max({(ans2[i] + 1) / 2, 1 + (int)floor(ans1[i] / 2.0), 0});
    print(ans, " \n"[i == n]);
  }
}