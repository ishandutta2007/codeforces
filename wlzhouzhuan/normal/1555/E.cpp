// Author: wlzhouzhuan
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

const int N = 1000005;
struct node {
  int l, r, w;
} a[N];
int n, m;

#define ls (u << 1)
#define rs (u << 1 | 1)
int lazy[N << 2], minn[N << 2];
void pushup(int u) {
  minn[u] = min(minn[ls], minn[rs]);
}
void pushtag(int u, int dlt) {
  lazy[u] += dlt, minn[u] += dlt; 
} 
void pushdown(int u) {
  if (lazy[u]) {
    pushtag(ls, lazy[u]), pushtag(rs, lazy[u]);
    lazy[u] = 0;
  }
}
void add(int u, int l, int r, int ql, int qr, int dlt) {
  if (ql <= l && r <= qr) {
    pushtag(u, dlt);
    return ;
  }
  pushdown(u);
  int mid = l + r >> 1;
  if (ql <= mid) add(ls, l, mid, ql, qr, dlt);
  if (qr > mid) add(rs, mid + 1, r, ql, qr, dlt);
  pushup(u);
}

int main() {
  n = read(), m = read() - 1;
  for (int i = 1; i <= n; i++) {
    a[i].l = read(), a[i].r = read() - 1;
    a[i].w = read();
  }
  sort(a + 1, a + n + 1, [&](node x, node y) {
    return x.w < y.w;
  });
  int ans = 2e9;
  for (int i = 1, j = 1; i <= n; i++) {
    if (i > 1) add(1, 1, m, a[i - 1].l, a[i - 1].r, -1);
    while (j <= n && !minn[1]) {
      add(1, 1, m, a[j].l, a[j].r, 1);
      ++j;
    }
    if (!minn[1]) break;
    ans = min(ans, a[j - 1].w - a[i].w);
  }
  print(ans, '\n');
}