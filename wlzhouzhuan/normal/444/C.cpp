// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)

namespace IO {
  const int SIZE = 1 << 25;
  char buf[SIZE], *p1 = buf, *p2 = buf;
  char obuf[SIZE], *O = obuf;
  char getc() {
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++;
  }
  int read() {
    int x = 0, f = 0;
    char ch = getc();
    while (!isdigit(ch)) f |= ch == '-', ch = getc();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getc();
    return f ? -x : x;
  }
  template<typename T> void print(T x) {
    if (x < 0) *O++ = '-', x = -x;
    if (x > 9) print(x / 10);
    *O++ = char(x % 10 + '0');
  }
  template<typename T> void print(T x, char opt) {
    print(x), *O++ = opt;
  } 
  void Flush() {
    fwrite(obuf, O - obuf, 1, stdout);
  }
}
using namespace IO;

const int N = 100005;

int n, q;

struct Smt {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  ll sum[N << 2], lzy[N << 2];
  void pushtag(int u, int l, int r, ll dlt) {
    sum[u] += 1ll * (r - l + 1) * dlt;
    lzy[u] += dlt;
  }
  void pushdown(int u, int l, int r) {
    if (lzy[u]) {
      int mid = l + r >> 1;
      pushtag(ls, l, mid, lzy[u]), pushtag(rs, mid + 1, r, lzy[u]);
      lzy[u] = 0;
    }
  }
  void update(int u, int l, int r, int ql, int qr, ll dlt) {
    if (ql <= l && r <= qr) {
      pushtag(u, l, r, dlt);
      return ;
    }
    pushdown(u, l, r);
    int mid = l + r >> 1;
    if (ql <= mid) update(ls, l, mid, ql, qr, dlt);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, dlt);
    sum[u] = sum[ls] + sum[rs];
  }
  ll query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[u];
    pushdown(u, l, r);
    int mid = l + r >> 1;
    if (qr <= mid) return query(ls, l, mid, ql, qr);
    else if (ql > mid) return query(rs, mid + 1, r, ql, qr);
    else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
  }
} smt;

#define IT set<node>::iterator
struct node {
  int l, r;
  mutable int v;
  node (int _l = 0, int _r = -1, int _v = 0) {
    l = _l, r = _r, v = _v;
  }
  friend bool operator < (const node &x, const node &y) {
    if (x.l ^ y.l) return x.l < y.l;
    else return x.r < y.r;
  }
};
set<node> s;
IT split(int x) {
  IT it = s.lower_bound(node(x));
  if (it != s.end() && it->l == x) return it;
  it--;
  int l = it->l, r = it->r, v = it->v;
  s.erase(it), s.insert(node(l, x - 1, v));
  return s.insert(node(x, r, v)).first;
}
void assign(int l, int r, int x) {
  IT itr = split(r + 1), itl = split(l);
  for (IT it = itl; it != itr; it++) {
    int l = it->l, r = it->r, v = it->v;
    smt.update(1, 1, n, l, r, abs(v - x));
  }
  s.erase(itl, itr);
  s.insert(node(l, r, x));
}

int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) s.insert(node(i, i, i)); 
  while (q--) {
    int opt = read(), l = read(), r = read(), x;
    if (opt == 1) {
      x = read();
      assign(l, r, x);
    } else {
      printf("%lld\n", smt.query(1, 1, n, l, r));
    }
  }
  return 0;
}