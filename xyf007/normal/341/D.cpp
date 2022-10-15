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
int n, m;
long long t[2][2][1001][1001];
void Add(int x, int y, long long v) {
  for (int i = x; i <= n; i += i & -i)
    for (int j = y; j <= n; j += j & -j) t[x & 1][y & 1][i][j] ^= v;
}
long long Query(int x, int y) {
  long long s = 0LL;
  for (int i = x; i; i -= i & -i)
    for (int j = y; j; j -= j & -j) s ^= t[x & 1][y & 1][i][j];
  return s;
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= m; i++) {
    int op, x1, y1, x2, y2;
    Read(op, x1, y1, x2, y2);
    if (op == 1) {
      std::printf("%lld\n", Query(x2, y2) ^ Query(x1 - 1, y2) ^
                                Query(x2, y1 - 1) ^ Query(x1 - 1, y1 - 1));
    } else {
      int v;
      Read(v);
      Add(x1, y1, v);
      Add(x1, y2 + 1, v);
      Add(x2 + 1, y1, v);
      Add(x2 + 1, y2 + 1, v);
    }
  }
  return 0;
}