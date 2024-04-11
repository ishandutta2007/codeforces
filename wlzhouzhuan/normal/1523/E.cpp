// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 500005;
const int mod = 1e9 + 7;

int fac[N], ifac[N];
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return res;
}
void init(int n) {
  fac[0] = ifac[0] = 1;
  rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod; 
}
int C(int n, int m) {
  if (n < m || m < 0) return 0;
  else return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}
int n, k;
void solve() {
  n = read(), k = read();
  int ans = fac[n];
  rep(i, 1, n) {
    if (1ll * i * k - k + 1 > n) break;
    ans = (ans + 1ll * C(n - 1 - (i - 1) * k + i, i) * fac[i] % mod * fac[n - i]) % mod;
  }
  printf("%d\n", 1ll * ans * ifac[n] % mod);
}
int main() {
  init(5e5);
  int T = read();
  while (T--) solve();
  return 0;
}