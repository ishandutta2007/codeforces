#include <bits/stdc++.h>
using namespace std;

namespace IO {
  const int SIZE = 1 << 21;
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
struct Q {
  int opt, l, r, x;
} q[500005];
int a[N], L[1005], R[1005], block;
int rt[100003], siz[100003], fa[N], to[N]; 
int ans[N], n, m, B;

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
} 
inline void merge(int x, int y) {
  if (rt[y]) fa[rt[x]] = rt[y];
  else rt[y] = rt[x], to[rt[y]] = y;
  siz[y] += siz[x], siz[x] = rt[x] = 0;
}
int maxx, tag;
inline void build(int x) { 
  maxx = tag = 0;
  for (register int i = L[x]; i <= R[x]; i++) {
    maxx = max(maxx, a[i]);
    if (rt[a[i]]) fa[i] = rt[a[i]];
    else rt[a[i]] = fa[i] = i, to[i] = a[i];
    siz[a[i]]++;
  }
}
inline void rebuild(int x, int id) {
  for (register int i = L[x]; i <= R[x]; i++) {
    a[i] = to[find(i)], rt[a[i]] = siz[a[i]] = 0;
    a[i] -= tag;
  }
  for (register int i = L[x]; i <= R[x]; i++) to[i] = 0;
  int l = max(q[id].l, L[x]), r = min(q[id].r, R[x]);
  for (register int i = l; i <= r; i++) {
    if (a[i] > q[id].x) a[i] -= q[id].x;
  }
  build(x);
}
inline void modify(int x) {
  if (maxx - tag >= 2 * x) {
    for (register int i = tag + 1; i <= tag + x; i++) {
      if (rt[i]) merge(i, i + x);
    }
    tag += x;
  } else {
    for (register int i = tag + x + 1; i <= maxx; i++) {
      if (rt[i]) merge(i, i - x);
    }
    if (tag + x <= maxx) maxx = tag + x;
  }
}
inline void query(int x, int id) {
  int l = q[id].l, r = q[id].r, qwq = q[id].x;
  if (qwq + tag > 100001) return ;
  if (l <= L[x] && R[x] <= r) ans[id] += siz[qwq + tag];
  else {
    l = max(l, L[x]), r = min(r, R[x]);
    for (register int j = l; j <= r; j++) {
      if (to[find(j)] - tag == qwq) ans[id]++;
    }
  }
}
int main() {
  n = read(), m = read(), B = sqrt(n);
  for (register int i = 1; i <= n; i++) a[i] = read();
  for (register int l = 1, r = B; l <= n; l += B, r += B) {
    r = min(r, n);
    block++, L[block] = l, R[block] = r;
  }
  for (register int i = 1; i <= m; i++) {
    q[i].opt = read(), q[i].l = read(), q[i].r = read(), q[i].x = read();
  }
  for (register int i = 1; i <= block; i++) {
    memset(rt, 0, sizeof(rt));
    memset(siz, 0, sizeof(siz));
    build(i);
    for (register int j = 1; j <= m; j++) {
      if (R[i] < q[j].l || q[j].r < L[i]) continue;
      if (q[j].opt == 1) {
        if (q[j].l <= L[i] && R[i] <= q[j].r) modify(q[j].x);
        else rebuild(i, j);
      }
      else query(i, j);
    }
  }
  for (register int i = 1; i <= m; i++) {
    if (q[i].opt == 2) print(ans[i], '\n');
  }
  Flush();
  return 0;
}