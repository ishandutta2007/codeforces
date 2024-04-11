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
std::size_t n, sg[5001];
char s[5001];
bool vis[10001];
int main(int argc, char const *argv[]) {
  std::scanf("%s", s);
  n = std::strlen(s);
  for (std::size_t i = 1; i <= n; i++) {
    std::memset(vis, false, sizeof(vis));
    for (std::size_t j = 0; j < i; j++)
      vis[sg[std::max(j - 1, 0ULL)] ^ sg[std::max(i - j - 2, 0ULL)]] = true;
    for (std::size_t j = 0;; j++)
      if (!vis[j]) {
        sg[i] = j;
        break;
      }
  }
  std::size_t ans = 0;
  for (std::size_t i = 1; i < n - 1; i++)
    if (s[i - 1] == s[i + 1]) {
      std::size_t j = i;
      while (j + 2 < n && s[j] == s[j + 2]) j++;
      ans ^= sg[j - i + 1];
      i = j + 1;
    }
  if (!ans) {
    std::printf("Second");
    return 0;
  }
  std::printf("First\n");
  for (std::size_t i = 1; i < n - 1; i++)
    if (s[i - 1] == s[i + 1]) {
      std::size_t j = i;
      while (j + 2 < n && s[j] == s[j + 2]) j++;
      std::size_t tmp = ans ^ sg[j - i + 1];
      for (std::size_t k = 0; k <= j - i; k++)
        if (!(tmp ^ sg[std::max(k - 1, 0ULL)] ^
              sg[std::max(j - i - k - 1, 0ULL)])) {
          std::printf("%lu", i + k + 1);
          return 0;
        }
      i = j + 1;
    }
  return 0;
}