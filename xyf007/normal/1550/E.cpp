#include <algorithm>
#include <cctype>
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
int n, k, cntq[200001], cnt[200001][17], pos[17][200005], dp[131072];
char s[200001];
int Query(int l, int r) { return cntq[r] - cntq[l - 1]; }
int Query(int l, int r, int x) { return cnt[r][x] - cnt[l - 1][x]; }
bool Check(int d) {
  std::memset(pos, 0x3f, sizeof(pos));
  for (int i = 0; i < k; i++)
    for (int j = n; j >= 1; j--)
      if (j + d - 1 <= n && Query(j, j + d - 1) + Query(j, j + d - 1, i) == d)
        pos[i][j] = j + d - 1;
      else
        pos[i][j] = pos[i][j + 1];
  dp[0] = 0;
  std::fill(dp + 1, dp + (1 << k), n + 1);
  for (int S = 1; S < (1 << k); S++)
    for (int i = 0; i < k; i++)
      if ((S >> i) & 1) checkmin(dp[S], pos[i][dp[S ^ (1 << i)] + 1]);
  return dp[(1 << k) - 1] <= n;
}
int main(int argc, char const *argv[]) {
  Read(n, k);
  std::scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    cntq[i] = cntq[i - 1] + (s[i] == '?');
    std::memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i]));
    if (std::isalpha(s[i])) cnt[i][s[i] - 'a']++;
  }
  int l = 0, r = n / k, best = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (Check(mid)) {
      best = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  std::printf("%d", best);
  return 0;
}