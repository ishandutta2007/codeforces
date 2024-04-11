#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
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
int t, n;
char a[200005], b[200005], c[200005];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    std::scanf("%d%s%s%s", &n, a, b, c);
    int pa = 0, pb = 0, pc = 0, p = 0;
    while (p < 3 * n) {
      int c0 = 0, c1 = 0;
      if (pa < 2 * n) a[pa] == '0' ? c0++ : c1++;
      if (pb < 2 * n) b[pb] == '0' ? c0++ : c1++;
      if (pc < 2 * n) c[pc] == '0' ? c0++ : c1++;
      if (c1 > c0) {
        std::printf("1");
        if (a[pa] == '1') pa++;
        if (b[pb] == '1') pb++;
        if (c[pc] == '1') pc++;
      } else {
        std::printf("0");
        if (a[pa] == '0') pa++;
        if (b[pb] == '0') pb++;
        if (c[pc] == '0') pc++;
      }
      p++;
      if (pa == 2 * n || pb == 2 * n || pc == 2 * n) break;
    }
    if (pa == 2 * n) {
      if (pb > pc)
        for (int i = pb; i < 2 * n; i++) std::printf("%c", b[i]);
      else
        for (int i = pc; i < 2 * n; i++) std::printf("%c", c[i]);
      std::printf("\n");
      continue;
    }
    if (pb == 2 * n) {
      if (pa > pc)
        for (int i = pa; i < 2 * n; i++) std::printf("%c", a[i]);
      else
        for (int i = pc; i < 2 * n; i++) std::printf("%c", c[i]);
      std::printf("\n");
      continue;
    }
    if (pc == 2 * n) {
      if (pa > pb)
        for (int i = pa; i < 2 * n; i++) std::printf("%c", a[i]);
      else
        for (int i = pb; i < 2 * n; i++) std::printf("%c", b[i]);
      std::printf("\n");
      continue;
    }
  }
  return 0;
}