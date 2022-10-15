/* Author: wlzhouzhuan
 * Created: 2021-07-24 18:23:24
 * System: NOI Linux
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, l, r) for (int i = l; i <= r; i++) 
#define per(i, l, r) for (int i = l; i >= r; i--)
#define pb push_back
#define SZ(x) (int(x.size()))

inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char ch) {
  print(x), putchar(ch);
}

const int N = 100005;
const int mod = 998244353;
const int G = 3, Gi = 332748118;
const int inv2 = (mod + 1) / 2;

int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}

namespace Poly {
#define poly vector<int>
int rev[1 << 20], lim, L;
void getR(int len) {
  lim = 1, L = 0;
  while (lim <= len) lim <<= 1, L++;
  for (int i = 0; i < lim; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << L - 1); 
}
void NTT(poly &a, int opt) {
  for (int i = 0; i < lim; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int Wn = qpow(opt == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int j = 0; j < lim; j += 2 * mid) {
      int W = 1;
      for (int k = 0; k < mid; k++, W = 1ll * W * Wn % mod) {
        int x = a[j + k], y = 1ll * W * a[j + k + mid] % mod;
        a[j + k] = (x + y) % mod;
        a[j + k + mid] = (x + mod - y) % mod;
      }
    }
  }
  if (opt == -1) {
    int linv = qpow(lim);
    for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * linv % mod;
  }
}
void operator += (poly &a, poly b) {
  if (SZ(a) < SZ(b)) a.resize(SZ(b));
  for (int i = 0; i < SZ(b); i++) a[i] = (a[i] + b[i]) % mod;
}
poly operator >> (poly a, int x) {
  int len = SZ(a);
  if (len - 1 < x) return {};
  for (int i = x; i < len; i++) a[i - x] = a[i];
  a.resize(len - x);
  return a;
}
poly operator * (poly a, poly b) {
  int len = SZ(a) + SZ(b) - 1;
  if (len <= 300) {
    poly c(len);
    for (int i = 0; i < SZ(a); i++) {
      for (int j = 0; j < SZ(b); j++) {
        c[i + j] = (c[i + j] + 1ll * a[i] * b[j]) % mod;
      }
    }
    return c;
  }
  getR(len);
  a.resize(lim), b.resize(lim);
  NTT(a, 1), NTT(b, 1);
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * b[i] % mod;
  NTT(a, -1);
  a.resize(len);
  return a;
}
void print_poly(poly a) {
  for (auto v: a) printf("%d ", v);
  puts("");
}
}
using namespace Poly;

int zz[N], b[N], n, m;
void WA() { puts("0"), exit(0); }

#define ls (u << 1)
#define rs (u << 1 | 1)
poly a[N << 2][2][2]; // [0/1][0/1] 
void solve(int u, int l, int r) {
  if (l == r) {
    a[u][0][0] = a[u][0][1] = a[u][1][0] = a[u][1][1] = {0, 1};
    if (b[l] == 1) a[u][0][0] = {0, inv2};
    //printf("node[%d] = ", u);
    //print_poly(a[u][0][0]);
    //print_poly(a[u][0][1]);
    //print_poly(a[u][1][0]);
    //print_poly(a[u][1][1]);
    return ;
  }
  int mid = l + r >> 1;
  solve(ls, l, mid), solve(rs, mid + 1, r);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a[u][i][j] += (a[ls][i][1] * a[rs][1][j]) >> 1;
      a[u][i][j] += a[ls][i][0] * a[rs][0][j];
    }
  }
  //printf("node[%d] = ", u);
  //print_poly(a[u][0][0]);
  //print_poly(a[u][0][1]);
  //print_poly(a[u][1][0]);
  //print_poly(a[u][1][1]);
}

int fac[N], ifac[N], pw[N];
void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  for (int i = n; i >= 1; i--) ifac[i - 1] = 1ll * ifac[i] * i % mod;
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = 2 * pw[i - 1] % mod; 
}

int main() {
  init(N - 1);
  n = read();
  for (int i = 1; i <= n; i++) zz[i] = read();
  for (int i = 1; i <= n; i++) {
    int x = zz[i];
    if (i + x - 1 > n) WA();
    for (int j = i; j <= i + x - 1; j++) {
      if (zz[j] != x) WA();
    }
    b[++m] = x;
    i += x - 1;
  }
  
  //printf("m = %d\n", m);
  //for (int i = 1; i <= m; i++) printf("%d ", b[i]);
  //puts("");
  
  solve(1, 1, m);
  int ans = 0;
  assert(SZ(a[1][0][0]) == m + 1);
  for (int i = 0; i <= m; i++) {
    int coef = 1ll * fac[i] * qpow(2, i) % mod * a[1][0][0][i] % mod;
    if ((m - i) & 1) ans = (ans + mod - coef) % mod;
    else ans = (ans + coef) % mod;
  }
  print(ans, '\n');
  return 0;
}