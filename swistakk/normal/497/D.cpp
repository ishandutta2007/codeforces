#include <bits/stdc++.h>
long long max(int a, long long b) { return max((long long)a, b); }
long long max(long long b, int a) { return max(a, (long long)b); }
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
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
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
using namespace std;
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

const double kEps = 1e-8;

const double kPi = 2 * acos(0);
struct Point {
  LD x, y;
  Point(LD a = 0, LD b = 0) : x(a), y(b) {}
  //Point(const Point& a) : x(a.x), y(a.y) {}
  void operator=(const Point& a) { x = a.x; y = a.y; }
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y); return p; }
  Point operator*(LD a) const { Point p(x * a, y * a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(LD a) { x *= a; y *= a; return *this;}
  Point operator/(long double a) const { Point p(x / a, y / a); return p; }
  Point& operator/=(long double a) { x /= a; y /= a; return *this; }
  
  LD NormSq() const {
    return (x * x + y * y);
  }
  LD Norm() const {
    return sqrt(x * x + y * y);
  }
  long double CrossProd(const Point& a) const {
    return x * a.y - y * a.x;
  }
  LD Dist(const Point& a) const {
    return (*this - a).Norm();
  }
  void NormalizeSelf() {
    *this /= Norm();
  }
  long double DotProd(const Point& a) const {
    return x * a.x + y * a.y;
  }
  Point Normalize() {
    Point res(*this);
    res.NormalizeSelf();
    return res;
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
  
  friend ostream& operator<<(ostream& out, Point m);
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

struct Utils {
    
  static Point ProjPointToLine(Point p, Line l) {
    l.p[0] -= p;
    l.p[1] -= p;
    Point normal = l.NormalVector();
    normal *= normal.DotProd(l.p[0]);
    return normal + p;
  }
    
};

ostream& operator<<(ostream& out, Point p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

const int N = 1e3 + 5;
Point A[N];
Point B[N];
void Exit() {
  cout<<"YES\n";
  exit(0);
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, x_p, y_p);
  Point P = Point(x_p, y_p);
  make(int, n);
  RE (i, n) {
    make2(int, a, b);
    A[i] = Point(a, b);
  }
  A[n + 1] = A[1];
  make2(int, x_q, y_q);
  Point Q = Point(x_q, y_q);
  make(int, m);
  RE (i, m) {
    make2(int, a, b);
    B[i] = Point(a, b);
  }
  B[m + 1] = B[1];
  int PQ = (P - Q).NormSq();
  RE (i, n) {
    RE (j, m) {
      Point B1 = B[j];
      Point A1 = A[i];
      Point A2 = A[i + 1];
      Point P1 = P + (B1 - Q);
      if ((P1 - A1).NormSq() >= PQ && (P1 - A2).NormSq() <= PQ) {
        cerr<<"dupa\n";
        Exit();
      }
      if ((P1 - A1).NormSq() <= PQ && (P1 - A2).NormSq() >= PQ) {
        cerr<<"dupencja\n";
        Exit();
      }
      Line l = Line(A1, A2);
      Point proj = Utils::ProjPointToLine(P1, l);
      if ((proj - P1).Norm() <= sqrt(PQ) + kEps && (P1 - A1).NormSq() >= PQ && (P1 - A2).NormSq() >= PQ && (proj - A1).DotProd(proj - A2) <= kEps) {
        cerr<<"dupeczka\n";
        cerr<<i<<" "<<j<<endl;
        debug3(B1, A1, A2);
        cerr<<proj<<endl;
        Exit();
      }
    }
  }
  
  RE (i, m) {
    RE (j, n) {
      Point B1 = A[j];
      Point A1 = B[i];
      Point A2 = B[i + 1];
      Point P1 = Q + (B1 - P);
      if ((P1 - A1).NormSq() >= PQ && (P1 - A2).NormSq() <= PQ) {
        Exit();
      }
      if ((P1 - A1).NormSq() <= PQ && (P1 - A2).NormSq() >= PQ) {
        Exit();
      }
      Line l = Line(A1, A2);
      Point proj = Utils::ProjPointToLine(P1, l);
      if ((proj - P1).Norm() <= sqrt(PQ) + kEps && (P1 - A1).NormSq() >= PQ && (P1 - A2).NormSq() >= PQ && (proj - A1).DotProd(proj - A2) <= kEps) {
        Exit();
      }
    }
  }
  
  
  cout<<"NO\n";
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}