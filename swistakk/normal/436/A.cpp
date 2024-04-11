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
const int N = 1e6 + 6;
int h[N];
int k[N];
multiset<int> can[2];
int Update(int t, int h, VPII& vec, int beg) {
  while (beg < vec.size() && vec[beg].first <= h) {
    can[t].insert(vec[beg].second);
    beg++;
  }
  return beg;
}
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, h);
  VPII sweets[2];
  sweets[0].clear();
  sweets[1].clear();
  RE (i, n) {
    make3(int, t, x, y);
    //cin>>t>>h>>y;
    sweets[t].PB(MP(x, y));
  }
  sort(ALL(sweets[0]));
  sort(ALL(sweets[1]));
  debugv(sweets[0]);
  int best = 0;
  for (int st = 0; st < 2; st++) {
    int act = st;
    int act_h = h;
    can[0].clear();
    can[1].clear();
    int fin[2] = {0, 0};
    for (int t = 0; t < 2; t++) {
      fin[t] = Update(t, h, sweets[t], 0);
    }
    debug(can[0].size());
    debug(can[1].size());
    int act_res = 0;
    while (!can[act].empty()) {
      auto it = can[act].end();
      it--;
      act_h += *it;
      can[act].erase(it);
      act = 1 - act;
      act_res++;
      fin[0] = Update(0, act_h, sweets[0], fin[0]);
      fin[1] = Update(1, act_h, sweets[1], fin[1]);
    }
    maxi(best, act_res);
  }
  cout<<best<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}