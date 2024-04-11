#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
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
int n, m, x, y, d1, d2;
char s[10];
std::map<std::pair<int, int>, int> vis;
int main(int argc, char const *argv[]) {
  Read(n, m, x, y);
  std::size_t tot = n + m - 2;
  std::scanf("%s", s);
  d1 = s[0] == 'D';
  d2 = s[1] == 'R';
  if (x == 1 || x == n || y == 1 || y == m) vis[{x, y}] = 1;
  long long ans = 0LL;
  while (vis.size() < tot) {
    int dis = std::min(d1 ? n - x : x - 1, d2 ? m - y : y - 1);
    d1 ? x += dis : x -= dis;
    d2 ? y += dis : y -= dis;
    if ((x == 1 && !d1) || (x == n && d1)) d1 ^= 1;
    if ((y == 1 && !d2) || (y == m && d2)) d2 ^= 1;
    ans += dis;
    if (vis[{x, y}] == 2) {
      std::printf("-1");
      return 0;
    }
    if (dis) vis[{x, y}]++;
  }
  std::printf("%lld", ans + 1);
  return 0;
}