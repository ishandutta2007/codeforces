// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { a > b && a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { a < b && a = b; }
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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

const int N = 2000005;
ll a[N], b[N], c[N];
ll m, n, t, mod;

void FWT(ll *a, int opt) {
  for (int mid = 1; mid < n; mid <<= 1) {
    for (int j = 0; j < n; j += mid << 1) {
      for (int k = 0; k < mid; k++) {
        ll x = a[j + k], y = a[j + k + mid];
        a[j + k] = (x + y) % mod;
        a[j + k + mid] = (x - y + mod) % mod;
      }
    }
  }
  if (opt == -1) {
    for (int i = 0; i < n; i++) a[i] /= n;
  }
} 
ll mulmod(ll x, ll y) {
  return ((x * y - (ll)((long double)x / mod * y) * mod) % mod + mod) % mod;
}
void mul(ll *a, ll *b) {
  for (int i = 0; i < n; i++) a[i] = mulmod(a[i], b[i]);
}
int main() {
  m = read(), t = read(), mod = read();
  n = 1 << m, mod = 1ll * n * mod;
  for (int i = 0; i < n; i++) a[i] = read();
  for (int i = 0; i <= m; i++) c[i] = read();
  for (int i = 0; i < n; i++) b[i] = c[__builtin_popcount(i)];
  FWT(a, 1), FWT(b, 1); 
  while (t > 0) {
    if (t & 1) mul(a, b);
    mul(b, b);
    t >>= 1;
  }
  FWT(a, -1);
  for (int i = 0; i < n; i++) print(a[i], '\n');
  return 0;
}