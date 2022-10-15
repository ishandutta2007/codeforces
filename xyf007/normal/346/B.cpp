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
std::size_t n, m, l, nxt[101];
char a[101], b[101], c[101];
int dp[101][101][101];
std::vector<std::size_t> v[101][26];
void Dfs(std::size_t p1, std::size_t p2, std::size_t p3) {
  if (!dp[p1][p2][p3]) return;
  if (a[p1] == b[p2])
    for (auto &&pre : v[p3][a[p1] - 'A'])
      if (dp[p1][p2][p3] == dp[p1 - 1][p2 - 1][pre] + 1) {
        Dfs(p1 - 1, p2 - 1, pre);
        std::printf("%c", a[p1]);
        return;
      }
  if (p1 > 1 && dp[p1][p2][p3] == dp[p1 - 1][p2][p3])
    Dfs(p1 - 1, p2, p3);
  else
    Dfs(p1, p2 - 1, p3);
}
int main(int argc, char const *argv[]) {
  std::scanf("%s%s%s", a + 1, b + 1, c + 1);
  n = std::strlen(a + 1);
  m = std::strlen(b + 1);
  l = std::strlen(c + 1);
  std::size_t j = 0;
  for (std::size_t i = 2; i <= l; i++) {
    while (j && c[j + 1] != c[i]) j = nxt[j];
    if (c[j + 1] == c[i]) j++;
    nxt[i] = j;
  }
  for (std::size_t i = 0; i <= l; i++)
    for (char j = 'A'; j <= 'Z'; j++) {
      std::size_t p = i;
      while (p && c[p + 1] != j) p = nxt[p];
      if (c[p + 1] == j) p++;
      v[p][j - 'A'].emplace_back(i);
    }
  for (std::size_t i = 1; i <= n; i++)
    for (std::size_t j = 1; j <= m; j++)
      for (std::size_t k = 0; k < l; k++) {
        if (a[i] == b[j])
          for (auto &&pre : v[k][a[i] - 'A'])
            checkmax(dp[i][j][k], dp[i - 1][j - 1][pre] + 1);
        checkmax(dp[i][j][k], std::max(dp[i - 1][j][k], dp[i][j - 1][k]));
      }
  std::ptrdiff_t p = std::max_element(dp[n][m], dp[n][m] + l) - dp[n][m];
  if (!dp[n][m][p])
    std::printf("0");
  else
    Dfs(n, m, p);
  return 0;
}