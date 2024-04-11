// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx")
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

const int mod = 31607;
const int iv = 3973;

inline void add(int &x, int y) {
  x += y; if (x >= mod) x -= mod;
}

int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}


int cnt[2097152], p[21][21], ip[21][21], row[21], col[21];
int z[21][2097152];
int n, all, X, Y;

int main() {
//  cerr << iv;
  n = read(), all = 1 << n;
  fill(row, row + n, 1), fill(col, col + n, 1);
  for (int i = 0; i < all; i++) cnt[i] = cnt[i >> 1] + (i & 1);
  X = Y = 1;
  rep(i, 0, n - 1) {
    rep(j, 0, n - 1) {
      p[i][j] = 1ll * read() * iv % mod;
      ip[i][j] = qpow(p[i][j]);
      row[i] = 1ll * row[i] * p[i][j] % mod;
      col[j] = 1ll * col[j] * p[i][j] % mod;
//      printf("ip[%d][%d] = %d\n", i, j, ip[i][j]);
    }
  }
//  rep(i, 0, n - 1) {
//    printf("a[%d] = %d\n", i, a[i]);
//    printf("b[%d] = %d\n", i, b[i]);
//  }
  rep(i, 0, n - 1) X = 1ll * X * p[i][i] % mod;
  rep(i, 0, n - 1) Y = 1ll * Y * p[i][n - 1 - i] % mod;
  rep(i, 0, n - 1) {
    rep(st, 0, all - 1) {
      z[i][st] = 1;
      rep(k, 0, n - 1) {
        if (st >> k & 1)
          z[i][st] = 1ll * z[i][st] * ip[k][i] % mod;
      }
//      printf("z[%d][%d] = %d\n", i, st, z[i][st]);
    }
  }
  int ans = 1;
  rep(tx, 0, 1) {
    rep(ty, 0, 1) {
      rep(i, 0, all - 1) {
        int P = 1;
        if (~(cnt[i] + tx + ty) & 1) P = mod - P;
        rep(k, 0, n - 1) {
          if (i >> k & 1) P = 1ll * P * row[k] % mod;
        }
//        printf("P = %d\n", P);
        if (tx) P = 1ll * P * X % mod;
        if (ty) P = 1ll * P * Y % mod;
        rep(j, 0, n - 1) {
          int A = P, B = mod - P;
          if (tx && ty && (n & 1) && j == (n >> 1) && !(i >> (n >> 1) & 1)) {
            A = 1ll * A * ip[j][j] % mod;
          }
          B = 1ll * B * col[j] % mod * z[j][i] % mod;
          if (tx) {
            if (i >> j & 1) A = 1ll * A * ip[j][j] % mod;
            B = 1ll * B * ip[j][j] % mod;
          }
          if (ty) {
            if (i >> (n - j - 1) & 1) A = 1ll * A * ip[n - j - 1][j] % mod;
            B = 1ll * B * ip[n - j - 1][j] % mod;
          }
          P = (A + B) % mod; 
        }
//        printf("tx = %d, ty = %d, i = %d, P = %d\n", tx, ty, i, P);
        add(ans, P);
      }
    }
  }
  print(ans, '\n');
  return 0;
}