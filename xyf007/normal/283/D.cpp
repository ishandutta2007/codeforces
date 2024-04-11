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
int n, cnt[5005], dp[5005];
long long a[5005];
bool Check(int l, int r) {
  if (a[l] % a[r]) return false;
  return cnt[r] - cnt[l] == r - l || cnt[r] < r - l;
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) {
    Read(a[i]);
    while (!(a[i] & 1)) {
      cnt[i]++;
      a[i] >>= 1;
    }
  }
  a[n + 1] = 1LL;
  std::iota(dp + 2, dp + n + 2, 1);
  for (int i = 2; i <= n + 1; i++)
    for (int j = 0; j < i; j++)
      if (Check(j, i)) checkmin(dp[i], dp[j] + i - j - 1);
  std::printf("%d", dp[n + 1]);
  return 0;
}