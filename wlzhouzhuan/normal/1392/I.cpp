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

const int N = 262145;
const double PI = acos(-1.0);

#define poly vector<Comp>
struct Comp {
  double x, y;
  Comp (double _x = 0, double _y = 0) {
    x = _x, y = _y; 
  }
};
Comp operator + (Comp x, Comp y) {
  return Comp(x.x + y.x, x.y + y.y);
}
Comp operator - (Comp x, Comp y) {
  return Comp(x.x - y.x, x.y - y.y);
}
Comp operator * (Comp x, Comp y) {
  return Comp(x.x * y.x - x.y * y.y, x.x * y.y + x.y * y.x);
}

int R[N], lim, L;
inline void getR(int n) {
  lim = 1, L = 0;
  while (lim <= n) lim <<= 1, L++;
  for (int i = 0; i < lim; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
}
inline void fft(poly &a, int opt) {
  a.resize(lim);
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
    for (int i = 0; i < lim; i++)
      a[i].x /= lim, a[i].y /= lim;
  }
}

ll ansV1[N], ansV2[N], ansE1[N], ansE2[N], ansh1[N], ansh2[N];
int a[N], b[N], n, m, q;

int main() {
  n = read(), m = read(), q = read();
  getR(200000);
//  cerr << "lim = " << lim << '\n';
  poly fa(lim), fmina(lim), fmaxa(lim);
  poly fb(lim), fminb(lim), fmaxb(lim);
  rep(i, 1, n) a[i] = read(), fa[a[i]].x++;
  rep(i, 1, m) b[i] = read(), fb[b[i]].x++;
  rep(i, 1, n - 1) fmina[min(a[i], a[i + 1])].x++, fmaxa[max(a[i], a[i + 1])].x++;
  rep(i, 1, m - 1) fminb[min(b[i], b[i + 1])].x++, fmaxb[max(b[i], b[i + 1])].x++;
  fft(fa, 1), fft(fmina, 1), fft(fmaxa, 1);
  fft(fb, 1), fft(fminb, 1), fft(fmaxb, 1);
  poly V(lim), E1(lim), E2(lim), H1(lim), H2(lim);
  rep(i, 0, lim - 1) {
    V[i] = fa[i] * fb[i];
    E1[i] = fmina[i] * fb[i] + fa[i] * fminb[i];
    E2[i] = fmaxa[i] * fb[i] + fa[i] * fmaxb[i];
    H1[i] = fmina[i] * fminb[i];
    H2[i] = fmaxa[i] * fmaxb[i];
  }
  fft(V, -1), fft(E1, -1), fft(E2, -1), fft(H1, -1), fft(H2, -1);
  per(i, lim - 1, 0) {
    ansV1[i] = ansV1[i + 1] + (ll)(V[i].x + 0.5);
    ansE1[i] = ansE1[i + 1] + (ll)(E1[i].x + 0.5);
    ansh1[i] = ansh1[i + 1] + (ll)(H1[i].x + 0.5);
  }
  rep(i, 0, lim - 1) {
    ansV2[i] = (i ? ansV2[i - 1] : 0) + (ll)(V[i].x + 0.5);
    ansE2[i] = (i ? ansE2[i - 1] : 0) + (ll)(E2[i].x + 0.5);
    ansh2[i] = (i ? ansh2[i - 1] : 0) + (ll)(H2[i].x + 0.5);
  }
  cerr << clock() << '\n';
  while (q--) {
    int x = read();
//    printf("%lld %lld %lld %lld %lld %lld\n", ansV1[x], ansV2[x - 1], ansE1[x], ansE2[x - 1], ansh1[x], ansh2[x - 1]);
    print(ansV1[x] - ansV2[x - 1] - ansE1[x] + ansE2[x - 1] + ansh1[x] - ansh2[x - 1], '\n');
  }
  return 0;
}