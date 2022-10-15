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
char a[100001], b[100001];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    std::scanf("%s%s", a + 1, b + 1);
    n = std::strlen(a + 1), m = std::strlen(b + 1);
    int p1 = n, p2 = m;
    bool f = true;
    while (p2 > 0) {
      while (p1 > 0 && a[p1] != b[p2]) p1 -= 2;
      if (p1 <= 0) {
        f = false;
        break;
      }
      p1--, p2--;
    }
    if (f)
      std::printf("YES\n");
    else
      std::printf("NO\n");
  }
  return 0;
}