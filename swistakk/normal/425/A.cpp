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
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}
const int N = 1e3;
int a[N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make2(int, n, k);
  VPII vec;
  RE (i, n) {
    cin>>a[i];
    vec.PB(MP(a[i], i));
  }
  int best = -N * N;
  sort(ALL(vec));
  RE (l, n) {
    for (int r = l; r <= n; r++) {
      VI smallest_from;
      VI largest_outside;
      int sum = 0;
      FOR (i, l, r) {
        sum += a[i];
      }
      for (int i = int(vec.size()) - 1; i >= 0; i--) {
        if (largest_outside.size() == k) {
          break;
        }
        if (vec[i].second < l || vec[i].second > r) {
          largest_outside.PB(vec[i].first);
        }
      }
      for (int i = 0; i < vec.size(); i++) {
        if (smallest_from.size() == k) {
          break;
        }
        if (vec[i].second >=l && vec[i].second <= r) {
          smallest_from.PB(vec[i].first);
        }
      }
      int pos_out = 0, pos_from = 0;
      while (pos_out < (int)largest_outside.size() && pos_from < (int)smallest_from.size() &&
        smallest_from[pos_from] < largest_outside[pos_out]) {
        sum += largest_outside[pos_out] - smallest_from[pos_from];
        pos_from++;
        pos_out++;
      }
      debug(l);
      debug(r);
      debug(sum);
      maxi(best, sum);
    }
  }
  cout<<best<<endl;
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}