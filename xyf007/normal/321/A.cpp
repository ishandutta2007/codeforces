#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
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
int x, y;
std::vector<std::pair<int, int>> v;
char s[101];
int main(int argc, char const *argv[]) {
  Read(x, y);
  std::scanf("%s", s);
  int nx = 0, ny = 0;
  std::size_t n = std::strlen(s);
  for (std::size_t i = 0; i < n; i++) {
    v.emplace_back(nx, ny);
    if (s[i] == 'U') ny++;
    if (s[i] == 'D') ny--;
    if (s[i] == 'L') nx--;
    if (s[i] == 'R') nx++;
  }
  for (auto &&i : v) {
    int tx = x - i.first, ty = y - i.second;
    if ((!nx && tx) || (!ny && ty)) continue;
    if (!nx) {
      if (!ny || (!(ty % ny) && ty / ny >= 0)) {
        std::printf("Yes");
        return 0;
      } else {
        continue;
      }
    }
    if (!ny) {
      if (!nx || (!(tx % nx) && tx / nx >= 0)) {
        std::printf("Yes");
        return 0;
      } else {
        continue;
      }
    }
    if (!(tx % nx) && !(ty % ny) && tx / nx >= 0 && tx / nx == ty / ny) {
      std::printf("Yes");
      return 0;
    }
  }
  std::printf("No");
  return 0;
}