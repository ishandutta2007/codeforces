#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


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

using ld  = double;
using P = Point<ld>;
ld eps = 1e-8;


template<class T>
T polygonArea2(vector<Point<T>>& v) {
  T a = v.back().cross(v[0]);
  rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
  return a;
}



template<class P> bool onSegment(P s, P e, P p) {
  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

double segDist(P& s, P& e, P& p) {
  if (s==e) return (p-s).dist();
  auto d = (e-s).dist2(), t = min<ld>(d,max<ld>(.0,(p-s).dot(e-s)));
  return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P>
bool inPolygon(const vector<P> &p, P a, bool strict = false) {
  int cnt = 0, n = sz(p);
  rep(i,0,n) {
    P q = p[(i + 1) % n];
    if (onSegment(p[i], q, a)) return !strict;
    //or: if (segDist(p[i], q, a) <= eps) return !strict;
    cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
  }
  return cnt;
}

int main() {
  ld w, h;
  int n;
  scanf("%lf %lf %d", &w, &h, &n);
  struct Poly {
    vector<P> pts;
    ld area;
    int id;
  };
  vector<Poly> v(n);
  rep(i,0,n) {
    int r;
    cin>>r;
    v[i].pts.resize(r);
    rep(j,0,r) {
      scanf("%lf %lf", &v[i].pts[j].x, &v[i].pts[j].y);
    }
    v[i].id = i;
    v[i].area = abs(polygonArea2(v[i].pts)/2);
  }


  cout << setprecision(6); // << fixed;

  int q;
  scanf("%d", &q);
  rep(i,0,q) {
    P p;
    ld r;
    scanf("%lf %lf %lf", &p.x, &p.y, &r);
    ld area = 0;
    vi pols;
    rep(j,0,n) {
      if(inPolygon(v[j].pts, p)) goto inside;
      rep(k,0,sz(v[j].pts)) {
        if(segDist(v[j].pts[k], v[j].pts[k ? k-1 : sz(v[j].pts)-1], p) < r+eps)
          goto inside;
      }
      continue;
inside:;
       area += v[j].area;
       pols.emplace_back(j);
    }
    cout << area << " ";
    cout << sz(pols) << " ";
    for(int j : pols) cout << j << " ";
    cout << "\n";
  }
}