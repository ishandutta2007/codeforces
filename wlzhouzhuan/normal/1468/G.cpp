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

#define x1 xa1
#define x2 xa2
#define y1 ya1
#define y2 ya2

const int N = 200005;
const double eps = 1e-9;

struct dot {
  double x, y;
} p[N], eye, high;
int n, h;

dot cross(dot x1, dot x2, dot x3, dot x4) {
  if (fabs((x2.y - x1.y) * (x4.x - x3.x) - (x4.y - x3.y) * (x2.x - x1.x)) < eps) {
    return x2;
  }
  if (x2.x == high.x) return x2;
  double k1 = (x2.y - x1.y) / (x2.x - x1.x), k2 = (x4.y - x3.y) / (x4.x - x3.x);
  double b1 = x2.y - x2.x * k1, b2 = x4.y - x4.x * k2;
  double cx = (b2 - b1) / (k1 - k2), cy = k1 * cx + b1;
  return dot{cx, cy};
}
double slope(dot x, dot y) { return (y.y - x.y) / (y.x - x.x); }
double sqr(double x) { return x * x; }
double dist(dot x, dot y) {
  return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y));
}

int main() {
  scanf("%d%d", &n, &h);
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  eye.x = p[n].x, eye.y = p[n].y + h, high = p[n];
  double ans = 0.0;
  for (int i = n - 1; i >= 1; i--) {
    if (i == n - 1 || slope(p[i], eye) <= slope(high, eye)) {
      dot jiao = cross(p[i], p[i + 1], high, eye);
      ans += dist(p[i], jiao);
      high = p[i];
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}