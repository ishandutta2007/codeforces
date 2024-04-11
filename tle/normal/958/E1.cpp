#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 20;
const double eps = 1e-9;

inline int Sgn(double x) {
  return fabs(x) < eps ? 0 : x > 0 ? 1 : -1;
}

inline int Cmp(double x, double y) {
  return Sgn(x - y);
}

inline bool Mid(double l, double r, double mid) {
  return Cmp(l, mid) * Cmp(r, mid) <= 0;
}

struct Point {
  double x, y;
  
  Point(double _x = 0, double _y = 0) {
    x = _x, y = _y;
  }
  
  Point operator + (const Point &b) const {
    return Point(x + b.x, y + b.y);
  }
  
  Point operator - (const Point &b) const {
    return Point(x - b.x, y - b.y);
  }
  
  Point operator * (const double &b) const {
    return Point(x * b, y * b);
  }
  
  Point operator / (const double &b) const {
    return Point(x / b, y / b);
  }
  
  double operator * (const Point &b) const {
    return x * b.x + y * b.y;
  }
  
  double operator ^ (const Point &b) const {
    return x * b.y - y * b.x;
  }
  
  bool operator == (const Point &b) const {
    return !Cmp(x, b.x) && !Cmp(y, b.y);
  }
  
  bool operator != (const Point &b) const {
    return Cmp(x, b.x) || Cmp(y, b.y);
  }
  
  inline double Len() {
    return x * x + y * y;
  }
} a[N], b[N];

inline double Dis(Point x, Point y) {
  return sqrt((x - y).Len());
}

inline bool Mid(Point l, Point r, Point mid) {
  return Mid(l.x, r.x, mid.x) && Mid(l.y, r.y, mid.y);
}

inline Point Projection(Point p, Point q, Point x) {
  Point delta = q - p;
  return p + delta * ((x - p) * delta / delta.Len());
}

inline bool IntersectInterval(double l1, double r1, double l2, double r2) {
  if (l1 > r1) {
    swap(l1, r1);
  }
  if (l2 > r2) {
    swap(l2, r2);
  }
  return ~Cmp(r1, l2) && ~Cmp(r2, l1);
}

inline bool IntersectLine(Point l1, Point r1, Point l2, Point r2) {
  return Cmp((l2 - l1) ^ (r2 - l1), (l2 - r1) ^ (r2 - r1));
}

inline bool IntersectSegment(Point l1, Point r1, Point l2, Point r2) {
  if (!IntersectInterval(l1.x, r1.x, l2.x, r2.x) || !IntersectInterval(l1.y, r1.y, l2.y, r2.y)) {
    return false;
  }
  return Sgn((l2 - l1) ^ (r2 - l1)) * Sgn((l2 - r1) ^ (r2 - r1)) <= 0 && Sgn((l1 - l2) ^ (r1 - l2)) * Sgn((l1 - r2) ^ (r1 - r2)) <= 0;
}

int n, m, per[N];

inline void Check() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (IntersectSegment(a[i], b[per[i]], a[j], b[per[j]])) {
        return ;
      }
    }
  }
  puts("Yes");
  exit(0);
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  if (n != m) {
    puts("No");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    Read(a[i].x), Read(a[i].y);
  }
  for (int i = 0; i < n; ++i) {
    Read(b[i].x), Read(b[i].y);
  }
  for (int i = 0; i < n; ++i) {
    per[i] = i;
  }
  do {
    Check();
  } while (next_permutation(per, per + n));
  puts("No");
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}