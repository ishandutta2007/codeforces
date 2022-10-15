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
int t, n, m;
int ans[31][31];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, m);
    std::memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (i == 1 || i == n || j == 1 || j == m)
          if (ans[i][j] == -1) {
            ans[i][j] = 1;
            ans[i - 1][j] = ans[i][j - 1] = ans[i + 1][j] = ans[i][j + 1] =
                ans[i - 1][j - 1] = ans[i - 1][j + 1] = ans[i + 1][j - 1] =
                    ans[i + 1][j + 1] = 0;
          }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) std::printf("%d", ans[i][j] == 1 ? 1 : 0);
      std::printf("\n");
    }
    std::printf("\n");
  }
  return 0;
}