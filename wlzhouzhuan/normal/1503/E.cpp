// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
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

const int N = 5005;
const int mod = 998244353;

int C[N][N];
int n, m;

int main() {
  n = read(), m = read();
  C[0][0] = 1;
  for (int i = 1; i < N; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  int ans = 0;
  for (int r = 1; r < n; r++) {
    int coef = 0;
    for (int y = m - 1; y >= 1; y--) {
      coef = (coef + 1ll * C[y + n - r - 1][n - r - 1] * C[m - y + n - r - 1][n - r]) % mod;
      ans = (ans + 1ll * coef * C[y + r - 1][r] % mod * C[m - y + r - 1][r - 1]) % mod;
    }
  }
  swap(n, m);
  for (int r = 1; r < n; r++) {
    int coef = 0;
    for (int y = m - 1; y >= 1; y--) {
      ans = (ans + 1ll * coef * C[y + r - 1][r] % mod * C[m - y + r - 1][r - 1]) % mod;
      coef = (coef + 1ll * C[y + n - r - 1][n - r - 1] * C[m - y + n - r - 1][n - r]) % mod;
    }
  }
  print(2 * ans % mod, '\n');
  return 0;
}