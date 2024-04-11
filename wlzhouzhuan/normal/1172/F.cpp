// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mset(s, t) memset(s, t, sizeof(s))
#define pb push_back

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

const int N = 1000005;
const ll inf = 1e18;

int a[N], n, q, p;

#define ls (u << 1)
#define rs (u << 1 | 1)
ll sum[N << 2];
vector<ll> c[N << 2];
inline void pushup(int u) {
  sum[u] = sum[ls] + sum[rs];
  int len1 = c[ls].size() - 1, len2 = c[rs].size() - 1;
  for (int x = 0, y = 0; x < len1; x++) {
    if (y > len2) y--;
    for (; y <= len2; y++) {
      ll cur = max(c[ls][x], c[rs][y] - (sum[ls] - 1ll * x * p));
      ll qaq = c[ls][x + 1] - 1 + (sum[ls] - 1ll * x * p);
      if (qaq < c[rs][y]) {
        if (y) y--;
        break;
      }
      c[u][x + y] = min(c[u][x + y], cur);
    }  
  }
}
void build(int u, int l, int r) {
  c[u].resize(r - l + 3);
  for (int i = 1; i <= r - l + 2; i++) c[u][i] = inf;
  c[u][0] = -inf;
  if (l == r) {
    sum[u] = a[l], c[u][1] = p - a[l];
    return ; 
  }
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(u);
}
ll query(int u, int l, int r, int ql, int qr, ll x) {
  if (ql <= l && r <= qr) {
    int id = upper_bound(c[u].begin(), c[u].end(), x) - c[u].begin() - 1;
    return x + sum[u] - 1ll * id * p;
  }
  int mid = l + r >> 1;
  if (qr <= mid) return query(ls, l, mid, ql, qr, x);
  if (ql > mid) return query(rs, mid + 1, r, ql, qr, x);
  return query(rs, mid + 1, r, ql, qr, query(ls, l, mid, ql, qr, x));
}

int main() {
  n = read(), q = read(), p = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  build(1, 1, n);
  while (q--) {
    int l = read(), r = read();
    print(query(1, 1, n, l, r, 0ll), '\n');
  }    
  Flush();
  return 0;
} 

/*
10 1 2
1 1 -1 -5 3 4 -1 -3 3 -4 
5 8
*/