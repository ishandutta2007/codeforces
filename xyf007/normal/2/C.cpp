#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <vector>
#define M_PI_2 1.57079632679489661923
constexpr double kEps = 1e-10;
constexpr int kPrecision = 8;
std::mt19937 rng(
    std::chrono::_V2::steady_clock::now().time_since_epoch().count());
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
  Point &operator=(const std::pair<double, double> &b) {
    this->x_ = b.first, this->y_ = b.second;
    return *this;
  }
  Point &operator=(const Point &b) {
    this->x_ = b.x_, this->y_ = b.y_;
    return *this;
  }
  Point operator+(const Vector &) const;
  Point operator-(const Vector &) const;
  Point &operator+=(const Vector &b) { return *this = *this + b; }
  Point &operator-=(const Vector &b) { return *this = *this - b; }
  friend std::istream &operator>>(std::istream &in, Point &a) {
    in >> a.x_ >> a.y_;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const Point &a) {
    out << std::setprecision(kPrecision) << std::fixed << a.x_ << ' ' << a.y_;
    return out;
  }
  ~Point() {}
};
class Vector {
 public:
  double x_, y_;
  Vector() {}
  Vector(double x, double y) : x_(x), y_(y) {}
  Vector(const std::pair<double, double> &b) : x_(b.first), y_(b.second) {}
  Vector(Point a, Point b) { x_ = b.x_ - a.x_, y_ = b.y_ - a.y_; }
  double Magnitude() const { return std::hypot(x_, y_); }
  double PolarAngle() const { return std::atan2(y_, x_); }
  Vector &operator=(const std::pair<double, double> &b) {
    this->x_ = b.first, this->y_ = b.second;
    return *this;
  }
  Vector &operator=(const Vector &b) {
    this->x_ = b.x_, this->y_ = b.y_;
    return *this;
  }
  Vector operator+(const Vector &b) const {
    return Vector(x_ + b.x_, y_ + b.y_);
  }
  Vector operator-(const Vector &b) const {
    return Vector(x_ - b.x_, y_ - b.y_);
  }
  Vector operator*(const double &b) const { return Vector(x_ * b, y_ * b); }
  Vector operator/(const double &b) const { return Vector(x_ / b, y_ / b); }
  Vector &operator+=(const Vector &b) { return *this = *this + b; };
  Vector &operator-=(const Vector &b) { return *this = *this - b; };
  Vector &operator*=(const double &b) { return *this = *this * b; };
  Vector &operator/=(const double &b) { return *this = *this / b; };
  void Rotate(const double &angle) {
    double x = x_, y = y_;
    x_ = x * std::cos(angle) - y * std::sin(angle);
    y_ = x * std::sin(angle) + y * std::cos(angle);
  }
  friend std::istream &operator>>(std::istream &in, Vector &a) {
    in >> a.x_ >> a.y_;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const Vector &a) {
    out << std::setprecision(kPrecision) << std::fixed << a.x_ << ' ' << a.y_;
    return out;
  }
  ~Vector() {}
};
class Line {
 public:
  Point p_;
  Vector v_;
  Line() {}
  Line(Point p, Vector v) : p_(p), v_(v) {}
  friend std::istream &operator>>(std::istream &in, Line &a) {
    Point A, B;
    in >> A >> B;
    a = Line(A, Vector(A, B));
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const Line &a) {
    out << a.p_ << ' ' << a.p_ + a.v_;
    return out;
  }
  ~Line() {}
};
class Segment {
 public:
  Point a_, b_;
  Segment() {}
  Segment(Point a, Point b) : a_(a), b_(b) {}
  friend std::istream &operator>>(std::istream &in, Segment &a) {
    in >> a.a_ >> a.b_;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const Segment &a) {
    out << std::setprecision(kPrecision) << std::fixed << a.a_ << ' ' << a.b_;
    return out;
  }
  ~Segment() {}
};
class Circle {
 public:
  Point o_;
  double r_;
  Circle() {}
  Circle(Point o, double r) : o_(o), r_(r) {}
  Circle(Point A) { o_ = A, r_ = 0.0; }
  Circle(Point A, Point B);
  Circle(Point A, Point B, Point C);
  Circle(const std::pair<Point, double> &b) : o_(b.first), r_(b.second) {}
  ~Circle() {}
  friend std::istream &operator>>(std::istream &in, Circle &a) {
    in >> a.o_ >> a.r_;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const Circle &a) {
    out << a.o_ << ' ' << a.r_;
    return out;
  }
};
typedef std::vector<Point> Polygon;
Point Point::operator+(const Vector &b) const {
  return Point(x_ + b.x_, y_ + b.y_);
}
Point Point::operator-(const Vector &b) const {
  return Point(x_ - b.x_, y_ - b.y_);
}
double Dis(const Point &a, const Point &b) {
  return std::hypot(a.x_ - b.x_, a.y_ - b.y_);
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
Circle::Circle(Point A, Point B) {
  o_ = Point((A.x_ + B.x_) / 2, (A.y_ + B.y_) / 2), r_ = Dis(o_, A);
}
Circle::Circle(Point A, Point B, Point C) {
  double a, b, c, d, e, f;
  a = B.y_ - A.y_;
  b = C.y_ - A.y_;
  c = B.x_ - A.x_;
  d = C.x_ - A.x_;
  e = B.x_ * B.x_ + B.y_ * B.y_ - A.x_ * A.x_ - A.y_ * A.y_;
  f = C.x_ * C.x_ + C.y_ * C.y_ - A.x_ * A.x_ - A.y_ * A.y_;
  o_ = Point((a * f - b * e) / (2 * a * d - 2 * b * c),
             (d * e - c * f) / (2 * a * d - 2 * b * c));
  r_ = Dis(o_, A);
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
    ans.emplace_back(p + v), ans.emplace_back(p - v);
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
  std::shuffle(a.begin(), a.end(), rng);
  Circle O(a.front());
  for (size_t i = 1; i < a.size(); i++)
    if (!InCircle(O, a.at(i))) {
      O = Circle(a.at(i));
      for (size_t j = 0; j < i; j++)
        if (!InCircle(O, a.at(j))) {
          O = Circle(a.at(i), a.at(j));
          for (size_t k = 0; k < j; k++)
            if (!InCircle(O, a.at(k))) O = Circle(a.at(i), a.at(j), a.at(k));
        }
    }
  return O;
}
double Area(const Polygon &a) {
  double ans = 0.0;
  for (size_t i = 1; i < a.size(); i++)
    ans += Cross(Vector(a.front(), a.at(i)), Vector(a.front(), a.at(i + 1)));
  return ans / 2;
}
Polygon ConvexHull(const std::vector<Point> &b) {
  std::vector<Point> a(b), s;
  std::swap(*a.begin(),
            *std::min_element(a.begin(), a.end(),
                              [](const Point &x, const Point &y) -> bool {
                                return x.y_ < y.y_;
                              }));
  s.emplace_back(a.at(0));
  std::sort(a.begin() + 1, a.end(),
            [&a](const Point &x, const Point &y) -> bool {
              return IsCcw(Vector(*a.begin(), x), Vector(*a.begin(), y));
            });
  s.emplace_back(a.at(1));
  int top = 1;
  for (size_t i = 2; i < a.size(); i++) {
    while (top && !IsCcw(Vector(s.at(top - 1), s.back()),
                         Vector(s.at(top - 1), a.at(i)))) {
      s.pop_back();
      top--;
    }
    s.emplace_back(a.at(i));
    top++;
  }
  return s;
}
Circle A, B, C;
Point P;
double D = -1e18, d[3];
void Check(Point p) {
  d[0] = A.r_ / Dis(p, A.o_);
  d[1] = B.r_ / Dis(p, B.o_);
  d[2] = C.r_ / Dis(p, C.o_);
  if (!Cmp(d[0] - d[1]) && !Cmp(d[1] - d[2]))
    if (d[0] > D) D = d[0], P = p;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> A >> B >> C;
  Line l1, l2;
  Circle c1, c2;
  Vector v1(A.o_, B.o_), v2(A.o_, C.o_);
  if (!Cmp(A.r_ - B.r_))
    l1.p_ = A.o_ + v1 / 2, l1.v_ = Rotate(v1, M_PI_2);
  else
    c1 = Circle(A.o_ + v1 * A.r_ / (A.r_ + B.r_),
                A.o_ + v1 * A.r_ / (A.r_ - B.r_));
  if (!Cmp(A.r_ - C.r_))
    l2.p_ = A.o_ + v2 / 2, l2.v_ = Rotate(v2, M_PI_2);
  else
    c2 = Circle(A.o_ + v2 * A.r_ / (A.r_ + C.r_),
                A.o_ + v2 * A.r_ / (A.r_ - C.r_));
  std::vector<Point> a;
  if (!Cmp(A.r_ - B.r_)) {
    if (!Cmp(A.r_ - C.r_))
      a.emplace_back(Intersection(l1, l2));
    else
      a = Intersection(l1, c2);
  } else {
    if (!(Cmp(A.r_ - C.r_)))
      a = Intersection(l2, c1);
    else
      a = Intersection(c1, c2);
  }
  for (auto &&i : a) Check(i);
  if (D > 0) std::cout << P;
  return 0;
}