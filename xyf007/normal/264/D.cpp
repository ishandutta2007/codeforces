#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) {
      return EOF;
    }
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9') {
    if (c == '-') {
      f = -1;
    }
  }
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') {
    x = x * 10 + c - '0';
  }
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
char s[1000001], t[1000001];
std::size_t n, m, a[1000001], b[1000001];
int cnt[3][3][1000001];
int main(int argc, char const *argv[]) {
  std::scanf("%s%s", s + 1, t + 1);
  n = std::strlen(s + 1);
  m = std::strlen(t + 1);
  for (std::size_t i = 1; i <= n; i++) {
    a[i] = s[i] % 3;
  }
  for (std::size_t i = 1; i <= m; i++) {
    b[i] = t[i] % 3;
  }
  for (std::size_t i = 0; i < 3; i++) {
    for (std::size_t j = 0; j < 3; j++) {
      for (std::size_t k = 2; k <= m; k++) {
        cnt[i][j][k] = cnt[i][j][k - 1] + (b[k - 1] == i && b[k] == j);
      }
    }
  }
  std::size_t l = 1, r = 1;
  while (r < m && b[r] != a[1]) {
    r++;
  }
  long long ans = r - l + 1;
  for (std::size_t i = 2; i <= n; i++) {
    if (l <= m && a[i - 1] == b[l]) {
      l++;
    }
    if (l > m) {
      break;
    }
    if (r < m) {
      r++;
      while (r < m && b[r] != a[i]) {
        r++;
      }
    }
    if (l > r) {
      continue;
    }
    ans += r - l + 1;
    if (a[i - 1] != a[i]) {
      ans -= cnt[a[i]][a[i - 1]][r] - cnt[a[i]][a[i - 1]][l - 1];
    }
  }
  std::printf("%lld", ans);
  return 0;
}