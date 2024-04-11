#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr int kMod = 95542721;
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
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
int n, m, a[100001], sum[400001][48], tag[400001];
void Pushup(int x) {
  for (int i = 0; i < 48; i++)
    sum[x][i] = add(sum[x + x][i], sum[x + x + 1][i]);
}
void Pushdown(int x) {
  if (tag[x]) {
    std::rotate(sum[x + x], sum[x + x] + tag[x], sum[x + x] + 48);
    std::rotate(sum[x + x + 1], sum[x + x + 1] + tag[x], sum[x + x + 1] + 48);
    tag[x + x] = (tag[x + x] + tag[x]) % 48;
    tag[x + x + 1] = (tag[x + x + 1] + tag[x]) % 48;
    tag[x] = 0;
  }
}
void Build(int l, int r, int x) {
  if (l == r) {
    sum[x][0] = a[l];
    for (int i = 1; i < 48; i++)
      sum[x][i] = mul(sum[x][i - 1], sum[x][i - 1], sum[x][i - 1]);
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x);
  Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) {
    std::rotate(sum[x], sum[x] + 1, sum[x] + 48);
    tag[x] = (tag[x] + 1) % 48;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, x + x + 1);
  Pushup(x);
}
int Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return sum[x][0];
  Pushdown(x);
  int mid = (l + r) >> 1, ans = 0;
  if (L <= mid) Add(ans, Query(L, R, l, mid, x + x));
  if (R > mid) Add(ans, Query(L, R, mid + 1, r, x + x + 1));
  return ans;
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  Build(1, n, 1);
  Read(m);
  for (int i = 1; i <= m; i++) {
    int op, l, r;
    Read(op, l, r);
    if (op == 2)
      Modify(l, r, 1, n, 1);
    else
      std::printf("%d\n", Query(l, r, 1, n, 1));
  }
  return 0;
}