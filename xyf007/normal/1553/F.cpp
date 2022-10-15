#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
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
void Read(T &x, Args &... args) {
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
int n, m = 300000;
long long a[200001], f[200001], g[200001];
class FenwickTree {
 public:
  FenwickTree() {}
  void Init(int n) { n_ = n; }
  void Add(int x, int v) {
    while (x <= n_) {
      t_[x] += v;
      x += x & -x;
    }
  }
  long long Query(int x) {
    checkmin(x, m);
    long long s = 0LL;
    while (x) {
      s += t_[x];
      x -= x & -x;
    }
    return s;
  }
  ~FenwickTree() {}

 private:
  int n_;
  long long t_[400001];
} T1, T2;
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  T1.Init(m), T2.Init(m);
  long long pre = 0LL;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] + (i - 1) * a[i] - T1.Query(a[i]);
    for (int j = a[i]; j <= m; j += a[i]) T1.Add(j, a[i]);
    g[i] = g[i - 1] + pre;
    int cnt = 0;
    for (int j = a[i]; j <= m; j += a[i])
      g[i] -= (T2.Query(j + a[i] - 1) - T2.Query(j - 1)) * a[i] * ++cnt;
    T2.Add(a[i], 1);
    pre += a[i];
  }
  for (int i = 1; i <= n; i++) std::printf("%lld ", f[i] + g[i]);
  return 0;
}