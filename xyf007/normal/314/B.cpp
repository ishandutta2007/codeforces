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
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
int a, b, cnt[101];
std::size_t n, m, nxt[101];
char s[101], t[101];
int main(int argc, char const *argv[]) {
  Read(a, b);
  std::scanf("%s%s", s, t);
  n = std::strlen(s);
  m = std::strlen(t);
  for (std::size_t i = 0; i < m; i++) {
    std::size_t x = i;
    for (std::size_t j = 0; j < n; j++)
      if (s[j] == t[x])
        if (++x == m) {
          cnt[i]++;
          x = 0;
        }
    nxt[i] = x;
  }
  long long ans = 0LL;
  std::size_t pos = 0;
  for (int i = 1; i <= a; i++) {
    ans += cnt[pos];
    pos = nxt[pos];
  }
  std::printf("%lld", ans / b);
  return 0;
}