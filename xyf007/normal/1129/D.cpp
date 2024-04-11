#include <algorithm>
#include <cmath>
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
constexpr int kB = 350, kMod = 998244353;
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, k, tot, a[100001], b[100001], pos[100001], lst[100001], L[290], R[290],
    tag[290], pre[100001], dp[100001], S, f[290][200001], *sum[290];
void Modify(int l, int r, int v) {
  int pl = pos[l], pr = pos[r];
  if (pl == pr) {
    for (int i = l; i <= r; i++) {
      if (b[i] + tag[pl] == k + 1 && v == -1) Add(S, dp[i]);
      if (b[i] + tag[pl] == k && v == 1) Sub(S, dp[i]);
      Sub(sum[pl][b[i]], dp[i]);
      b[i] += v;
      Add(sum[pl][b[i]], dp[i]);
    }
    return;
  }
  for (int i = pl + 1; i < pr; i++) {
    if (v == 1)
      Sub(S, sum[i][k - tag[i]]);
    else
      Add(S, sum[i][k - tag[i] + 1]);
    tag[i] += v;
  }
  for (int i = l; i <= R[pl]; i++) {
    if (b[i] + tag[pl] == k + 1 && v == -1) Add(S, dp[i]);
    if (b[i] + tag[pl] == k && v == 1) Sub(S, dp[i]);
    Sub(sum[pl][b[i]], dp[i]);
    b[i] += v;
    Add(sum[pl][b[i]], dp[i]);
  }
  for (int i = L[pr]; i <= r; i++) {
    if (b[i] + tag[pr] == k + 1 && v == -1) Add(S, dp[i]);
    if (b[i] + tag[pr] == k && v == 1) Sub(S, dp[i]);
    Sub(sum[pr][b[i]], dp[i]);
    b[i] += v;
    Add(sum[pr][b[i]], dp[i]);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k, tot = n / kB;
  for (int i = 1; i <= n; i++) std::cin >> a[i], pos[i] = i / kB;
  for (int i = 0; i <= tot; i++)
    L[i] = i * kB, R[i] = (i + 1) * kB - 1, sum[i] = &f[i][100000];
  R[tot] = n;
  for (int i = 1; i <= n; i++) pre[i] = lst[a[i]], lst[a[i]] = i;
  dp[0] = S = sum[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    Modify(pre[i], i - 1, 1);
    if (pre[i]) Modify(pre[pre[i]], pre[i] - 1, -1);
    dp[i] = S;
    Add(S, dp[i]), Add(sum[pos[i]][0], dp[i]);
  }
  std::cout << dp[n];
  return 0;
}