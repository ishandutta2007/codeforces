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
int t;
char s[101];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    std::scanf("%s", s + 1);
    int c1 = 0, c2 = 0, ans = 10;
    for (int i = 1; i <= 10; i++)
      if (i & 1) {
        if (s[i] != '0') c1++;
        if (c2 + (11 - i) / 2 < c1) {
          checkmin(ans, i);
          break;
        }
        if (c1 + (10 - i) / 2 < c2) {
          checkmin(ans, i);
          break;
        }
      } else {
        if (s[i] == '1') c2++;
        if (c2 + (10 - i) / 2 < c1) {
          checkmin(ans, i);
          break;
        }
        if (c1 + (10 - i) / 2 < c2) {
          checkmin(ans, i);
          break;
        }
      }
    c1 = c2 = 0;
    for (int i = 1; i <= 10; i++)
      if (i & 1) {
        if (s[i] == '1') c1++;
        if (c2 + (11 - i) / 2 < c1) {
          checkmin(ans, i);
          break;
        }
        if (c1 + (10 - i) / 2 < c2) {
          checkmin(ans, i);
          break;
        }
      } else {
        if (s[i] != '0') c2++;
        if (c2 + (10 - i) / 2 < c1) {
          checkmin(ans, i);
          break;
        }
        if (c1 + (10 - i) / 2 < c2) {
          checkmin(ans, i);
          break;
        }
      }
    std::printf("%d\n", ans);
  }
  return 0;
}