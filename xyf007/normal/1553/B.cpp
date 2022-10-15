#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
char a[2001], b[2001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    scanf("%s%s", a + 1, b + 1);
    n = strlen(a + 1), m = strlen(b + 1);
    bool f = false;
    for (int i = 1; i <= n; i++)
      for (int j = i; j <= n; j++) {
        if (a[j] != b[j - i + 1] || j - i + 1 > m) break;
        if (2 * j - i >= m && j - i + 1 == m) {
          f = true;
          break;
        }
        if (f) break;
        for (int k = j - 1; k >= 1; k--) {
          if (a[k] != b[j - i + 1 + j - k]) break;
          if (j - i + 1 + j - k == m) {
            f = true;
            break;
          }
        }
        if (f) break;
      }
    if (f)
      std::printf("YES\n");
    else
      std::printf("NO\n");
  }
  return 0;
}