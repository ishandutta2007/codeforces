#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
#include <algorithm>
#include <iostream>
#include <utility>
constexpr int kB = 1 << 20;
char rbuf[kB + 1], *ps = rbuf + kB, wbuf[kB + 1], *po = wbuf;
char Getchar() {
  if (ps - rbuf == kB) {
    if (std::cin.read(rbuf, kB).rdstate() == std::ios_base::eofbit) return EOF;
    ps = rbuf;
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
  if (po - wbuf == kB) std::cout.write(wbuf, kB), po = wbuf;
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
  ~AutoFlusher() { std::cout.write(wbuf, po - wbuf); }
} autoflusher;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, pre[300001], nxt[300001], s[300001], top;
long long x[300001], a[300001], ans[300001];
std::vector<std::pair<int, long long>> c[300001];
std::vector<std::pair<int, int>> b[300001];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n) { Clear(); }
  void Init(int n) { n_ = n, Clear(); }
  void Add(int x, const T &v) {
    while (x) checkmin(t_[x], v), x -= x & -x;
  }
  T Query(int x) {
    T s(0x3f3f3f3f3f3f3f3fLL);
    while (x <= n_) checkmin(s, t_[x]), x += x & -x;
    return s;
  }
  void Clear() { std::fill(t_, t_ + n_ + 1, 0x3f3f3f3f3f3f3f3fLL); }
  ~FenwickTree() {}

 private:
  int n_;
  T t_[300001];
};
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Read(n, m);
  for (int i = 1; i <= n; i++) Read(x[i], a[i]);
  for (int i = 1; i <= n; i++) {
    while (top && a[s[top]] > a[i]) top--;
    pre[i] = s[top];
    s[++top] = i;
  }
  top = 0;
  for (int i = n; i >= 1; i--) {
    while (top && a[s[top]] > a[i]) top--;
    nxt[i] = s[top];
    s[++top] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (pre[i])
      c[i].emplace_back(pre[i], (x[i] - x[pre[i]]) * (a[i] + a[pre[i]]));
    if (nxt[i])
      c[nxt[i]].emplace_back(i, (x[nxt[i]] - x[i]) * (a[nxt[i]] + a[i]));
  }
  for (int i = 1; i <= m; i++) {
    int l = Read(), r = Read();
    b[r].emplace_back(l, i);
  }
  FenwickTree<long long> bit(n);
  for (int i = 1; i <= n; i++) {
    for (const auto &[l, w] : c[i]) bit.Add(l, w);
    for (const auto &[l, id] : b[i]) ans[id] = bit.Query(l);
  }
  for (int i = 1; i <= m; i++) std::cout << ans[i] << '\n';
  return 0;
}