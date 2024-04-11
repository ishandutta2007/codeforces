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
int n, a[2000001];
int main(int argc, char const *argv[]) {
  Read(n);
  std::iota(a + 1, a + n + 1, 1);
  int t;
  for (int i = 2; i <= n; i++) {
    t = 0;
    for (int j = i - 1; j < i + n - 1; j += i) std::swap(t, a[j]);
    a[i + n - 1] = t;
  }
  for (int i = n; i < 2 * n; i++) std::printf("%d ", a[i]);
  return 0;
}