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

const int M = 1e9 + 5;
set<int> maxis;
map<int, int> cnt;
int choose3(int n) {
  return n * (n - 1) * (n - 2) / 6;
}
int choose2(int n) {
  return n * (n - 1) / 2;
}
void Type1(vector<PII>& vec) {
  map<int, int> tmp;
  int mn = M, mx = 0;
  int all = 0;
  for (auto a : vec) {
    if (!a.first) {
      continue;
    }
    mini(mn, a.second);
    maxi(mx, a.second);
    tmp[a.second]++;
    all++;
  }
  int dis = mx - mn;
  if (dis <= 0) {
    return;
  }
  int xx = choose3(all) - choose3(all - tmp[mn]) - choose3(all - tmp[mx]) + choose3(all - tmp[mn] - tmp[mx]);
  maxis.insert(-dis);
  cnt[dis] += xx;
  debug3("T1", dis, xx);
}
  
void Type2(vector<PII> vec, int n) {
  map<int, int> vals[2];
  int mn[2] = {M, M}, mx[2] = {0, 0}; 
  int all[2] = {0, 0};
  for (auto a : vec) {
    debug(a);
    vals[a.first][a.second]++;
    all[a.first]++;
    mini(mn[a.first], a.second);
    maxi(mx[a.first], a.second);
  }
  int dis;
  int xx = 0;
  debug2(mn[0], mx[0]);
  debug2(mn[1], mx[1]);
  if (mx[0] <= mn[1]) {
    dis = n - mn[1] + mx[0];
    xx = vals[0][mx[0]] * (choose2(all[1]) - choose2(all[1] - vals[1][mn[1]]));
  } else if (mn[0] >= mx[1]) {
    dis = n - mn[0] + mx[1];
    xx = vals[0][mn[0]] * (choose2(all[1]) - choose2(all[1] - vals[1][mx[1]]));
  } else {
    dis = n;
    for (auto& a : vec) {
      swap(a.first, a.second);
    }
    sort(ALL(vec));
    for (auto& a : vec) {
      swap(a.first, a.second);
    }
    int so_far1 = 0;
    for (auto& a : vec) {
      if (a.first == 1) {
        so_far1++;
      } else {
        xx += choose2(all[1]) - choose2(so_far1) - choose2(all[1] - so_far1 - vals[1][a.second]);
      }
    }
  }
  if (xx == 0) {
    return;
  }
  maxis.insert(-dis);
  cnt[dis] += xx;
  debug3("T2", dis, xx);
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  vector<PII> vec;
  RE (i, m) {
    make2(int, s, f);
    vec.PB(MP(s, f));
  }
  Type1(vec);
  Type2(vec, n);
  for (auto& a : vec) {
    a.first ^= 1;
  }
  Type1(vec);
  Type2(vec, n);
  if (maxis.empty()) {
    cout<<choose3(m)<<endl;
    return 0;
  }
  int a = *maxis.begin();
  debug(-a);
  cout<<cnt[-a]<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}