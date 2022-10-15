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
int n, m, a[34][34], b[34][34], ans = 0x80000000;
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) Read(a[i][j]);
  m = (n + 1) >> 1;
  for (int S = 0; S < (1 << m); S++) {
    std::memset(b, 0, sizeof(b));
    int sum = 0;
    for (int i = 0; i < m; i++) b[m - 1][i] = (S >> i) & 1;
    for (int i = 0; i < m - 1; i++)
      b[m - 1][i + m] = b[m - 1][i] ^ b[m - 1][m - 1];
    for (int i = 0; i < n; i++) sum += b[m - 1][i] ? -a[m - 1][i] : a[m - 1][i];
    for (int i = 0; i < m - 1; i++) {
      int max = 0x80000000;
      for (b[i][m - 1] = 0; b[i][m - 1] < 2; b[i][m - 1]++) {
        int s = 0;
        for (int j = 0; j < m - 1; j++) {
          int tmp = 0x80000000;
          for (b[i][j] = 0; b[i][j] < 2; b[i][j]++) {
            b[i][j + m] = b[i][j] ^ b[i][m - 1];
            b[i + m][j] = b[i][j] ^ b[m - 1][j];
            b[i + m][j + m] = b[i][j + m] ^ b[m - 1][j + m];
            checkmax(tmp, (b[i][j] ? -a[i][j] : a[i][j]) +
                              (b[i][j + m] ? -a[i][j + m] : a[i][j + m]) +
                              (b[i + m][j] ? -a[i + m][j] : a[i + m][j]) +
                              (b[i + m][j + m] ? -a[i + m][j + m]
                                               : a[i + m][j + m]));
          }
          s += tmp;
        }
        b[i + m][m - 1] = b[i][m - 1] ^ b[m - 1][m - 1];
        checkmax(max,
                 s + (b[i][m - 1] ? -a[i][m - 1] : a[i][m - 1]) +
                     (b[i + m][m - 1] ? -a[i + m][m - 1] : a[i + m][m - 1]));
      }
      sum += max;
    }
    checkmax(ans, sum);
  }
  std::printf("%d", ans);
  return 0;
}