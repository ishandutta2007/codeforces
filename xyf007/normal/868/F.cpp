#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, k, a[100001], cur, cnt[100001], l, r;
long long dp[21][100001], s;
long long Calc(int L, int R) {
  while (r < R) s += cnt[a[++r]]++;
  while (l > L) s += cnt[a[--l]]++;
  while (r > R) s -= --cnt[a[r--]];
  while (l < L) s -= --cnt[a[l++]];
  return s;
}
void Solve(int l, int r, int ql, int qr) {
  if (l > r) return;
  if (ql == qr) {
    for (int i = l; i <= r; i++) dp[cur][i] = dp[cur - 1][ql - 1] + Calc(ql, i);
    return;
  }
  int mid = (l + r) >> 1, op = -1, cr = std::min(qr, mid);
  for (int i = ql; i <= cr; i++)
    if (long long t = dp[cur - 1][i - 1] + Calc(i, mid); t < dp[cur][mid])
      dp[cur][mid] = t, op = i;
  Solve(l, mid - 1, ql, op), Solve(mid + 1, r, op, qr);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0LL;
  l = 1, r = 0;
  for (cur = 1; cur <= k; cur++) Solve(1, n, 1, n);
  std::cout << dp[k][n];
  return 0;
}