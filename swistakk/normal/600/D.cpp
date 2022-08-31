// Wojtek Nadara
// Library that implements geometrical algorithms
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define st first
#define nd second
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using namespace std;
typedef long double LD;
const LD kEps = 1e-9;
const LD kPi = 2 * acos(0);
LD Sq(LD x) {
  return x * x;
}
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
    return abs(x) < kEps && abs(y) < kEps;
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
    if (abs(a.x - b.x) > kEps) {
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
    return center == c.center && abs(r - c.r) < kEps;
  }
};

struct Line {
  Point p[2];
  bool is_seg;
  Line(Point a, Point b, bool is_seg_ = false) {
    p[0] = a;
    p[1] = b;
    is_seg = is_seg_;
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
  
  // (A, B, C) such that A^2 + B^2 = 1, (A, B) > (0, 0)
  vector<LD> LineEqNormLD() { // seems ok
    LD A = p[1].y - p[0].y;
    LD B = p[0].x - p[1].x;
    LD C = -(A * p[0].x + B * p[0].y);
    assert(abs(A * p[1].x + B * p[1].y + C) < kEps);
    LD norm = sqrt(A * A + B * B);
    vector<LD> res{A, B, C};
    for (auto& x : res) { x /= norm; }
    if (A < -kEps || (abs(A) < kEps && B < -kEps)) {
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

struct Utils {
  // 0, 1, 2 or 3 pts. In case of 3 pts it means they are equal
  // TODO get rid of those idiotic pointers and references, copying here would be no harm 
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
    if (abs(2 * longest - c->r - d->r - dis) < 2 * kEps) {
      return vector<Point>{c->RotateRightMost(ang)};
    }
    LD proj_diff = (c->r * c->r - d->r * d->r) / dis;
    LD r1_proj = (dis + proj_diff) / 2;
    LD ang_deviation = acos(r1_proj / c->r);
    LD ang1 = ang - ang_deviation;
    LD ang2 = ang + ang_deviation;
    return vector<Point>{c->RotateRightMost(ang1), c->RotateRightMost(ang2)};
  }
  
  //TODO change it to vector<Point>, intersection could be nothing, point or line
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
    
    
  // TODO break idiotic dependence
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
    return abs(l[0].CrossProd(l[1], p)) < kEps;
  }
  
  static bool PtBelongToSeg(Line l, Point p) { // seems ok
    return abs(p.Dist(l[0]) + p.Dist(l[1]) - l[0].Dist(l[1])) < kEps;
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
    return abs(l1[0].CrossProd(l2[0], l1[1]) - l1[0].CrossProd(l2[1], l1[1])) < kEps;
  }
  
  // returns a vector of points such that their convex hull is intersection of those segments
  // SZ(res) == 0 => empty intersection, SZ(res) == 1 => intersection is a point, SZ(res) == 2 => intersection is a segment
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
  
  //TODO break the dependence and test precision on Educational Round 2
  static LD DiskInterArea(Circle c1, Circle c2) { // tested here: http://opentrains.snarknews.info/~ejudge/team.cgi?contest_id=006254 problem I
    if (c1.r < c2.r) {
      swap(c1, c2);
    }
    LD d = c1.center.Dist(c2.center);
    if (c1.r + c2.r < d + kEps) {
      return 0;
    }
    if (c1.r - c2.r > d - kEps) {
      return kPi * Sq(c2.r);
    }
    LD alfa = acos((Sq(d) + Sq(c1.r) - Sq(c2.r)) / (2 * d * c1.r));
    LD beta = acos((Sq(d) + Sq(c2.r) - Sq(c1.r)) / (2 * d * c2.r));
    return alfa * Sq(c1.r) + beta * Sq(c2.r) - sin(2 * alfa) * Sq(c1.r) / 2 - sin(2 * beta) * Sq(c2.r) / 2;
//     vector<Point> inters = Utils::InterCircleCircle(c1, c2);
//     LD cross = (inters[0] - c1.center).CrossProd(inters[1] - c1.center);
//     if (cross < kEps) {
//       swap(inters[0], inters[1]);
//     }
//     LD res = 0;
//     LD ang1 = Angle(inters[0], c1.center, inters[1]);
//     res += ang1 * c1.r * c1.r;
//     LD ang2 = Angle(inters[1], c2.center, inters[0]);
//     res += ang2 * c2.r * c2.r;
//     res -= (inters[0] - c1.center).CrossProd(inters[1] - c1.center) + (inters[1] - c2.center).CrossProd(inters[0] - c2.center);
//     return res / 2;
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
    for (int i = 0; i < SZ(pts); i++) {
      area += pts[i].CrossProd(pts[(i + 1) % SZ(pts)]);
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
    if (a + 1 < SZ(pts)) {
      return a + 1;
    }
    return 0;
  }
  pair<int, int> FurthestPair() { // tested here: http://codeforces.com/contest/333/submission/11058065
    MakeConvexHull();
    OrientCounterclockwise();
    int furth = 1;
    pair<int, int> best_pair = make_pair(0, 0);
    double best_dis = 0;
    for (int i = 0; i < SZ(pts); i++) {
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
  void MakeConvexHull() { // tested everywhere http://codeforces.com/contest/333/submission/11058065
    vector<Point> one_way_hull[2];
    sort(pts.begin(), pts.end(), Point::LexCmp);
    for (int dir = -1; dir <= 1; dir += 2) {
      int hull_num = (dir + 1) / 2;
      auto& H = one_way_hull[hull_num];
      one_way_hull[hull_num].push_back(pts[0]);
      if (SZ(pts) > 1) {
        H.push_back(pts[1]);
      }
      for (int i = 2; i < SZ(pts); i++) {
        while (SZ(H) >= 2 &&
            dir * (pts[i] - H[SZ(H) - 2]).CrossProd(H.back() - H[SZ(H) - 2]) > -kEps) {
          H.pop_back();
        }
        H.push_back(pts[i]);
      }
    }
    pts.clear();
    for (auto p : one_way_hull[1]) {
      pts.push_back(p);
    }
    for (int i = SZ(one_way_hull[0]) - 2; i >= 1; i--) {
      pts.push_back(one_way_hull[0][i]);
    }
  }
  vector<vector<bool>> InsideDiagonalsMatrix() { // tested here: http://codeforces.com/contest/438/submission/11063385
    int n = pts.size();
    vector<vector<bool>> res(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        Line diag(pts[i], pts[j]);
        if (i == j || abs(i - j) == 1 || abs(i - j) == n - 1) { continue; }
        res[i][j] = 1;
        for (int k = 0; k < n; k++) {
          int kk = next(k);
          Line side(pts[k], pts[kk]);
          if (k == i || k == j || kk == i || kk == j) { continue; }
          vector<Point> inter = Utils::InterSegs(diag, side);
          if (SZ(inter)) { res[i][j] = 0; }
        }
        int act = next(i);
        LD areas[2] = {0, 0};
        int passed_j = 0;
        while (act != i) {
          passed_j |= (act == j);
          areas[passed_j] += pts[i].CrossProd(pts[act], pts[next(act)]);
          act = next(act);
        }
        if (areas[0] * areas[1] < kEps) {
          res[i][j] = 0;
        }
      }
    }
    return res;
  }
};



int main() {
  cout<<fixed<<setprecision(10);
  int x1, y1, r1, x2, y2, r2;
  cin>>x1>>y1>>r1>>x2>>y2>>r2;
  Circle c1{{x1, y1}, r1}, c2{{x2, y2}, r2};
  cout<<Utils::DiskInterArea(c1, c2)<<endl;
  return 0;
}