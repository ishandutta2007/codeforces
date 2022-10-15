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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
struct Point {
  int x, y;
} a[100001];
int n, lg[100001], min[18][100001], max[18][100001];
int QueryMax(int l, int r) {
  if (l > r) return -1e9;
  int len = lg[r - l + 1];
  return std::max(max[len][l], max[len][r - (1 << len) + 1]);
}
int QueryMin(int l, int r) {
  if (l > r) return 1e9;
  int len = lg[r - l + 1];
  return std::min(min[len][l], min[len][r - (1 << len) + 1]);
}
bool Check(int x) {
  int r = 0;
  for (int i = 1; i <= n; i++) {
    checkmax(r, i);
    while (r < n && a[r + 1].x - a[i].x <= x) r++;
    if (std::max(QueryMax(1, i - 1), QueryMax(r + 1, n)) -
            std::min(QueryMin(1, i - 1), QueryMin(r + 1, n)) <=
        x)
      return true;
  }
  return false;
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    Read(x, y);
    a[i].x = x + y;
    a[i].y = x - y;
  }
  std::sort(a + 1, a + n + 1, [](const Point &lhs, const Point &rhs) -> bool {
    return lhs.x < rhs.x;
  });
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++) min[0][i] = max[0][i] = a[i].y;
  for (int i = 1; i <= lg[n]; i++)
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      min[i][j] = std::min(min[i - 1][j], min[i - 1][j + (1 << (i - 1))]);
      max[i][j] = std::max(max[i - 1][j], max[i - 1][j + (1 << (i - 1))]);
    }
  int l = 0, r = 2e9, best = -1;
  while (l <= r) {
    int mid = l + ((r - l) >> 1);
    if (Check(mid)) {
      best = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  std::printf("%.8lf", best / 2.);
  return 0;
}