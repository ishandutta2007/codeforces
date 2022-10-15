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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
int n, m, h, a[150001], b[150001], min[600001], tag[600001];
void Pushup(int x) { min[x] = std::min(min[x + x], min[x + x + 1]); }
void Pushdown(int x) {
  if (tag[x]) {
    min[x + x] += tag[x];
    min[x + x + 1] += tag[x];
    tag[x + x] += tag[x];
    tag[x + x + 1] += tag[x];
    tag[x] = 0;
  }
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L > R) return;
  if (L <= l && r <= R) {
    min[x] += v;
    tag[x] += v;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, v, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, v, x + x + 1);
  Pushup(x);
}
int main(int argc, char const *argv[]) {
  Read(n, m, h);
  for (int i = 1; i <= m; i++) Read(b[i]);
  std::sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++) {
    Read(a[i]);
    a[i] = std::lower_bound(b + 1, b + m + 1, h - a[i]) - b;
  }
  for (int i = 1; i <= m; i++) Modify(i, i, 1, m, -i, 1);
  for (int i = 1; i < m; i++) Modify(a[i], m, 1, m, 1, 1);
  int ans = 0;
  for (int i = m; i <= n; i++) {
    Modify(a[i], m, 1, m, 1, 1);
    ans += min[1] >= 0;
    Modify(a[i - m + 1], m, 1, m, -1, 1);
  }
  std::printf("%d", ans);
  return 0;
}