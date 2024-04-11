#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x=0, T y=0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
  bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
  P operator+(P p) const { return P(x+p.x, y+p.y); }
  P operator-(P p) const { return P(x-p.x, y-p.y); }
  P operator*(T d) const { return P(x*d, y*d); }
  P operator/(T d) const { return P(x/d, y/d); }
  T dot(P p) const { return x*p.x + y*p.y; }
  T cross(P p) const { return x*p.y - y*p.x; }
  T cross(P a, P b) const { return (a-*this).cross(b-*this); }
  T dist2() const { return x*x + y*y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x-axis in interval [-pi, pi]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this/dist(); } // makes dist()=1
  P perp() const { return P(-y, x); } // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated 'a' radians ccw around the origin
  P rotate(double a) const {
    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};


template<class P>
P circleTangents(const P &p, const P &c, double r) {
  P a = p-c;
  double x = r*r/a.dist2(), y = sqrt(x-x*x);
  return c+a*x+a.perp()*y;
}


using D = double;
using I = D;
using P = Point<D>;
const D eps = 1e-14;

template<class F>
I bs(I a, I b, F f) {
  assert(a < b);
  while(a + 1e-7 < b) { // floats: s/1/eps
    I q = a + (b - a)/2;
    (!f(q) ? b : a) = q;
  }
  return a;
}

template<class P>
int sideOf(const P& s, const P& e, const P& p, double eps) {
  auto a = (e-s).cross(p-s);
  double l = (e-s).dist()*eps;
  return (a > l) - (a < -l);
}


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n,m;
  cin>>n>>m;
  vector<P> pts(n);
  rep(i,0,n) cin >> pts[i].x >> pts[i].y;

  vector<vi> len(30,vi(n));
  vector<P> tangents(n);
  vector<D> angles(n);

  auto works = [&](D rad){
    debug(rad);
    D rad2 = rad*rad;
    rep(i,0,n) {
      if(pts[i].dist2() <= rad2) return false;
      tangents[i] = circleTangents(pts[i], P{0,0}, rad);
      angles[i] = tangents[i].angle();
    }
    vi idx(n);
    iota(all(idx),0);
    sort(all(idx), [&](int a, int b) {
        return angles[a] < angles[b];
        });

    int r = 0;
    rep(_i,0,n) {
      int i = idx[_i];
      while(r < _i + n && sideOf(pts[i], tangents[i], pts[idx[r%n]], eps) <= 0) ++r;
      debug(_i, r);
      len[0][_i] = (r-_i);
    }
    ll x = 0;
    rep(i,0,3*n) {
      x += len[0][x%n];
    }
    debug(x%n);
    debug(len[0], n);
    ll y = x;
    rep(i,0,m) {
      x += len[0][x%n];
    }
    if(x - y >= n) return true;
    return false;
  };

  D ans = bs(D(0.0),D(1e9), works);

  cout << setprecision(30) << ans << endl;
}