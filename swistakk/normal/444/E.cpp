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

const int N = 3e3 + 5;
int vis[N];
int x[N];
vector<PII> slo[N];
PII Dfs(int v, int mx) {
  vis[v] = 1;
  int sa = 1, sb = x[v];
  for (auto e : slo[v]) {
    if (e.second > mx || vis[e.first]) {
      continue;
    }
    auto p = Dfs(e.first, mx);
    sa += p.first;
    sb += p.second;
  }
  return MP(sa, sb);
}


#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  RE (i, n - 1) {
    make3(int, a, b, c);
    slo[a].PB(MP(b, c));
    slo[b].PB(MP(a, c));
  }
  RE (i, n) {
    cin>>x[i];
  }
  
  int kl = 0, kp = 11111, aktc, faj = 0;
  while (kl <= kp) {
    aktc = (kl + kp) / 2;
    RE (i, n) {
      vis[i] = 0;
    }
    vector<PII> vec;
    RE (i, n) {
      if (vis[i]) {
        continue;
      }
      vec.PB(Dfs(i, aktc - 1));
    }
    int mx = 0;
    int sumc = 0;
    for (auto a : vec) {
      maxi(mx, a.first + a.second);
      sumc += a.second;
    }
    //debugv(vec);
    //debug2(sumc, mx);
    if (sumc < mx) {
      kp = aktc - 1;
    } else {
      faj = aktc;
      kl = aktc + 1;
    }
  }
  cout<<faj<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}