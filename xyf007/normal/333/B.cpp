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
bool b1[1001], b2[1001];
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    Read(x, y);
    b1[x] = true;
    b2[y] = true;
  }
  int ans = 0;
  for (int i = 2; i <= n / 2; i++)
    ans += !b1[i] + !b1[n - i + 1] + !b2[i] + !b2[n - i + 1];
  if (n & 1) ans += !b1[(n + 1) >> 1] || !b2[(n + 1) >> 1];
  std::printf("%d", ans);
  return 0;
}