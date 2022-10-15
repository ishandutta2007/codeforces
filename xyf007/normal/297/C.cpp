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
struct Node {
  int v, id;
} s[100001];
int n, a[100001], b[100001], ansa[100001], ansb[100001];
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) {
    Read(s[i].v);
    s[i].id = i;
  }
  std::sort(s + 1, s + n + 1, [](const Node &lhs, const Node &rhs) -> bool {
    return lhs.v < rhs.v;
  });
  int t = (n + 2) / 3;
  for (int i = 1; i <= t; i++) b[i] = s[i].v - (a[i] = i - 1);
  for (int i = t + 1; i <= n - t; i++) a[i] = s[i].v - (b[i] = i - 1);
  for (int i = n; i >= n - t + 1; i--) a[i] = s[i].v - (b[i] = n - i);
  for (int i = 1; i <= n; i++) {
    ansa[s[i].id] = a[i];
    ansb[s[i].id] = b[i];
  }
  std::printf("YES\n");
  for (int i = 1; i <= n; i++) std::printf("%d%c", ansa[i], " \n"[i == n]);
  for (int i = 1; i <= n; i++) std::printf("%d%c", ansb[i], " \n"[i == n]);
  return 0;
}