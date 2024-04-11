#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#if !defined(M_PI)
#define M_PI 3.14159265358979323846 /* pi */
#endif
#if !defined(M_PI_2)
#define M_PI_2 1.57079632679489661923 /* pi/2 */
#endif
constexpr double kEps = 1e-10;
constexpr int kPrecision = 8;
int Cmp(const double &x) {
  if (std::fabs(x) < kEps) return 0;
  return x >= kEps ? 1 : -1;
}
class Vector;
class Point {
 public:
  double x_, y_;
  Point() {}
  Point(double x, double y) : x_(x), y_(y) {}
  Point(const std::pair<double, double> &b) : x_(b.first), y_(b.second) {}
  Point &operator=(const std::pair<double, double> &);
  Point &operator=(const Point &);
  Point operator+(const Vector &) const;
  Point operator-(const Vector &) const;
  Point &operator+=(const Vector &b) { return *this = *this + b; }
  Point &operator-=(const Vector &b) { return *this = *this - b; }
  friend std::istream &operator>>(std::istream &, Point &);
  friend std::ostream &operator<<(std::ostream &, const Point &);
  ~Point() {}
};
class Vector {
 public:
  double x_, y_;
  Vector() {}
  Vector(double x, double y) : x_(x), y_(y) {}
  Vector(const std::pair<double, double> &b) : x_(b.first), y_(b.second) {}
  Vector(Point a, Point b) {
    x_ = b.x_ - a.x_;
    y_ = b.y_ - a.y_;
  }
  double Magnitude() const { return std::hypot(x_, y_); }
  double PolarAngle() const { return std::atan2(y_, x_); }
  Vector &operator=(const std::pair<double, double> &);
  Vector &operator=(const Vector &);
  Vector operator+(const Vector &) const;
  Vector operator-(const Vector &) const;
  Vector operator*(const double &) const;
  Vector operator/(const double &) const;
  Vector &operator+=(const Vector &b) { return *this = *this + b; };
  Vector &operator-=(const Vector &b) { return *this = *this - b; };
  Vector &operator*=(const double &b) { return *this = *this * b; };
  Vector &operator/=(const double &b) { return *this = *this / b; };
  void Rotate(const double &);
  friend std::istream &operator>>(std::istream &, Vector &);
  friend std::ostream &operator<<(std::ostream &, const Vector &);
  ~Vector() {}
};
class Line {
 public:
  Point p_;
  Vector v_;
  Line() {}
  Line(Point p, Vector v) : p_(p), v_(v) {}
  friend std::istream &operator>>(std::istream &, Line &);
  friend std::ostream &operator<<(std::ostream &, const Line &);
  ~Line() {}
};
class Segment {
 public:
  Point a_, b_;
  Segment() {}
  Segment(Point a, Point b) : a_(a), b_(b) {}
  friend std::istream &operator>>(std::istream &, Segment &);
  friend std::ostream &operator<<(std::ostream &, const Segment &);
  ~Segment() {}
};
class Circle {
 public:
  Point o_;
  double r_;
  Circle() {}
  Circle(Point o, double r) : o_(o), r_(r) {}
  Circle(Point A);
  Circle(Point A, Point B);
  Circle(Point A, Point B, Point C);
  Circle(const std::pair<Point, double> &b) : o_(b.first), r_(b.second) {}
  ~Circle() {}
  friend std::istream &operator>>(std::istream &, Circle &);
  friend std::ostream &operator<<(std::ostream &, const Circle &);
};
typedef std::vector<Point> Polygon;
Point &Point::operator=(const std::pair<double, double> &b) {
  this->x_ = b.first;
  this->y_ = b.second;
  return *this;
}
Point &Point::operator=(const Point &b) {
  this->x_ = b.x_;
  this->y_ = b.y_;
  return *this;
}
Point Point::operator+(const Vector &b) const {
  return Point(x_ + b.x_, y_ + b.y_);
}
Point Point::operator-(const Vector &b) const {
  return Point(x_ - b.x_, y_ - b.y_);
}
std::istream &operator>>(std::istream &in, Point &a) {
  in >> a.x_ >> a.y_;
  return in;
}
std::ostream &operator<<(std::ostream &out, const Point &a) {
  out << std::setprecision(kPrecision) << std::fixed << a.x_ << ',' << a.y_;
  return out;
}
double Dis(const Point &a, const Point &b) {
  return std::hypot(a.x_ - b.x_, a.y_ - b.y_);
}
Vector &Vector::operator=(const std::pair<double, double> &b) {
  this->x_ = b.first;
  this->y_ = b.second;
  return *this;
}
Vector &Vector::operator=(const Vector &b) {
  this->x_ = b.x_;
  this->y_ = b.y_;
  return *this;
}
Vector Vector::operator+(const Vector &b) const {
  return Vector(x_ + b.x_, y_ + b.y_);
}
Vector Vector::operator-(const Vector &b) const {
  return Vector(x_ - b.x_, y_ - b.y_);
}
Vector Vector::operator*(const double &b) const {
  return Vector(x_ * b, y_ * b);
}
Vector Vector::operator/(const double &b) const {
  return Vector(x_ / b, y_ / b);
}
void Vector::Rotate(const double &angle) {
  double x = x_, y = y_;
  x_ = x * std::cos(angle) - y * std::sin(angle);
  y_ = x * std::sin(angle) + y * std::cos(angle);
}
std::istream &operator>>(std::istream &in, Vector &a) {
  in >> a.x_ >> a.y_;
  return in;
}
std::ostream &operator<<(std::ostream &out, const Vector &a) {
  out << std::setprecision(kPrecision) << std::fixed << a.x_ << ',' << a.y_;
  return out;
}
double Dot(const Vector &a, const Vector &b) {
  return a.x_ * b.x_ + a.y_ * b.y_;
}
double Cross(const Vector &a, const Vector &b) {
  return a.x_ * b.y_ - b.x_ * a.y_;
}
bool IsCcw(const Vector &a, const Vector &b) { return Cmp(Cross(a, b)) > 0; }
Vector Rotate(const Vector &a, const double &angle) {
  return Vector(a.x_ * std::cos(angle) - a.y_ * std::sin(angle),
                a.x_ * std::sin(angle) + a.y_ * std::cos(angle));
}
std::istream &operator>>(std::istream &in, Line &a) {
  Point A, B;
  in >> A >> B;
  a = Line(A, Vector(A, B));
  return in;
}
std::ostream &operator<<(std::ostream &out, const Line &a) {
  out << a.p_ << ' ' << a.p_ + a.v_;
  return out;
}
double Dis(const Point &a, const Line &l) {
  Vector v(l.p_, a);
  return std::fabs(Cross(v, l.v_)) / l.v_.Magnitude();
}
Point Projection(const Point &A, const Line &l) {
  Vector a(l.p_, A), v = l.v_ * Dot(a, l.v_) / Dot(l.v_, l.v_);
  return l.p_ + v;
}
Point Intersection(const Line &a, const Line &b) {
  Vector v(a.p_, b.p_);
  double k = Cross(a.v_, v) / Cross(b.v_, a.v_);
  return b.p_ + b.v_ * k;
}
std::istream &operator>>(std::istream &in, Segment &a) {
  in >> a.a_ >> a.b_;
  return in;
}
std::ostream &operator<<(std::ostream &out, const Segment &a) {
  out << std::setprecision(kPrecision) << std::fixed << a.a_ << ' ' << a.b_;
  return out;
}
bool IsIntersecting(const Segment &a, const Segment &b) {
  Vector v1(a.a_, a.b_), v2(b.a_, b.b_);
  return Cmp(Cross(v1, Vector(a.a_, b.a_))) *
                 Cmp(Cross(v1, Vector(a.a_, b.b_))) <
             0 &&
         Cmp(Cross(v2, Vector(b.a_, a.a_))) *
                 Cmp(Cross(v2, Vector(b.a_, a.b_))) <
             0;
}
Point Intersection(const Segment &a, const Segment &b) {
  return Intersection(Line(a.a_, Vector(a.a_, a.b_)),
                      Line(b.a_, Vector(b.a_, b.b_)));
}
double Dis(const Point &A, const Segment &b) {
  Vector v1(b.a_, b.b_), v2(b.a_, A), v3(b.b_, A);
  if (Cmp(Dot(v1, v2)) < 0)
    return v2.Magnitude();
  else if (Cmp(Dot(v1, v3)) < 0)
    return v3.Magnitude();
  else
    return std::fabs(Cross(v1, v2)) / v1.Magnitude();
}
Circle::Circle(Point A) {
  o_ = A;
  r_ = 0.0;
}
Circle::Circle(Point A, Point B) {
  o_ = Point((A.x_ + B.x_) / 2, (A.y_ + B.y_) / 2);
  r_ = Dis(o_, A);
}
Circle::Circle(Point A, Point B, Point C) {
  double a, b, c, d, e, f;
  a = B.y_ - A.y_;
  b = C.y_ - A.y_;
  c = B.x_ - A.x_;
  d = C.x_ - A.x_;
  f = C.x_ * C.x_ + C.y_ * C.y_ - A.x_ * A.x_ - A.y_ * A.y_;
  e = B.x_ * B.x_ + B.y_ * B.y_ - A.x_ * A.x_ - A.y_ * A.y_;
  o_ = Point((a * f - b * e) / (2 * a * d - 2 * b * c),
             (d * e - c * f) / (2 * a * d - 2 * b * c));
  r_ = Dis(o_, A);
}
std::istream &operator>>(std::istream &in, Circle &a) {
  in >> a.o_ >> a.r_;
  return in;
}
std::ostream &operator<<(std::ostream &out, const Circle &a) {
  out << a.o_ << ',' << a.r_;
  return out;
}
bool InCircle(const Circle &O, const Point &A) {
  return Cmp(Dis(O.o_, A) - O.r_) <= 0;
}
Circle InscribedCircle(const Point &A, const Point &B, const Point &C) {
  double a = Dis(B, C), b = Dis(A, C), c = Dis(A, B), p = (a + b + c) / 2;
  return Circle(Point((a * A.x_ + b * B.x_ + c * C.x_) / (a + b + c),
                      (a * A.y_ + b * B.y_ + c * C.y_) / (a + b + c)),
                sqrt((p - a) * (p - b) * (p - c) / p));
}
std::vector<Point> Intersection(const Line &l, const Circle &O) {
  std::vector<Point> ans;
  if (Cmp(Dis(O.o_, l) - O.r_) < 0) {
    Point p = Projection(O.o_, l);
    double d = Dis(O.o_, p), t = std::sqrt(O.r_ * O.r_ - d * d);
    Vector v(l.v_ * t / l.v_.Magnitude());
    ans.emplace_back(p + v);
    ans.emplace_back(p - v);
  } else if (!Cmp(Dis(O.o_, l) - O.r_)) {
    ans.emplace_back(Projection(O.o_, l));
  }
  return ans;
}
std::vector<Point> Intersection(const Circle &O1, const Circle &O2) {
  std::vector<Point> ans;
  double d = Dis(O1.o_, O2.o_);
  Vector v(O1.o_, O2.o_);
  if (Cmp(d - O1.r_ - O2.r_) < 0) {
    double angle =
        std::acos((O1.r_ * O1.r_ + d * d - O2.r_ * O2.r_) / (2 * O1.r_ * d));
    ans.emplace_back(O1.o_ + Rotate(v, angle) * O1.r_ / d);
    ans.emplace_back(O1.o_ + Rotate(v, -angle) * O1.r_ / d);
  } else if (!Cmp(d - O1.r_ - O2.r_)) {
    ans.emplace_back(O1.o_ + v * O1.r_ / d);
  }
  return ans;
}
std::vector<Line> Tangents(const Point &P, const Circle &O) {
  std::vector<Line> ans;
  Vector a(P, O.o_);
  double d = a.Magnitude();
  if (Cmp(d - O.r_) > 0) {
    double angle = std::asin(O.r_ / d);
    ans.emplace_back(P, Rotate(a, angle));
    ans.emplace_back(P, Rotate(a, -angle));
  } else if (Cmp(d - O.r_) == 0) {
    ans.emplace_back(P, Rotate(a, M_PI_2));
  }
  return ans;
}
Circle SmallestCircle(const std::vector<Point> &b) {
  std::vector<Point> a(b);
  std::mt19937 mt_rand(
      std::chrono::_V2::steady_clock::now().time_since_epoch().count());
  std::shuffle(a.begin(), a.end(), mt_rand);
  Circle O(a.front());
  for (std::size_t i = 1; i < a.size(); i++)
    if (!InCircle(O, a[i])) {
      O = Circle(a[i]);
      for (std::size_t j = 0; j < i; j++)
        if (!InCircle(O, a[j])) {
          O = Circle(a[i], a[j]);
          for (std::size_t k = 0; k < j; k++)
            if (!InCircle(O, a[k])) O = Circle(a[i], a[j], a[k]);
        }
    }
  return O;
}
double Area(const Polygon &a) {
  double ans = 0.0;
  for (std::size_t i = 1; i + 1 < a.size(); i++)
    ans += Cross(Vector(a.front(), a[i]), Vector(a.front(), a[i + 1]));
  return ans / 2;
}
Polygon ConvexHull(const std::vector<Point> &b) {
  std::vector<Point> a(b), s;
  std::swap(*a.begin(),
            *std::min_element(a.begin(), a.end(),
                              [](const Point &x, const Point &y) -> bool {
                                return x.y_ < y.y_;
                              }));
  s.emplace_back(a[0]);
  std::sort(a.begin() + 1, a.end(),
            [&a](const Point &x, const Point &y) -> bool {
              return IsCcw(Vector(*a.begin(), x), Vector(*a.begin(), y));
            });
  s.emplace_back(a[1]);
  int top = 1;
  for (std::size_t i = 2; i < a.size(); i++) {
    while (top &&
           !IsCcw(Vector(s[top - 1], s.back()), Vector(s[top - 1], a[i]))) {
      s.pop_back();
      top--;
    }
    s.emplace_back(a[i]);
    top++;
  }
  return s;
}
long long a, b, alpha;
Point O(0.0, 0.0);
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> a >> b >> alpha;
  if (alpha == 0 || alpha == 180) {
    std::cout << a * b;
    return 0;
  }
  Point A(a / 2.0, b / 2.0), B(-a / 2.0, b / 2.0), C(-a / 2.0, -b / 2.0),
      D(a / 2.0, -b / 2.0), E, F, G, H;
  Vector OA(O, A), OB(O, B), OC(O, C), OD(O, D),
      OE = Rotate(OA, alpha * M_PI / 180), OF = Rotate(OB, alpha * M_PI / 180),
      OG = Rotate(OC, alpha * M_PI / 180), OH = Rotate(OD, alpha * M_PI / 180);
  E = O + OE;
  F = O + OF;
  G = O + OG;
  H = O + OH;
  std::vector<Segment> ra = {Segment(A, B), Segment(B, C), Segment(C, D),
                             Segment(D, A)},
                       rb = {Segment(E, F), Segment(F, G), Segment(G, H),
                             Segment(H, E)};
  Polygon ans;
  for (auto &&i : ra)
    for (auto &&j : rb)
      if (IsIntersecting(i, j)) ans.emplace_back(Intersection(i, j));
  ans = ConvexHull(ans);
  std::cout << std::setprecision(kPrecision) << std::fixed << Area(ans);
  return 0;
}