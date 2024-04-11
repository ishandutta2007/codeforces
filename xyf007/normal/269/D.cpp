#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Panel {
  int h, l, r;
} a[100005];
int n, h, nn, b[200005], max[800001], tag[800001], dp[100005];
void Pushup(int x) { max[x] = std::max(max[x + x], max[x + x + 1]); }
void Pushdown(int x) {
  if (tag[x]) {
    max[x + x] = max[x + x + 1] = tag[x + x] = tag[x + x + 1] = tag[x];
    tag[x] = 0;
  }
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    max[x] = tag[x] = v;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, v, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, v, x + x + 1);
  Pushup(x);
}
int Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return max[x];
  Pushdown(x);
  int mid = (l + r) >> 1, ans = 0;
  if (L <= mid) checkmax(ans, Query(L, R, l, mid, x + x));
  if (R > mid) checkmax(ans, Query(L, R, mid + 1, r, x + x + 1));
  return ans;
}
void Solve(int L, int R, int p, bool cl, bool cr) {
  if (L > R) return;
  int id = Query(L, R, 1, nn, 1);
  if (!id) {
    dp[p] = b[R + 1] - b[L];
    return;
  }
  int nl = a[id].l, nr = a[id].r;
  if ((nl >= L || cl) && (nr <= R || cr))
    checkmax(dp[p],
             std::min(dp[id], b[std::min(R, nr) + 1] - b[std::max(L, nl)]));
  if (L < nl) Solve(L, nl - 1, p, cl, false);
  if (R > nr) Solve(nr + 1, R, p, false, cr);
}
int main(int argc, char const *argv[]) {
  Read(n, h);
  for (int i = 1; i <= n; i++) {
    Read(a[i].h, a[i].l, a[i].r);
    b[2 * i - 1] = a[i].l;
    b[2 * i] = a[i].r;
  }
  b[2 * n + 1] = -1000000005;
  b[2 * n + 2] = 1000000005;
  std::sort(b + 1, b + 2 * n + 3);
  nn = std::unique(b + 1, b + 2 * n + 3) - b - 1;
  a[++n] = {h, -1000000005, 1000000005};
  a[++n] = {0, -1000000005, 1000000005};
  std::sort(a + 1, a + n + 1, [](const Panel &lhs, const Panel &rhs) -> bool {
    return lhs.h < rhs.h;
  });
  for (int i = 1; i <= n; i++) {
    a[i].l = std::lower_bound(b + 1, b + nn + 1, a[i].l) - b;
    a[i].r = std::lower_bound(b + 1, b + nn + 1, a[i].r) - b - 1;
  }
  for (int i = 1; i <= n; i++) {
    Solve(a[i].l, a[i].r, i, true, true);
    Modify(a[i].l, a[i].r, 1, nn, i, 1);
  }
  std::printf("%d", dp[n]);
  return 0;
}