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
int n, a[200001];
long long f[200001][2];
bool v1[200001][2], v2[200001][2];
long long Dfs(int x, int op) {
  if (x < 1 || x > n) return 0LL;
  if (v1[x][op]) return v2[x][op] ? f[x][op] : -1LL;
  v1[x][op] = true;
  long long s = Dfs(x + (op ? -a[x] : a[x]), !op);
  v2[x][op] = true;
  return f[x][op] = ~s ? s + a[x] : -1LL;
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 2; i <= n; i++) Read(a[i]);
  for (int i = 1; i < n; i++) {
    a[1] = i;
    if (~Dfs(a[1] + 1, 1))
      std::printf("%lld\n", f[a[1] + 1][1] + a[1]);
    else
      std::printf("-1\n");
  }
  return 0;
}