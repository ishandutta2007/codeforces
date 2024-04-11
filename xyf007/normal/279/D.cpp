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
int n, a[23], dp[8388608];
int Dfs(int S, int p) {
  if (dp[S]) return dp[S];
  int ans = 0x7fffffff, cnt = __builtin_popcount(S);
  for (int i = 0; i < p; i++)
    for (int j = i; j < p; j++)
      if (a[i] + a[j] == a[p])
        checkmin(ans, std::max(Dfs((S ^ (1 << p)) | (1 << (p - 1)) | (1 << i) |
                                       (1 << j),
                                   p - 1),
                               cnt));
  return dp[S] = ans;
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 0; i < n; i++) Read(a[i]);
  dp[1] = 1;
  if (Dfs(1 << (n - 1), n - 1) > n)
    std::printf("-1");
  else
    std::printf("%d", dp[1 << (n - 1)]);
  return 0;
}