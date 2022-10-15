#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
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
int n, a[1001];
std::vector<std::pair<int, int>> ans;
void Move(int x, int y) {
  ans.emplace_back(x, y);
  a[y] -= a[x];
  a[x] *= 2;
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  if (std::count_if(a + 1, a + n + 1,
                    [](const int &x) -> bool { return x > 0; }) < 2) {
    std::printf("-1");
    return 0;
  }
  int p2 = 1, p3 = 2;
  for (int i = 3; i <= n; i++) {
    int p1 = i;
    while (true) {
      if (a[p1] > a[p2]) std::swap(p1, p2);
      if (a[p1] > a[p3]) std::swap(p1, p3);
      if (a[p2] > a[p3]) std::swap(p2, p3);
      if (!a[p1]) break;
      for (int j = a[p2] / a[p1]; j; j >>= 1)
        if (j & 1)
          Move(p1, p2);
        else
          Move(p1, p3);
    }
  }
  std::printf("%u\n", ans.size());
  for (auto &&i : ans) std::printf("%d %d\n", i.first, i.second);
  return 0;
}