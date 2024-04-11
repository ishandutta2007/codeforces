/**
 *    author:  tourist
 *    created: 24.11.2020 20:01:52       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct TPoint {
  T x;
  T y;
  int id;

  TPoint() : x(0), y(0), id(-1) {}
  TPoint(const T& x_, const T& y_) : x(x_), y(y_), id(-1) {}
  TPoint(const T& x_, const T& y_, int id_) : x(x_), y(y_), id(id_) {}

  //static constexpr T eps = static_cast<T>(1e-9);

  inline TPoint operator+(const TPoint& rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
  inline TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
  inline TPoint operator-() const { return TPoint(-x, -y); }

  inline bool operator<(const TPoint& rhs) const {
    return (y < rhs.y || (y == rhs.y && x < rhs.x));
  }

  inline bool is_upper() const {
    return (y > 0 || (y == 0 && x > 0));
  }

  inline int cmp_polar(const TPoint& rhs) const {
    assert(x != 0 || y != 0);
    assert(rhs.x != 0 || rhs.y != 0);
    bool a = is_upper();
    bool b = rhs.is_upper();
    if (a != b) {
      return (a ? -1 : 1);
    }
    long long v = x * rhs.y - y * rhs.x;
    return (v > 0 ? -1 : (v < 0 ? 1 : 0));
  }

  inline long double abs() const {
    return sqrt((long double) x * x + (long double) y * y);
  }
};

using Point = TPoint<long long>;
//using Point = TPoint<long double>;

string to_string(const Point& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  mt19937 rng(58);
  while (true) {
    shuffle(order.begin(), order.end(), rng);
    vector<int> sign(n);
    Point q;
    for (int i : order) {
      if ((q + p[i]).abs() < (q - p[i]).abs()) {
        sign[i] = 1;
        q = q + p[i];
      } else {
        sign[i] = -1;
        q = q - p[i];
      }
    }
    if (q.abs() < 1.5e6) {
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << sign[i];
      }
      cout << '\n';
      break;
    }
  }
  return 0;
}