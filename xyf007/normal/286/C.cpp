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
int n, m, a[1000001], s[1000001], top;
bool vis[1000001];
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) {
    Read(a[i]);
  }
  Read(m);
  for (int i = 1; i <= m; i++) {
    int x;
    Read(x);
    vis[x] = true;
  }
  for (int i = n; i >= 1; i--)
    if (vis[i]) {
      s[++top] = a[i];
      a[i] = -a[i];
    } else {
      if (top && a[i] == s[top]) {
        top--;
      } else {
        s[++top] = a[i];
        a[i] = -a[i];
      }
    }
  if (top) {
    std::printf("NO");
    return 0;
  }
  std::printf("YES\n");
  for (int i = 1; i <= n; i++) std::printf("%d ", a[i]);
  return 0;
}