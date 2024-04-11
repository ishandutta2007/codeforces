//{{{
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include <set>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;

template<class T>
ostream& operator<<(ostream&o, const vector<T>&v) {
  o<<'{';
  FOREACH(it,v) o<<*it<<',';
  return o<<'}';
}
typedef long long LL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
typedef vector<int> VI; typedef vector<string> VS; typedef vector<VI> VVI;
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
//}}}

struct Point {
  int x,y;
  Point() {}
  Point(int x,int y):x(x),y(y) {}
};

inline Point operator+(const Point &A,const Point&B) { return Point(A.x+B.x,A.y+B.y); }
inline Point operator-(const Point &A,const Point&B) { return Point(A.x-B.x,A.y-B.y); }
inline LL operator%(const Point&A,const Point&B) { return LL(A.x)*B.y-LL(A.y)*B.x; }
inline bool operator<(const Point &A, const Point &B) {
  if(A.x!=B.x) return A.x < B.x;
  return A.y < B.y;
}
inline bool operator==(const Point &A, const Point &B) {
  return A.x==B.x && A.y == B.y;
}

class HalfHull {
  set<Point> points;
 public:
  void add(Point p);
  bool above(Point p);
  void debug();
};

bool HalfHull::above(Point p) {
  set<Point>::iterator Rp = points.upper_bound(p);
  if(Rp==points.begin()) return false;
  set<Point>::iterator Lp = Rp; --Lp;
  Point L = *Lp;
  if(Rp==points.end()) return L == p;
  Point R = *Rp;
  return (R-L) % (p-L) >= 0;
}

void HalfHull::add(Point p) {
  if(above(p)) return;
  set<Point>::iterator pp = points.insert(p).first;

  set<Point>::iterator Ap = pp;
  ++Ap;
  while(Ap != points.end()) {
    set<Point>::iterator Bp = Ap;
    ++Bp;
    if(Bp==points.end()) break;
    if((*Ap - p) % (*Bp - p) > 0) break;
    points.erase(Ap);
    Ap = Bp;
  }

  set<Point>::iterator Cp = pp;
  if(Cp != points.begin()) {
    --Cp;
    while(Cp != points.begin()) {
      set<Point>::iterator Dp = Cp;
      --Dp;
      if ((*Dp - p) % (*Cp-p) > 0) break;
      points.erase(Cp);
      Cp = Dp;
    }
  }
}

void HalfHull::debug() {
  FOREACH(it, points) printf(" (%d,%d)", it->x, it->y);
  printf("\n");
}

const bool DEBUG = false;

int main() {
  int nq = rint();
  HalfHull H1, H2;
  REP(i,nq) {
    int t = rint();
    int x = rint();
    int y = rint();
    Point p(x,y);
    Point pf(x,-y);
    if(t==1) {
      H1.add(p);
      H2.add(pf);
      if(DEBUG) {
        printf("Lower:"); H1.debug();
        printf("Upper:"); H2.debug();
      }
    } else {
      bool res = H1.above(p) && H2.above(pf);
      printf(res ? "YES\n" : "NO\n");
    }
  }
}