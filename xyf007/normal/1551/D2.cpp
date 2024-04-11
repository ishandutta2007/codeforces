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
int t, n, m, k;
char ans[105][105];
auto col = [](int x, int y) {
  return (((x + 1) >> 1) & 1) << 1 | (((y + 1) >> 1) & 1);
};
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, m, k);
    if (n & 1) {
      k -= m >> 1;
      if (k < 0 || k & 1) {
        std::printf("NO\n");
        continue;
      }
      for (int i = 1; i <= m; i++) ans[1][i] = (((i + 1) / 2) & 1) ? 'z' : 'y';
      for (int i = 2; i <= n; i += 2)
        for (int j = 1; j <= m; j += 2) {
          if (k) {
            k -= 2;
            ans[i][j] = ans[i][j + 1] = 'a' + col(i, j);
            ans[i + 1][j] = ans[i + 1][j + 1] = 'e' + col(i, j);
          } else {
            ans[i][j] = ans[i + 1][j] = 'i' + col(i, j);
            ans[i][j + 1] = ans[i + 1][j + 1] = 'm' + col(i, j);
          }
        }
      std::printf("YES\n");
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) std::printf("%c", ans[i][j]);
        std::printf("\n");
      }
    } else if (m & 1) {
      int kk = n * m / 2 - k - n / 2;
      if (kk < 0 || kk & 1) {
        std::printf("NO\n");
        continue;
      }
      for (int i = 1; i <= n; i++) ans[i][1] = (((i + 1) / 2) & 1) ? 'z' : 'y';
      for (int i = 1; i <= n; i += 2)
        for (int j = 2; j <= m; j += 2) {
          if (kk) {
            kk -= 2;
            ans[i][j] = ans[i + 1][j] = 'a' + col(i, j);
            ans[i][j + 1] = ans[i + 1][j + 1] = 'e' + col(i, j);
          } else {
            ans[i][j] = ans[i][j + 1] = 'i' + col(i, j);
            ans[i + 1][j] = ans[i + 1][j + 1] = 'm' + col(i, j);
          }
        }
      std::printf("YES\n");
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) std::printf("%c", ans[i][j]);
        std::printf("\n");
      }
    } else {
      if (k & 1) {
        std::printf("NO\n");
        continue;
      }
      for (int i = 1; i <= n; i += 2)
        for (int j = 1; j <= m; j += 2) {
          if (k) {
            k--, k--;
            ans[i][j] = ans[i][j + 1] = 'a' + col(i, j);
            ans[i + 1][j] = ans[i + 1][j + 1] = 'e' + col(i, j);
          } else {
            ans[i][j] = ans[i + 1][j] = 'i' + col(i, j);
            ans[i][j + 1] = ans[i + 1][j + 1] = 'm' + col(i, j);
          }
        }
      std::printf("YES\n");
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) std::printf("%c", ans[i][j]);
        std::printf("\n");
      }
    }
  }
  return 0;
}