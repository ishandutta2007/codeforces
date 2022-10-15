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
int n, a[1005], top;
std::pair<int, int> s[10];
bool Check() {
  for (int i = 1; i <= n; i++)
    if (a[i] != i) return false;
  return true;
}
void Dfs(int x) {
  if (Check()) {
    std::printf("%d\n", top);
    for (int i = top; i >= 1; i--)
      std::printf("%d %d\n", s[i].first, s[i].second);
    std::exit(0);
  }
  if (x == 3) return;
  for (int i = 1; i <= n; i++)
    if (a[i] != i &&
        (std::abs(a[i] - a[i - 1]) > 1 || std::abs(a[i] - a[i + 1]) > 1))
      for (int j = i + 1; j <= n; j++)
        if (a[j] != j &&
            (std::abs(a[j] - a[j - 1]) > 1 || std::abs(a[j] - a[j + 1]) > 1)) {
          s[++top] = {i, j};
          std::reverse(a + i, a + j + 1);
          Dfs(x + 1);
          std::reverse(a + i, a + j + 1);
          top--;
        }
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  a[0] = a[n + 1] = -1;
  Dfs(0);
  return 0;
}