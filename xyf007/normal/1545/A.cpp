#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
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
int t, n, a[100001], b[100001], sum[100001][2];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n);
    for (int i = 1; i <= n; i++) Read(a[i]);
    std::memcpy(b + 1, a + 1, 4 * n);
    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) sum[a[i]][i & 1]++;
    for (int i = 1; i <= n; i++) sum[b[i]][i & 1]--;
    bool f = true;
    for (int i = 1; i <= n; i++)
      if (sum[a[i]][0] || sum[a[i]][1]) {
        f = false;
        break;
      }
    if (f)
      std::printf("YES\n");
    else
      std::printf("NO\n");
    for (int i = 1; i <= n; i++) sum[a[i]][0] = sum[a[i]][1] = 0;
  }
  return 0;
}