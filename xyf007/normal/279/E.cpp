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
char s[1000001];
std::size_t n;
int main(int argc, char const *argv[]) {
  std::scanf("%s", s);
  n = std::strlen(s);
  int ans = 0, cnt = 0;
  for (std::size_t i = 0; i < n; i++)
    if (s[i] == '1') {
      cnt = 0;
      while (i < n && s[i] == '1') {
        i++;
        cnt++;
      }
      if (cnt == 1) {
        ans++;
      } else {
        ans += 2;
        while (true) {
          cnt = 0;
          while (i < n && s[i] == '0') {
            i++;
            cnt++;
          }
          if (i >= n) break;
          if (cnt == 1) {
            while (i < n && s[i] == '1') i++;
            ans++;
          } else if (cnt == 2) {
            cnt = 0;
            while (i < n && s[i] == '1') {
              i++;
              cnt++;
            }
            if (cnt == 1) {
              ans++;
              break;
            } else {
              ans += 2;
            }
          } else {
            i--;
            break;
          }
        }
      }
    }
  std::printf("%d", ans);
  return 0;
}