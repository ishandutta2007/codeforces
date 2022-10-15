#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
char rbuf[1 << 20], *ps, *pt, wbuf[1 << 20], *po = wbuf;
char Getchar() {
  if (ps == pt) {
    pt = (ps = rbuf) + std::fread(rbuf, 1, 1 << 20, stdin);
    if (ps == pt) return EOF;
  }
  return *ps++;
}
template <typename T = int>
T Read() {
  T x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  return x * f;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
void Read(char &c) { c = Getchar(); }
void Read(char *s) {
  char c = Getchar();
  while (c <= 32) c = Getchar();
  while (c > 32) *s++ = c, c = Getchar();
  *s = '\0';
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x), Read(args...);
}
void Putchar(const char &c) {
  if (po - wbuf == 1 << 20) std::fwrite(wbuf, po - wbuf, 1, stdout), po = wbuf;
  *po++ = c;
}
template <typename T>
void Write(const T &x) {
  if (x < 0) {
    Putchar('-'), Write(-x);
    return;
  }
  if (x > 9) Write(x / 10);
  Putchar(x % 10 + '0');
}
void Write(const char c) { Putchar(c); }
void Write(const char *s) {
  while (*s != '\0') Putchar(*s++);
}
template <typename T, typename... Args>
void Write(const T &x, const Args &...args) {
  Write(x), Write(args...);
}
class AutoFlusher {
 public:
  AutoFlusher() {}
  ~AutoFlusher() { std::fwrite(wbuf, po - wbuf, 1, stdout); }
} autoflusher;
struct Node {
  int ls, rs, min;
  Node() { ls = rs = 0, min = 0x3f3f3f3f; }
} t[10000001];
int n, q, tot = 1;
long long g, r, m, l[200005], d[200005], f[200005], sl[200005];
void Pushup(int x) { t[x].min = std::min(t[t[x].ls].min, t[t[x].rs].min); }
void Modify(long long l, long long r, long long p, int v, int x) {
  if (l == r) {
    t[x].min = v;
    return;
  }
  long long mid = (l + r) >> 1;
  if (p <= mid) {
    if (!t[x].ls) t[x].ls = ++tot;
    Modify(l, mid, p, v, t[x].ls);
  } else {
    if (!t[x].rs) t[x].rs = ++tot;
    Modify(mid + 1, r, p, v, t[x].rs);
  }
  Pushup(x);
}
int Query(long long L, long long R, long long l, long long r, int x) {
  if (L <= l && r <= R) return t[x].min;
  if (!x) return 0x3f3f3f3f;
  long long mid = (l + r) >> 1;
  if (R <= mid) return Query(L, R, l, mid, t[x].ls);
  if (L > mid) return Query(L, R, mid + 1, r, t[x].rs);
  return std::min(Query(L, R, l, mid, t[x].ls),
                  Query(L, R, mid + 1, r, t[x].rs));
}
void Init() {
  for (int i = 1; i <= n + 1; i++) d[i] = (d[i - 1] + l[i]) % m;
  std::partial_sum(l + 1, l + n + 2, sl + 1);
  for (int i = n; i >= 1; i--) {
    long long l = (g + d[i]) % m, r = (m - 1 + d[i]) % m, p;
    if (l <= r)
      p = Query(l, r, 0, m - 1, 1);
    else
      p = std::min(Query(l, m - 1, 0, m - 1, 1), Query(0, r, 0, m - 1, 1));
    if (p > n) {
      f[i] = sl[n + 1] - sl[i];
    } else {
      long long arrt = (d[p] - d[i] + m) % m, waitt = m - arrt;
      f[i] = f[p] + sl[p] - sl[i] + waitt;
    }
    Modify(0LL, m - 1, d[i], i, 1);
  }
}
long long Solve(long long t) {
  long long ans = t, st = t % m, l = (g - st + m) % m, r = (m - 1 - st) % m, p;
  if (l <= r)
    p = Query(l, r, 0LL, m - 1, 1);
  else
    p = std::min(Query(l, m - 1, 0LL, m - 1, 1), Query(0LL, r, 0LL, m - 1, 1));
  if (p > n) {
    ans += sl[n + 1];
  } else {
    long long arrt = (d[p] + st + m) % m, waitt = m - arrt;
    ans += f[p] + sl[p] + waitt;
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  Read(n, g, r), m = g + r;
  for (int i = 1; i <= n + 1; i++) Read(l[i]);
  Init();
  Read(q);
  while (q--) Write(Solve(Read()), '\n');
  return 0;
}