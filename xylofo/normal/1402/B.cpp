#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

struct Line {
  using ll = long double;
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  using ll = long double;
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const ll inf = 1/.0;
  ll div(ll a, ll b) { // floored division
    return a / b;}
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

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

using ld = long double;
using P = Point<ld>;
const ld pi = acos(-1);
const ld eps = 1e-14;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<pair<P,P>> v(n);
  rep(i,0,n) {
    ll xl, xr, y;
    cin>>xl>>xr>>y;
    //xl = rand()%int(1e7); xr = xl + 1; y = 1+rand()%2;

    v[i] = {P{xl,y}, P{xr,y}};
  }

  vector<pair<ld,int>> deltas;
  deltas.emplace_back(pi/2,0);

  rep(i,0,n) rep(j,i+1,n) {
    if(v[i].first.y == v[j].first.y) continue;
    P p1, p2;
    if(v[i].first.y > v[j].first.y) {
      p1 = v[i].first - v[j].second;
      p2 = v[i].second - v[j].first;
    }
    else {
      p1 = v[j].first - v[i].second;
      p2 = v[j].second - v[i].first;
    }
    p1 = P()-p1;
    p2 = P()-p2;
    ld t1 = -p1.angle();
    ld t2 = -p2.angle();
    assert(0 <= t1 && t1 <= t2 && t2 <= pi);
    deltas.emplace_back(t1+eps, 1);
    deltas.emplace_back(t2-eps, -1);
  }
  debug("hej");

  LineContainer lefts, rights;
  rep(i,0,n) {
    rights.add(v[i].second.y, v[i].second.x);
    lefts.add(-v[i].first.y, -v[i].first.x);
  }

  ld lstq = 1e18;
  ld ans = 1.0/0.0;
  auto go = [&](ld q) {
    if(abs(q-lstq) <= eps) return;
    lstq = q;
    P dir(1,0);
    dir = dir.rotate(-q);
    ld a = -dir.x/dir.y;
    ld mn = -lefts.query(a);
    ld mx = rights.query(a);
    //debug(dir, mx - mn);
    ans = min(ans, mx - mn);
  };

  sort(all(deltas));
  int d = 0;
  for(auto [q,c] : deltas) {
    if(d == 0) go(q);
    d += c;
    if(d == 0) go(q);
    assert(d >= 0);
  }


  cout << setprecision(14) << fixed;
  cout << ans << endl;
}