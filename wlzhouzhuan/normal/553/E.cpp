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

const double inf = 1e18;
const double PI = acos(-1.0);

struct Comp {
  double x, y;
  Comp (double _x = 0.0, double _y = 0.0) {
    x = _x, y = _y;
  }
};
Comp operator + (Comp a, Comp b) {
  return (Comp){a.x + b.x, a.y + b.y};
}
Comp operator - (Comp a, Comp b) {
  return (Comp){a.x - b.x, a.y - b.y};
}
Comp operator * (Comp a, Comp b) {
  return (Comp){a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}

#define poly vector<double>
#define poly2 vector<Comp>
#define SZ(x) (int(x.size()))

namespace Poly {
  vector<int> R;
  int lim, L;
  void getR(int n) {
    lim = 1, L = 0;
    while (lim <= n) lim <<= 1, L++;
    R.resize(lim);
    for (int i = 0; i < lim; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
  }
  void fft(poly2 &a, int opt) {
    for (int i = 0; i < lim; i++) if (i < R[i]) swap(a[i], a[R[i]]);
    for (int mid = 1; mid < lim; mid <<= 1) {
      Comp Wn(cos(PI / mid), opt * sin(PI / mid));
      for (int i = 0; i < lim; i += mid << 1) {
        Comp W(1, 0);
        for (int j = 0; j < mid; j++, W = W * Wn) {
          Comp x = a[i + j], y = W * a[i + j + mid];
          a[i + j] = x + y;
          a[i + j + mid] = x - y;
        }
      }
    }
    if (opt == -1) {
      for (int i = 0; i < lim; i++) {
        a[i].x /= lim, a[i].y /= lim;
      }
    }
  }
  poly operator * (poly a, poly b) {
    int n = a.size() + b.size() - 1;
    getR(n);
    poly2 _a(lim), _b(lim);
    for (int i = 0; i < SZ(a); i++) _a[i].x = a[i];
    for (int i = 0; i < SZ(b); i++) _b[i].x = b[i];
    fft(_a, 1), fft(_b, 1);
    for (int i = 0; i < lim; i++) _a[i] = _a[i] * _b[i];
    fft(_a, -1);
    poly c(n);
    for (int i = 0; i < n; i++) c[i] = _a[i].x;
    return c;
  }
}
using namespace Poly;

double d[55][55], p[105][40005], g[105][40005], dp[55][40005];
int a[105], b[105], c[105];
int n, m, t, x;

void cdq(int l, int r) {
  if (l >= t) return ;
  if (l == r) {
    for (int i = 1; i <= m; i++) {
      ckmin(dp[a[i]][l], g[i][l] + c[i]);
    }
    return ;
  }
//  printf("cdq %d %d\n", l, r);
  int mid = l + r >> 1;
  cdq(mid + 1, r);
//  printf("now l = %d, mid = %d, r = %d\n", l, mid, r);
  for (int i = 1; i <= m; i++) {
    //cerr << "!!\n";
    poly A(r - l), B(r - mid);
    //cerr << "!1\n";
    for (int j = 0; j < r - l; j++) A[j] = p[i][r - l - j];
    //cerr << "!2\n";
    for (int j = 0; j < r - mid; j++) B[j] = dp[b[i]][mid + 1 + j];
//    printf("[a]: "); for (auto v: A) printf("%.3lf ", v); puts("");
//    printf("[b]: "); for (auto v: B) printf("%.3lf ", v); puts("");
    A = A * B;
    //cerr << "?\n";
//    printf("After fft\n");
//    for (auto v: A) printf("%.5lf ", v); puts("");
    for (int j = l; j <= mid; j++) {
      g[i][j] += A[r - l - mid - 1 + j];
    }
    //cerr << "???\n";
  }
  //cerr << "!\n"; 
  cdq(l, mid);
}

int main() {
  n = read(), m = read(), t = read(), x = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2 * t; j++) {
      dp[i][j] = inf;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) d[i][j] = 0;
      else d[i][j] = inf;
    }
  }
  for (int i = 1; i <= m; i++) {
    a[i] = read(), b[i] = read(), c[i] = read();
    d[a[i]][b[i]] = c[i];
    for (int j = 1; j <= t; j++) {
      p[i][j] = read() / 1e5;
    }
    if (a[i] == n) i--, m--; //  (n, *, *) 
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        ckmin(d[i][j], d[i][k] + d[k][j]);
  for (int i = 0; i < 2 * t; i++) dp[n][i] = (i <= t ? 0 : x);
  for (int i = 1; i < n; i++)
    for (int j = t; j < 2 * t; j++)
      dp[i][j] = d[i][n] + x;
  cdq(0, 2 * t - 1);
  printf("%.10f\n", dp[1][0]);
  return 0; 
}