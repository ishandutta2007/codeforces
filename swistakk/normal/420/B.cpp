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
const int N = 1e5 + 5;
int logg[N];
int pres[N];
int can[N];
int init[N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make2(int, n, m);
  RE (i, n) {
    can[i] = 1;
  }
  RE (i, m) {
    char c;
    int pers;
    cin>>c>>pers;
    int sign = 1;
    if (c == '-') {
      sign = -1;
    }
    if (init[pers] == 0) {
      init[pers] = sign;
    }
    logg[i] = sign * pers;
  }
  
  int sure = 0;
  RE (i, n) {
    if (init[i] == -1) {
      pres[i] = 1;
      sure++;
    }
  }
  if (sure) {
    RE (i, n) {
      if (pres[i] == 0 && init[i] != 0) {
        can[i] = 0;
      }
    }
  }
  int clear_all_num = 0;
  int last_clear_all = 0;
  RE (i, m) {
    int pers = abs(logg[i]);
    int sign = 1;
    if (logg[i] < 0) {
      sign = -1;
    }
    if (sign == -1 && sure > 1) {
      can[pers] = 0;
    }
    if (sign == 1 && sure) {
      can[pers] = 0;
    }
    if (sign == 1 && sure == 0) {
      if (clear_all_num < 2 && last_clear_all != pers) {
        last_clear_all = pers;
        clear_all_num++;
        RE (j, n) {
          if (init[j] != 0 && j != pers) {
            can[j] = 0;
          }
        }
      }
    }
        
    sure += sign;
  }
  int sum = 0;
  RE (i, n) {
    sum += can[i];
  }
  cout<<sum<<endl;
  RE (i, n) {
    if (can[i]) {
      cout<<i<<" ";
    }
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}