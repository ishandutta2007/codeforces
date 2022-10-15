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
constexpr int kMod = 1e9 + 7;
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
int n, m, nxt[201], tr[201][2], dp[201][201][201];
char s[201];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> (s + 1);
  n *= 2, m = std::strlen(s + 1);
  int j = 0;
  nxt[1] = 0;
  for (int i = 2; i <= m; i++) {
    while (j && s[j + 1] != s[i]) j = nxt[j];
    if (s[j + 1] == s[i]) j++;
    nxt[i] = j;
  }
  for (int i = 0; i < m; i++) {
    int p = i, q = i;
    while (p && s[p + 1] != '(') p = nxt[p];
    if (s[p + 1] == '(') p++;
    tr[i][0] = p;
    while (q && s[q + 1] != ')') q = nxt[q];
    if (s[q + 1] == ')') q++;
    tr[i][1] = q;
  }
  tr[m][0] = tr[m][1] = m;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= m; k++) {
        Add(dp[i + 1][j + 1][tr[k][0]], dp[i][j][k]);
        if (j) Add(dp[i + 1][j - 1][tr[k][1]], dp[i][j][k]);
      }
  std::cout << dp[n][0][m];
  return 0;
}