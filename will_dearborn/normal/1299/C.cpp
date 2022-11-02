#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

template<typename T> struct TPoint2D {
  T X, Y;
  TPoint2D() : X(), Y() {}
  TPoint2D(const T& x, const T& y) : X(x), Y(y) {}
  TPoint2D(const TPoint2D<T>& p) : X(p.X), Y(p.Y) {}
  TPoint2D& operator=(const TPoint2D<T>& p) { X = p.X; Y = p.Y; return *this; }
  T operator&(const TPoint2D<T>& p) const { return X * p.X + Y * p.Y; }
  T operator^(const TPoint2D<T>& p) const { return X * p.Y - Y * p.X; }
  bool operator<(const TPoint2D<T>& p) const {return X < p.X || (X == p.X && Y < p.Y); }
  bool operator==(const TPoint2D<T>& p) const {return X == p.X && Y == p.Y; }
  TPoint2D conj() const { return TPoint2D(X, -Y); }
  TPoint2D<T> operator*(const TPoint2D<T>& p) const { return TPoint2D<T>(*this & p.conj(), -*this ^ p.conj()); }
  TPoint2D<T> operator*(const T& p) const { return TPoint2D<T>(p * X, p * Y); }
  TPoint2D<T> operator-(void) const { return TPoint2D(-X, -Y); }
  TPoint2D<T> operator+(const TPoint2D<T>& p) const { return TPoint2D(X + p.X, Y + p.Y); }
  TPoint2D<T> operator-(const TPoint2D<T>& p) const { return *this + (-p); }
  T norm() const { return X * X + Y * Y; }
  T dist() const { return sqrt(norm()); }
};
typedef TPoint2D<ll> pnt;
typedef TPoint2D<ll> pt;

bool cmp (pnt a, pnt b) {
  return a.X < b.X || a.X == b.X && a.Y < b.Y;
}

bool cw (pt a, pt b, pt c) {
  return a.X*(b.Y-c.Y)+b.X*(c.Y-a.Y)+c.X*(a.Y-b.Y) < 0;
}

bool ccw (pt a, pt b, pt c) {
  return a.X*(b.Y-c.Y)+b.X*(c.Y-a.Y)+c.X*(a.Y-b.Y) > 0;
}

void convex_hull (vector<pt> & a) {
  if (a.size() == 1)  return;
  sort (a.begin(), a.end(), &cmp);
  pt p1 = a[0],  p2 = a.back();
  vector<pt> up, down;
  up.push_back (p1);
  down.push_back (p1);
  for (size_t i=1; i<a.size(); ++i) {
    if (i==a.size()-1 || cw (p1, a[i], p2)) {
      while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
        up.pop_back();
      up.push_back (a[i]);
    }
    if (i==a.size()-1 || ccw (p1, a[i], p2)) {
      while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
        down.pop_back();
      down.push_back (a[i]);
    }
  }
  a.clear();
  for (size_t i=0; i<down.size(); ++i)
    a.push_back (down[i]);
  for (size_t i=up.size()-2; i>0; --i)
    a.push_back (up[i]);
}

ll p2(ll x) {
  return x*x;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<pnt> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i].Y);
    a[i].Y += a[i - 1].Y;
    a[i].X = i;
  }
  convex_hull(a);
  for (int i = 0; i + 1 < a.size(); ++i) {
    double avg = (a[i + 1].Y - a[i].Y) / (double)(a[i + 1].X - a[i].X);
    for (int j = 0; j < a[i + 1].X - a[i].X; ++j) {
      printf("%.10lf\n", avg);
    }
  }
  return 0;
}