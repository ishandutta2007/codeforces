#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr int kMod = 1e9 + 9;
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) {
      return EOF;
    }
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9') {
    if (c == '-') {
      f = -1;
    }
  }
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') {
    x = x * 10 + c - '0';
  }
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) {
    x = y;
  }
}
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
int n, h, dp[1001][31][31][31][2];
int main(int argc, char const *argv[]) {
  Read(n, h);
  dp[1][1][1][1][1] = 4;
  for (int i = 1; i <= n; i++) {
    for (int a = 1; a <= h; a++) {
      for (int b = 1; b <= h; b++) {
        for (int c = 1; c <= h; c++) {
          for (int d = 0; d <= 1; d++) {
            if (!dp[i][a][b][c][d]) {
              continue;
            }
            int na = std::min(a + 1, h), nb = std::min(b + 1, h),
                nc = std::min(c + 1, h), nd = d ? 1 : h;
            Add(dp[i + 1][na][nb][nc][d], dp[i][a][b][c][d]);
            Add(dp[i + 1][nd][nb][nc][a < h], dp[i][a][b][c][d]);
            Add(dp[i + 1][na][nd][nc][b < h], dp[i][a][b][c][d]);
            Add(dp[i + 1][na][nb][nd][c < h], dp[i][a][b][c][d]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int a = 1; a <= h; a++) {
    for (int b = 1; b <= h; b++) {
      for (int c = 1; c <= h; c++) {
        for (int d = 0; d <= 1; d++) {
          if (d || a < h || b < h || c < h) {
            Add(ans, dp[n][a][b][c][d]);
          }
        }
      }
    }
  }
  std::printf("%d", ans);
  return 0;
}