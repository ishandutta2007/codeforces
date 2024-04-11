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
#include <complex>
#define MP make_pair
#define PB push_back
#define int long long
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
using std::endl;
using std::cout;
using std::cin;
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
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::swap;
using std::complex;
using std::sort;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PII;
typedef pair<ll, ll> PLL;
typedef vector<ll> VI;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const ll P = 999999197;
const int M = 1e9 + 7;
const int N = 1e6 + 5;
int pot[N];
int hash[N];
int pref[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  pot[0] = 1;
  RE (i, N - 1) {
    pot[i] = pot[i - 1] * P % M;
  }
  
  make2(int, n, w);
  if (w == 1) {
    cout<<n<<endl;
    return 0;
  }
  int last = 0;
  vector<int> ele, wall;
  RE (i, n) {
    make(int, a);
      wall.PB(a - last);
    last = a;
  }
  debugv(wall);
  int ele_hash = 0;
  RE (i, w) {
    make(int, a);
    if (i > 1) {
      ele.PB(a - last);
      ele_hash = ((ele_hash + pot[i - 2] * (a - last)) % M + M) % M;
    }
    last = a;
  }
//   debugv(ele);
//   vector<int> slo;
//   for (auto xz : ele) {
//     slo.PB(xz);
//   }
//   slo.PB(M);
//   for (auto xz : wall) {
//     slo.PB(xz);
//   }
//   debugv(slo);
// //   slo.clear();
// //   slo = vector<int>{0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0};
//   int ans = 0;
//   for (int i = 1; i < slo.size(); i++) {
//     pref[i] = pref[i - 1];
//     while (1) {
//       if (slo[i] == slo[pref[i]]) {
//         pref[i] = pref[i] + 1;
//         break;
//       }
//       if (pref[i] == 0) {
//         break;
//       }
//       pref[i] = pref[pref[i] - 1];
//     }
//     if (pref[i] == w - 1) {
//       ans++;
//       //debug(i);
//     }
//     cerr<<pref[i]<<" ";
//   }
//   cerr<<endl;
//   cout<<ans<<endl;
  debugv(ele);
  int ans = 0;
  int len = w - 1;
  debug(len);
  for (int i = 1; i < wall.size(); i++) {
    hash[i] = (hash[i - 1] + wall[i] * pot[i] % M + M) % M;
    if (i >= len && (hash[i] - hash[i - len] + M) % M == ele_hash * pot[i - len + 1] % M) {
      ans++;
      debug(i);
    }
  }
  
  
  cout<<ans<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}