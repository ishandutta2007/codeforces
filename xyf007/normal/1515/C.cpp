#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
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
int t, n, m, x;
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, m, x);
    std::printf("YES\n");
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        q;
    for (int i = 1; i <= m; i++) q.emplace(0, i);
    for (int i = 1; i <= n; i++) {
      Read(x);
      std::pair<int, int> tmp = q.top();
      q.pop();
      std::printf("%d%c", tmp.second, " \n"[i == n]);
      q.emplace(tmp.first + x, tmp.second);
    }
  }
  return 0;
}