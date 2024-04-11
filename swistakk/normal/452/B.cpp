#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debugv(x)
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
using std::endl;
using std::cout;
using std::cin;
using std::cerr;
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

struct Point {
  int y, x;
  Point (int y_, int x_) : y(y_), x(x_) {}
  Point () : Point(-1, -1) {}
};
double Dis(Point a, Point b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return sqrt(1.0 * dx * dx + 1.0 * dy * dy);
}
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  make2(int, n, m);
//   if (m == 0) {
//     cout<<n - 1<<" 0 "<<"0 0 "<<n<<" 0 1 0"<<endl;
//     return 0;
//   }
//   if (n == 0) {
//     cout<<"0 "<<m - 1<<" 0 0 0 "<<m<<" 0 1"<<endl;
//     return 0;
//   }
//   int dx, dy;
//   if (n > m) {
//     dx = 0;
//     dy = 1;
//   } else {
//     dx = 1;
//     dy = 0;
//   }
//   cout<<n - dx<<" "<<m - dy<<" 0 0 "<<n<<" "<<m<<" "<<dx<<" "<<dy<<endl; 
  set<pair<int, int> > secik;
  double best = 0;
  vector<int> res;
  int DUPA = 6;
  REP (x1, min(n + 1, DUPA)) {
    REP (y1, min(m + 1, DUPA)) {
      REP (x2, min(n + 1, DUPA)) {
        REP (y2, min(m + 1, DUPA)) {
          REP (x3, min(n + 1, DUPA)) {
            REP (y3, min(m + 1, DUPA)) {
              REP (x4, min(n + 1, DUPA)) {
                REP (y4, min(m + 1, DUPA)) {
                  secik.clear();
                  secik.insert(MP(x1, y1));
                  secik.insert(MP(n - x2, m - y2));
                  secik.insert(MP(x3, y3));
                  secik.insert(MP(n - x4, m - y4));
                  if (secik.size() != 4) {
                    continue;
                  }
                  Point p1(x1, y1), p2(n - x2, m - y2), p3(x3, y3), p4(n - x4, m - y4);
                  double d = Dis(p1, p2) + Dis(p2, p3) + Dis(p3, p4);
                  if (d > best) {
                    best = d;
                    res.clear();
                    res.PB(x1);
                    res.PB(y1);
                    res.PB(n - x2);
                    res.PB(m - y2);
                    res.PB(x3);
                    res.PB(y3);
                    res.PB(n - x4);
                    res.PB(m - y4);
//                     for (auto p : secik) {
//                       res.PB(p.first);
//                       res.PB(p.second);
//                     }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cerr<<best<<endl;
  for (auto a : res) {
    cout<<a<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}