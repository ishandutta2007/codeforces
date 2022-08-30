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
using namespace std;
typedef long long ll;
typedef double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}
const double kEps = 1e-6;
double sq(double a) {
  return a * a;
}
  
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make2(int, n, d);
  vector<pair<double, int> > inters;
  double PI = acos(0) * 2;
  RE (i, n) {
    make3(int, x, y, r);
    double dis = sqrt(sq(x) + sq(y));
    int least_mult = int((dis - r - kEps) / d) * d;
    int greatest_mult = int((dis + r + kEps) / d) * (d + 1);
    double ang = atan2(y, x);
    for (int R1 = least_mult; R1 <= greatest_mult; R1 += d) {
      if (abs(dis - R1) > r || R1 <= 0) {
        continue;
      }
      double R2 = r;
      double diff = (sq(R1) - sq(R2)) / dis;
      double a = (dis + diff) / 2;
      double width = acos(a / R1);
      pair<double, double> inter1 = MP(ang - width - kEps, ang + width + kEps);
      pair<double, double> inter2 = MP(inter1.first - 2 * PI, inter1.first - 2 * PI);
      pair<double, double> inter3 = MP(inter1.first + 2 * PI, inter1.first + 2 * PI);
      vector<pair<double, double> > vec;
      vec.PB(inter1);
      vec.PB(inter2);
      vec.PB(inter3);
      for (auto p : vec) {
        inters.PB(MP(p.first, 1));
        inters.PB(MP(p.second, -1));
      }
    }
  }
  sort(ALL(inters));
  int acc = 0;
  int res = 0;
  for (auto p : inters) {
    acc += p.second;
    maxi(res, acc);
  }
  cout<<res<<endl;
  
  
  // nie zapomnij o ll
  return 0;
}