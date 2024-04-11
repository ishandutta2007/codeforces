#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::set;
using std::map;
using std::pair;
using std::max;
using std::min;
using std::ostream;
using std::fixed;
using std::ios_base;
using std::setprecision;
using std::make_pair;
using std::string;
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::swap;
using std::complex;
using std::sort;
using std::bitset;
using std::abs;
using std::__gcd;
using std::unordered_set;
using std::unordered_map;
using std::sqrt;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const double kEps = 1e-9;
const double kPi = 2 * acos(0);
struct Point {
  long double x, y;
  Point(long double a = 0, long double b = 0) : x(a), y(b) {}
  Point(const Point& a) : x(a.x), y(a.y) {}
  void operator=(const Point& a) { x = a.x; y = a.y; }
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y); return p; }
  Point operator*(long double a) const { Point p(x * a, y * a); return p; }
  Point operator/(long double a) const { assert(a > kEps); Point p(x / a, y / a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(long double a) { x *= a; y *= a; return *this;}
  Point& operator/=(long double a) { assert(a > kEps); x /= a; y /= a; return *this; }
  
  bool IsZero() const {
    return fabs(x) < kEps && fabs(y) < kEps;
  }
  bool operator==(const Point& a) const {
    return (*this - a).IsZero();
  }
  long double CrossProd(const Point& a) const {
    return x * a.y - y * a.x;
  }
  long double DotProd(const Point& a) const {
    return x * a.x + y * a.y;
  }
  long double Norm() const {
    return sqrt(x * x + y * y);
  }
  void NormalizeSelf() {
    *this /= Norm();
  }
  Point Normalize() {
    Point res(*this);
    res.NormalizeSelf();
    return res;
  }
  long double Dist(const Point& a) const {
    return (*this - a).Norm();
  }
  long double Angle() const {
    return atan2(y, x);
  }
  void RotateSelf(long double angle) {
    long double c = cos(angle);
    long double s = sin(angle);
    long double nx = x * c - y * s;
    long double ny = y * c + x * s;
    y = ny;
    x = nx;
  }
  Point Rotate(long double angle) const {
    Point res(*this);
    res.RotateSelf(angle);
    return res;
  }
  static bool LexCmp(const Point& a, const Point& b) { // FIXME TODO FIXME!!!!!!!!!!!1
    if (a.x != b.x) {
      return a.x < b.x;
    }
    return a.y < b.y;
  }
  friend ostream& operator<<(ostream& out, Point m);
};

ostream& operator<<(ostream& out, Point p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

struct Circle {
  Point center;
  long double r;
  Circle(long double x, long double y, long double rad) {
    center = Point(x, y);
    r = rad;
  }
  Circle(const Point& a, long double rad) : center(a), r(rad) {}
  long double Area() const {
    return kPi * r * r;
  }
  long double Perimeter() const {
    return 2 * kPi * r;
  }
  long double Diameter() const {
    return 2 * r;
  }
  Point RotateRightMost(long double ang) const {
    Point right_most(r, 0);
    Point res = right_most.Rotate(ang);
    return center + res;
  }
  bool operator==(const Circle& c) const {
    return center == c.center && fabs(r - c.r) < kEps;
  }
};

struct Line {
  Point p[2];
  bool is_seg;
  int id;
  Line(Point a, Point b, int id_) {
    p[0] = a;
    p[1] = b;
    id = id_;
  }
  Line() {
  }
  static bool VectorsInOneHalfPlaneCmp(const Line& a, const Line& b) {
    return (a.p[1] - a.p[0]).CrossProd(b.p[1] - b.p[0]) > 0;
  }
  Point NormalVector() {
    Point perp = p[1] - p[0];
    perp.RotateSelf(kPi / 2);
    perp.NormalizeSelf();
    return perp;
  }
};


struct Polygon {
  vector<Point> pts;
  Polygon(vector<Point> pts_) : pts(pts_) {}
  Polygon() : Polygon(vector<Point>()) {}
  void Add(Point p) {
    pts.push_back(p);
  }
  double Area() {
    double area = 0;
    for (int i = 0; i < pts.size(); i++) {
      area += pts[i].CrossProd(pts[(i + 1) % pts.size()]);
    }
    area /= 2;
    return area;
  }
  void OrientCounterclockwise() {
    if (Area() < 0) {
      reverse(pts.begin(), pts.end());
    }
  }
  int next(int a) {
    if (a + 1 < pts.size()) {
      return a + 1;
    }
    return 0;
  }
  pair<int, int> FurthestPair() { // not working, I don't have a slightest idea why
    OrientCounterclockwise();
    int furth = 1;
    pair<int, int> best_pair = make_pair(0, 0);
    double best_dis = 0;
    for (int i = 0; i < pts.size(); i++) {
      Point side = pts[next(i)] - pts[i];
      while (side.CrossProd(pts[furth] - pts[i]) < side.CrossProd(pts[next(furth)] - pts[i])) {
        furth = next(furth);
      }
      vector<int> vec{i, next(i)};
      for (auto ind : vec) {
        if (pts[ind].Dist(pts[furth]) > best_dis) {
          best_pair = make_pair(ind, furth);
          best_dis = pts[ind].Dist(pts[furth]);
        }
      }
      cerr<<"Furthest from: "<<pts[i]<<"-"<<pts[next(i)]<<" is "<<pts[furth]<<endl;
    }
    return best_pair;
  }
  void MakeConvexHull() {
    vector<Point> one_way_hull[2];
    sort(pts.begin(), pts.end(), Point::LexCmp);
    for (int dir = -1; dir <= 1; dir += 2) {
      int hull_num = (dir + 1) / 2;
      auto& H = one_way_hull[hull_num];
      one_way_hull[hull_num].push_back(pts[0]);
      if (pts.size() > 1) {
        H.push_back(pts[1]);
      }
      for (int i = 2; i < pts.size(); i++) {
        while (H.size() >= 2 &&
            dir * (pts[i] - H[H.size() - 2]).CrossProd(H.back() - H[H.size() - 2]) >= 0) {
          H.pop_back();
        }
        H.push_back(pts[i]);
      }
    }
    pts.clear();
    for (auto p : one_way_hull[1]) {
      pts.push_back(p);
    }
    for (int i = (int)one_way_hull[0].size() - 2; i >= 1; i--) {
      pts.push_back(one_way_hull[0][i]);
    }
  }
};

struct Utils {
  static vector<Point> InterCircleCircle(Circle& a, Circle& b) {
    Circle* c = &a;
    Circle* d = &b;
    if (a.r + kEps < b.r) {
      swap(c, d);
    }
    if (a == b) {
      return vector<Point>{a.RotateRightMost(0), a.RotateRightMost(2 * kPi / 3),
          a.RotateRightMost(4 * kPi / 3)};
    }
    Point diff = d->center - c->center;
    long double dis = diff.Norm();
    long double ang = diff.Angle();
    long double longest = max(max(c->r, d->r), dis);
    if (2 * longest > c->r + d->r + dis + kEps) {
      return vector<Point>();
    }
    if (fabs(2 * longest - c->r - d->r - dis) < 2 * kEps) {
      return vector<Point>{c->RotateRightMost(ang)};
    }
    long double proj_diff = (c->r * c->r - d->r * d->r) / dis;
    long double r1_proj = (dis + proj_diff) / 2;
    long double ang_deviation = acos(r1_proj / c->r);
    long double ang1 = ang - ang_deviation;
    long double ang2 = ang + ang_deviation;
    return vector<Point>{c->RotateRightMost(ang1), c->RotateRightMost(ang2)};
  }
  static Point InterLineLine(Line& a, Line& b) { // working fine
    Point vec_a = a.p[1] - a.p[0];
    Point vec_b1 = b.p[1] - a.p[0];
    Point vec_b0 = b.p[0] - a.p[0]; 
    long double tr_area = vec_b1.CrossProd(vec_b0);
    long double quad_area = vec_b1.CrossProd(vec_a) + vec_a.CrossProd(vec_b0);
//     if (abs(quad_area) < kEps) {
//       throw Parallel();
//     }
    return Point(a.p[0] + vec_a * (tr_area / quad_area));
  }
//   static Polygon InterHalfPlanes(vector<Line>& line) { // left side is valid
//     const double R = 2e9;
//     line.push_back(Line(Point(R, R), Point(R, -R)));
//     line.push_back(Line(Point(R, -R), Point(-R, -R)));
//     line.push_back(Line(Point(-R, -R), Point(-R, R)));
//     line.push_back(Line(Point(-R, R), Point(R, R)));
//     vector<Line> half[2]; // half[0] - downward, half[1] - upward
//     for (auto l : line) {
//       half[(l.p[0].x > l.p[1].x) || (l.p[0].x > l.p[1].x && l.p[0].y > l.p[1].y)].PB(l);
//     }
//     for (int dir = -1; dir <= 1; dir += 2) {
//       int hull_num = (dir + 1) / 2;
//       vector<Line>& H = half[hull_num];
//       sort(H.begin(), H.end(), Line::VectorsInOneHalfPlaneCmp);
//       for (int i = 0; i < H.size(); i++) {
//         //TODO
//       }
//       //TODO
//     }
//   }
    
  static Point ProjPointToLine(Point p, Line l) {
    l.p[0] -= p;
    l.p[1] -= p;
    Point normal = l.NormalVector();
    normal *= normal.DotProd(l.p[0]);
    return normal + p;
  }
    
};

const int N = 1e5 + 5;
const LD kInf = 1e9 + 5;
int dp[N], x[N], slope[N];

LD Eval(int l_n, LD xx) {
  return dp[l_n] + xx * slope[l_n];
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  if (n == 1) {
    cout<<0<<endl;
    return 0;
  }
  RE (i, n) {
    cin>>x[i];
  }
  RE (i, n) {
    cin>>slope[i];
  }
  
  vector<Line> lines;
  lines.PB(Line(Point(0, 0), Point(1, slope[1]), 1));
  
  FOR (i, 2, n) {
    int kl = 0, kp = SZ(lines) - 1, faj;
    while (kl <= kp) {
      int aktc = (kl + kp) / 2;
      if (lines[aktc].p[0].x - kEps < x[i]) {
        faj = aktc;
        kl = aktc + 1;
      } else {
        kp = aktc - 1;
      }
    }
    int id = lines[faj].id;
    debug(id);
//     debug3(dp[id], slope[id], x[i]);
    dp[i] = dp[id] + slope[id] * x[i];
    debug(dp[i]);
    Line l(Point(0, dp[i]), Point(1, dp[i] + slope[i]), i);
    while (1) {
      Point p = Utils::InterLineLine(l, lines.back());
      cerr<<"Przecinam ("<<lines.back().p[0]<<" "<<lines.back().p[1]<<") z ("<<l.p[0]<<" "<<l.p[1]<<") i wychodzi "<<p<<endl;
//       cerr<<lines.back().p[0]<<" "<<lines.back().p[1]<<endl;
//       cerr<<l.p[0]<<" "<<l.p[1]<<endl;
      if (p.x < lines.back().p[0].x) {
        lines.pop_back();
      } else {
//         lines.back().p[1].x = p.x;
//         lines.back().p[1].y = Eval(lines.back().id, p.x);
        l.p[0].x = p.x;
        l.p[0].y = Eval(i, p.x);
        lines.PB(l);
        //assert(fabs(l.p[0].y - lines.back().p[1].y) < 1e-3);
        break;
      }
    }
  }
  cout<<dp[n]<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}