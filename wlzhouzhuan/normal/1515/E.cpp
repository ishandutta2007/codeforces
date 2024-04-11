// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 405;

int n, mod;
inline int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
int fac[N], ifac[N], pw[N], dp[N][N];
inline void init(int n) {
  fac[0] = pw[0] = 1;
  rep(i, 1, n) pw[i] = 2 * pw[i - 1] % mod;
  rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
inline int C(int n, int m) {
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}
inline void add(int &x, int y) {
  x += y; if (x >= mod) x -= mod;
}

int main() {
  scanf("%d%d", &n, &mod);
  init(n);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = pw[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = i - 1; k >= 1 && k >= j; k--) {
        add(dp[i][j], 1ll * dp[k - 1][j - 1] * pw[i - k - 1] % mod * C(i - j, i - k) % mod);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) add(ans, dp[n][i]);
  printf("%d\n", ans);
  return 0;
}