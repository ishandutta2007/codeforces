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

const int N = 131072;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

ll f1[N], f2[N], f3[N], f[N], ind;
int n, m;
ll x, y, z;

ll qpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

void fwt(ll *a, int opt, int keep = 0) {
  for (int mid = 1; mid < m; mid <<= 1) {
    for (int j = 0; j < m; j += mid << 1) {
      for (int k = 0; k < mid; k++) {
        ll x = a[j + k], y = a[j + k + mid];
        if (keep) {
          a[j + k] = x + y;
          a[j + k + mid] = x - y;
        } else {
          a[j + k] = (x + y) % mod;
          a[j + k + mid] = (x - y + mod) % mod;
        }
        if (opt == -1) {
          a[j + k] = inv2 * a[j + k] % mod;
          a[j + k + mid] = inv2 * a[j + k + mid] % mod;
        } 
      }
    }
  }
}

int main() {
  n = read(), m = 1 << read(), x = read(), y = read(), z = read();
  for (int i = 0; i < n; i++) {
    ll a = read(), b = read(), c = read();
    ind ^= a, b ^= a, c ^= a;
    f1[b]++, f2[c]++, f3[b ^ c]++;
  }
  fwt(f1, 1, 1), fwt(f2, 1, 1), fwt(f3, 1, 1);
  ll s1 = (x + y + z) % mod, s2 = (x + y - z + mod) % mod, s3 = (x - y + z + mod) % mod, s4 = (x - y + mod - z + mod) % mod;
  for (int i = 0; i < m; i++) {
    ll c1 = (n + f1[i] + f2[i] + f3[i]) / 4;
    ll c2 = (n + f1[i] - c1 - c1) / 2;
    ll c3 = (n + f2[i] - c1 - c1) / 2;
    ll c4 = (n + f3[i] - c1 - c1) / 2;
    f[i] = qpow(s1, c1) * qpow(s2, c2) % mod * qpow(s3, c3) % mod * qpow(s4, c4) % mod;
  }
  fwt(f, -1);
  for (int i = 0; i < m; i++) {
    print(f[ind ^ i], ' ');
  }
  return 0;
}