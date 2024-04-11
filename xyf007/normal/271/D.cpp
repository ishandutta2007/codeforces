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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
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
char s[1501], a[26];
int k, ch[3000001][26], tot, sum[1501];
std::size_t n;
int main(int argc, char const *argv[]) {
  std::scanf("%s%s", s + 1, a);
  Read(k);
  n = std::strlen(s + 1);
  for (std::size_t i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (a[s[i] - 'a'] == '0');
  }
  int now;
  for (std::size_t i = 1; i <= n; i++) {
    now = 0;
    for (std::size_t j = i; j <= n; j++) {
      if (sum[j] - sum[i - 1] > k) {
        break;
      }
      int id = s[j] - 'a';
      if (!ch[now][id]) {
        ch[now][id] = ++tot;
      }
      now = ch[now][id];
    }
  }
  std::printf("%d", tot);
  return 0;
}