#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

typedef long double LD;
const LD kEps = 1e-12;
const LD kPi = 2 * acos(0);
struct Point {
  LD x, y;
  Point(LD a = 0, LD b = 0) : x(a), y(b) {}
  Point(const Point& a) : x(a.x), y(a.y) {}
  void operator=(const Point& a) { x = a.x; y = a.y; }
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y); return p; }
  Point operator*(LD a) const { Point p(x * a, y * a); return p; }
  Point operator/(LD a) const { assert(a > kEps); Point p(x / a, y / a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(LD a) { x *= a; y *= a; return *this;}
  Point& operator/=(LD a) { assert(a > kEps); x /= a; y /= a; return *this; }
  
  bool IsZero() const {
    return fabs(x) < kEps && fabs(y) < kEps;
  }
  bool operator==(const Point& a) const {
    return (*this - a).IsZero();
  }
  LD CrossProd(const Point& a) const {
    return x * a.y - y * a.x;
  }
  LD CrossProd(Point a, Point b) const {
    a -= *this;
    b -= *this;
    return a.CrossProd(b);
  }
  LD DotProd(const Point& a) const {
    return x * a.x + y * a.y;
  }
  LD Norm() const {
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
  LD Dist(const Point& a) const {
    return (*this - a).Norm();
  }
  LD Angle() const {
    return atan2(y, x);
  }
  void RotateSelf(LD angle) {
    LD c = cos(angle);
    LD s = sin(angle);
    LD nx = x * c - y * s;
    LD ny = y * c + x * s;
    y = ny;
    x = nx;
  }
  Point Rotate(LD angle) const {
    Point res(*this);
    res.RotateSelf(angle);
    return res;
  }
  static bool LexCmp(const Point& a, const Point& b) {
    if (fabs(a.x - b.x) > kEps) {
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
 
struct Line {
  Point p[2];
  Point diff;
  bool is_seg;
  Line(Point a, Point b, bool is_seg_ = false) {
    p[0] = a;
    p[1] = b;
    is_seg = is_seg_;
    diff = b - a;
  }
  Line() {
  }
  Point& operator[](int a) {
    return p[a];
  }
  static bool VectorsInOneHalfPlaneCmp(Line a, Line b) {
    return (a[1] - a[0]).CrossProd(b[1] - b[0]) > 0;
  }
  Point NormalVector() {
    Point perp = p[1] - p[0];
    perp.RotateSelf(kPi / 2);
    perp.NormalizeSelf();
    return perp;
  }
  vector<LD> LineEqNormLD() { // seems ok
    LD A = p[1].y - p[0].y;
    LD B = p[0].x - p[1].x;
    LD C = -(A * p[0].x + B * p[0].y);
    assert(fabs(A * p[1].x + B * p[1].y + C) < kEps);
    LD norm = sqrt(A * A + B * B);
    vector<LD> res{A, B, C};
    for (auto& x : res) { x /= norm; }
    if (A < -kEps || (fabs(A) < kEps && B < -kEps)) {
      for (auto& x : res) { x *= -1; }
    }
    return res;
  }
  
  // assumes that coordinates are integers!
  vector<int> LineEqNormInt() { // seems ok
    int A = round(p[1].y - p[0].y);
    int B = round(p[0].x - p[1].x);
    int C = -(A * p[0].x + B * p[0].y);
    int gcd = abs(__gcd(A, __gcd(B, C)));
    vector<int> res{A, B, C};
    for (auto& x : res) { x /= gcd; }
    if (A < 0 || (A == 0 && B < 0)) {
      for (auto& x : res) { x *= -1; }
    }
    return res;
  }
};
struct Circle {
  Point center;
  LD r;
  Circle(LD x, LD y, LD rad) {
    center = Point(x, y);
    r = rad;
  }
  Circle(const Point& a, LD rad) : center(a), r(rad) {}
  LD Area() const {
    return kPi * r * r;
  }
  LD Perimeter() const {
    return 2 * kPi * r;
  }
  LD Diameter() const {
    return 2 * r;
  }
  Point RotateRightMost(LD ang) const {
    Point right_most(r, 0);
    Point res = right_most.Rotate(ang);
    return center + res;
  }
  bool operator==(const Circle& c) const {
    return center == c.center && fabs(r - c.r) < kEps;
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
    LD dis = diff.Norm();
    LD ang = diff.Angle();
    LD longest = max(max(c->r, d->r), dis);
    if (2 * longest > c->r + d->r + dis + kEps) {
      return vector<Point>();
    }
    if (fabs(2 * longest - c->r - d->r - dis) < 2 * kEps) {
      return vector<Point>{c->RotateRightMost(ang)};
    }
    LD proj_diff = (c->r * c->r - d->r * d->r) / dis;
    LD r1_proj = (dis + proj_diff) / 2;
    LD ang_deviation = acos(r1_proj / c->r);
    LD ang1 = ang - ang_deviation;
    LD ang2 = ang + ang_deviation;
    return vector<Point>{c->RotateRightMost(ang1), c->RotateRightMost(ang2)};
  }
  static Point InterLineLine(Line& a, Line& b) { // working fine
    Point vec_a = a[1] - a[0];
    Point vec_b1 = b[1] - a[0];
    Point vec_b0 = b[0] - a[0]; 
    LD tr_area = vec_b1.CrossProd(vec_b0);
    LD quad_area = vec_b1.CrossProd(vec_a) + vec_a.CrossProd(vec_b0);
//     if (abs(quad_area) < kEps) {
//       throw Parallel();
//     }
    return Point(a[0] + vec_a * (tr_area / quad_area));
  }
//   static Polygon InterHalfPlanes(vector<Line>& line) { // left side is valid
//     const double R = 2e9;
//     line.push_back(Line(Point(R, R), Point(R, -R)));
//     line.push_back(Line(Point(R, -R), Point(-R, -R)));
//     line.push_back(Line(Point(-R, -R), Point(-R, R)));
//     line.push_back(Line(Point(-R, R), Point(R, R)));
//     vector<Line> half[2]; // half[0] - downward, half[1] - upward
//     for (auto l : line) {
//       half[(l[0].x > l[1].x) || (l[0].x > l[1].x && l[0].y > l[1].y)].PB(l);
//     }
//     for (int dir = -1; dir <= 1; dir += 2) {
//       int hull_num = (dir + 1) / 2;
//       vector<Line>& H = half[hull_num];
//       sort(H.begin(), H.end(), Line::VectorsInOneHalfPlaneCmp);
//       for (int i = 0; i < SZ(H); i++) {
//         //TODO
//       }
//       //TODO
//     }
//   }
    
  static Point ProjPointToLine(Point p, Line l) { ///Tested
    l[0] -= p;
    l[1] -= p;
    Point normal = l.NormalVector();
    normal *= normal.DotProd(l[0]);
    return normal + p;
  }
  
  static Point ReflectPtWRTLine(Point p, Line l) {
    Point proj = ProjPointToLine(p, l);
    return proj * 2 - p;
  }
  
  static vector<Point> InterCircleLine(Circle c, Line l) { /// Tested here: http://codeforces.com/gym/100554/submission/10197624
    Point proj = ProjPointToLine(c.center, l);
    LD dis_proj = c.center.Dist(proj);
    if (dis_proj > c.r + kEps) { return vector<Point>(); }
    LD a = sqrt(c.r * c.r - dis_proj * dis_proj);
    Point dir = l[1] - l[0];
    dir.NormalizeSelf();
    vector<Point> cands{proj + dir * a, proj - dir * a};
    if (cands[0].Dist(cands[1]) < kEps) { return vector<Point>{proj}; }
    return cands;
  }
  
  static bool PtBelongToLine(Line l, Point p) {
    return fabs(l[0].CrossProd(l[1], p)) < kEps;
  }
  
  static bool PtBelongToSeg(Line l, Point p) { // seems ok
    return fabs(p.Dist(l[0]) + p.Dist(l[1]) - l[0].Dist(l[1])) < kEps;
  }
  
  static vector<Point> InterCircleSeg(Circle c, Line l) { //seems ok
    vector<Point> from_line = InterCircleLine(c, l);
    vector<Point> res;
    for (auto p : from_line) {
      if (PtBelongToSeg(l, p)) { res.PB(p); }
    }
    return res;
  }
  
  static vector<Point> TangencyPtsToCircle(Circle c, Point p) { // seems ok
    assert(c.center.Dist(p) > c.r + kEps); // or return vector<Point>() if needed
    Point mid = (c.center + p) / 2;
    Circle aux_circ = Circle(mid, c.center.Dist(p) / 2);
    return InterCircleCircle(aux_circ, c);
  }
  
  static bool AreParallel(Line l1, Line l2) { // seems ok
    return fabs(l1[0].CrossProd(l2[0], l1[1]) - l1[0].CrossProd(l2[1], l1[1])) < kEps;
  }
  
  // returns a vector of points such that their convex hull is intersection of those segments
  // SZ(0) = 0 => empty intersection, SZ(1) = 1 => intersection is a point, SZ(2) => intersection is a segment
  static vector<Point> InterSegs(Line l1, Line l2) { // seems ok
    if (!Point::LexCmp(l1[0], l1[1])) { swap(l1[0], l1[1]); }
    if (!Point::LexCmp(l2[0], l2[1])) { swap(l2[0], l2[1]); }
    if (AreParallel(l1, l2)) {
      if (!PtBelongToLine(l1, l2[0])) { return vector<Point>(); }
      vector<Point> ends(2);
      for (int tr = 0; tr < 2; tr++) {
        if (Point::LexCmp(l1[tr], l2[tr]) ^ tr) {
          ends[tr] = l2[tr];
        } else {
          ends[tr] = l1[tr];
        }
      }
      if ((ends[1] - ends[0]).IsZero()) {
        ends.pop_back();
      }
      if (SZ(ends) == 2 && Point::LexCmp(ends[1], ends[0])) { return vector<Point>(); }
      return ends;
    } else {
      Point p = InterLineLine(l1, l2);
      if (PtBelongToSeg(l1, p) && PtBelongToSeg(l2, p)) { return vector<Point>{p}; }
      return vector<Point>();
    }
  }
  static LD Angle(Point P, Point Q, Point R) { // angle PQR
    LD ang2 = (P - Q).Angle();
    LD ang1 = (R - Q).Angle();
    LD ans = ang1 - ang2;
    if (ans < kEps) {
      ans += 2 * kPi;
    }
    return ans;
  }
  static LD DiskInterArea(Circle c1, Circle c2) { // tested here: http://opentrains.snarknews.info/~ejudge/team.cgi?contest_id=006254 problem I
    if (c1.r < c2.r) {
      swap(c1, c2);
    }
    LD dist = c1.center.Dist(c2.center);
    if (c1.r + c2.r < dist + kEps) {
      return 0;
    }
    if (c1.r - c2.r > dist - kEps) {
      return kPi * c2.r * c2.r;
    }
    vector<Point> inters = Utils::InterCircleCircle(c1, c2);
    LD cross = (inters[0] - c1.center).CrossProd(inters[1] - c1.center);
    if (cross < kEps) {
      swap(inters[0], inters[1]);
    }
    LD res = 0;
    LD ang1 = Angle(inters[0], c1.center, inters[1]);
    res += ang1 * c1.r * c1.r;
    LD ang2 = Angle(inters[1], c2.center, inters[0]);
    res += ang2 * c2.r * c2.r;
    res -= (inters[0] - c1.center).CrossProd(inters[1] - c1.center) + (inters[1] - c2.center).CrossProd(inters[0] - c2.center);
    return res / 2;
  }
};
const int N = 2e3 + 5;
Line line[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  int through_orig = 0;
  vector<Line> lines;
  RE (i, n) {
    int a, b, c;
    cin>>a>>b>>c;
    if (c == 0) {
      through_orig++;
      continue;
    }
    //Line& line[i];
    if (a == 0) {
      line[i] = Line({0, 1. * c / b}, {1, 1. * c / b});
    } else if (b == 0) {
      line[i] = Line({1. * c / a, 0}, {1. * c / a, 1});
    } else {
      line[i] = Line({0, 1. * c / b}, {1, 1. * (c - a) / b});
    }
//     REP (tr, 2) {
//       assert(Utils::PtBelongToLine(line[i], line[i].p[tr]));
//     }
    lines.PB(line[i]);
  }
  int to_add = 0;
  Point orig{0, 0};
  int po2 = through_orig * (through_orig - 1) / 2;
  int ans = (n - through_orig) * po2 + po2 * (through_orig - 2) / 3;
  for (int ii = 0; ii < SZ(lines); ii++) {
    vector<LD> angs;
    for (int jj = 0; jj < SZ(lines); jj++) {
      if (ii == jj) { continue; }
      Point inter = Utils::InterLineLine(lines[ii], lines[jj]);
      
      /*Point P1 = inter + lines[jj].diff;
      Point P2 = inter - lines[jj].diff;*/
      if (inter.CrossProd(lines[jj].diff) > 0) {
        angs.PB(Utils::Angle(orig, inter, inter + lines[jj].diff));
      } else {
        angs.PB(Utils::Angle(orig, inter, inter - lines[jj].diff));
      }
    }
    angs.PB(-10);
    sort(ALL(angs));
    angs.PB(10);
    debugv(angs);
    int last = 0;
    for (int i = 1; i < SZ(angs); i++) {
      if (abs(angs[i] - angs[i - 1]) < kEps) {
        last++;
      } else {
        to_add += last * (last - 1) / 2;
        last = 1;
      }
    }
  }
  assert(to_add % 3 == 0);
  cout<<ans + to_add / 3<< endl;
  
  
  
//   
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}