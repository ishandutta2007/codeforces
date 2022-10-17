#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


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

using P = Point<ll>;

struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};


// Source: ecnerwala github

// check if 180 <= s..t < 360
bool is_reflex(const P& a, const P& b) { auto c = a.cross(b); return c ? (c < 0) : (a.dot(b) < 0); }

// operator < (s,t) for angles in [base,base+2pi)
bool angle_less(const P& base, const P& s, const P& t) {
  int r = is_reflex(base, s) - is_reflex(base, t);
  if(r) return r < 0;
  if(s.cross(t)) return 0 < s.cross(t);
  return s.dist2() < t.dist2();
}
auto angle_cmp(const P& base = P(1,0)) {
  return [base](const P& s, const P& t) { return angle_less(base, s, t); };
}
// sort point around center starting in direction 'dir' and continueing in CCW fashion
auto angle_cmp_center(const P& center, const P& dir = P(1,0)) {
  return [center, dir](const P& s, const P& t) -> bool { return angle_less(dir, s-center, t-center); };
}


template<class P> bool onSegment(P s, P e, P p) {
  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
  auto oa = c.cross(d, a), ob = c.cross(d, b),
       oc = a.cross(b, c), od = a.cross(b, d);
  // Checks if intersection is single non-endpoint point.
  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
    return {(a * ob - b * oa) / (ob - oa)};
  set<P> s;
  if (onSegment(c, d, a)) s.insert(a);
  if (onSegment(c, d, b)) s.insert(b);
  if (onSegment(a, b, c)) s.insert(c);
  if (onSegment(a, b, d)) s.insert(d);
  return {all(s)};
}



template<class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

template<class P>
int sideOf(const P& s, const P& e, const P& p, double eps) {
  auto a = (e-s).cross(p-s);
  double l = (e-s).dist()*eps;
  return (a > l) - (a < -l);
}

void dbg(auto& v) {
  cerr << "Polygon" << endl;
  for(auto p : v) cerr << p.x << " " << p.y << endl;
  cerr << "..." << endl;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi perm(n);
  vector<P> v(n);
  rep(i,0,n) {
    cin >> v[i].x >> v[i].y >> perm[i];
    //v[i].x = rand()%1000;
    //v[i].y = rand()%1000;
    --perm[i];
  }
  //rep(i,0,n) perm[i] = i^1;
  //dbg(v);

  int q = -1;
  rep(i,0,n) if(perm[i] != i) q = i;
  if(q == -1) {
    cout << 0 << endl;
    exit(0);
  }

  UF uf(n);
  rep(i,0,n) uf.join(i, perm[i]);

  vector<pii> ans;
  auto swp = [&](int i, int j) {
    assert(i != j);
    debug(i,j);
    ans.emplace_back(i, j);
    swap(perm[i], perm[j]);
  };

  vi order;
  rep(i,0,n) if(i != q && perm[i] != i) order.emplace_back(i);
  auto cmp = angle_cmp_center(v[q]);
  sort(all(order), [&](int a, int b){ return cmp(v[a], v[b]); });
  debug(order);
  rep(i,0,sz(order)) {
    int x = order[i];
    int y = order[(i+1)%sz(order)];
    if(sideOf(v[x], v[y], v[q]) <= 0) continue;
    if(uf.join(x,y)) swp(x,y);
  }

  while(perm[q] != q) swp(q, perm[q]);

  debug(perm);
  rep(i,0,n) assert(perm[i] == i);

  cout << sz(ans) << endl;
  for(auto [i,j] : ans) cout << i+1 << " " << j+1 << "\n";

  for(auto [i,j] : ans) for(auto [a,b] : ans) {
    if(a == i || a == j || b == i || b == j) continue;
    if(sz(segInter(v[i],v[j], v[a], v[b]))) {
      debug(v[i], v[j], v[a], v[b]);
      assert(false);
    }
  }
}