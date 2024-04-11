#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif


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
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")"; }
};

using P = Point<ld>;

template<class T>
T polygonArea2(vector<Point<T>>& v) {
  T a = v.back().cross(v[0]);
  rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
  return a;
}

auto slv(const vector<P>& line, const vector<ld>& f) {
  const int POINT = -1;
  vector<tuple<ld,int,ld,ld>> event;
  rep(i,0,sz(line)-1) {
    P p = line[i], q = line[i+1];
    if(p.x > q.x) swap(p,q);
    if(p.x == q.x) {
      event.emplace_back(q.x, POINT, abs(p.y-q.y), 0);
    }
    else {
      ld slope = (p.x == q.x ? 0 : abs(p.y-q.y)/abs(p.x-q.x));
      event.emplace_back(p.x, POINT, 0, slope);
      event.emplace_back(q.x, POINT, 0, -slope);
    }
  }
  rep(i,0,sz(f)) event.emplace_back(f[i], i,0,0);
  sort(all(event));

  vector<ld> ans(sz(f));

  ld delta = 0, slope = 0, last_x = -1e12, area = 0;
  for(auto [x,qi,del,sdel] : event) {
    ld dx = x - last_x;
    last_x = x;
    area += delta*dx + slope*dx*dx/2;
    delta += slope*dx;

    if(qi != POINT) ans[qi] = area;
    slope += sdel;
    delta += del;
  }
  return ans;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,q;
  cin >> n >> q;
  vector<P> v(n);
  rep(i,0,n) cin>>v[i].x>>v[i].y;
  if(polygonArea2(v) < 0) reverse(all(v));

  int mx = 0, mn = 0;
  rep(i,0,n) {
    if(v[i].y > v[mx].y) mx = i;
    if(v[i].y < v[mn].y) mn = i;
  }

  vector<P> L,M,R;
  {
    int i = mn;
    while(i != mx) {
      R.emplace_back(v[i]);
      i = (i+1)%n;
    }
    R.emplace_back(v[i]);
    rep(i,0,sz(R)-1) assert(R[i].y < R[i+1].y);
  }
  {
    int i = mn;
    while(i != mx) {
      L.emplace_back(v[i]);
      i = (i+n-1)%n;
    }
    L.emplace_back(v[i]);
    rep(i,0,sz(L)-1) assert(L[i].y < L[i+1].y);
  }
  {
    int il = 0, ir = 0;
    while(il != sz(L) && ir != sz(R)) {
      if(L[il].y == R[ir].y) {
        M.emplace_back((L[il] + R[ir])/2);
        ++il; ++ir;
      }
      else if(L[il].y < R[ir].y) {
        ld slope = (R[ir].x - R[ir-1].x) / (R[ir].y - R[ir-1].y);
        ld x = R[ir-1].x + (L[il].y - R[ir-1].y) * slope;
        M.emplace_back((L[il].x + x)/2, L[il].y);
        ++il;
      }
      else if(L[il].y > R[ir].y) {
        ld slope = (L[il].x - L[il-1].x) / (L[il].y - L[il-1].y);
        ld x = L[il-1].x + (R[ir].y - L[il-1].y) * slope;
        M.emplace_back((R[ir].x + x)/2, R[ir].y);
        ++ir;
      }
      else assert(false);
    }
    assert(il == sz(L) && ir == sz(R));
  }

  //debug(L); debug(R); debug(M);

  vector<ld> f(q);
  rep(i,0,q) cin>>f[i];

  auto ansL = slv(L, f);
  auto ansM = slv(M, f);
  auto ansR = slv(R, f);
  ld area = polygonArea2(v)/2;
  //debug(area); debug(ansL); debug(ansR);
  //rep(i,0,q) { debug(ansL[i] - ansR[i]); }

  cout << setprecision(14) << fixed;
  rep(i,0,q) {
    ld aL = ansL[i] - ansM[i];
    ld aR = ansM[i] - ansR[i];
    cout << area - aL + aR << "\n";
  }
}