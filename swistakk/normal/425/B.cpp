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
int b[N][N];
int c[N][N];
void PrintRes(int res, int k) {
  if (res > k) {
      cout<<"-1"<<endl;
    } else {
      cout<<res<<endl;
    }
}
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make3(int, n, m, k);
  RE (i, n) {
    RE (j, m) {
      cin>>b[i][j];
    }
  }
  int res = 100;
  if (n > 10) {
    RE (i, n) {
      int act = 0;
      RE (j, n) {
        int match = 0;
        RE (l, m) {
          if (b[i][l] == b[j][l]) {
            match++;
          }
        }
        act += min(match, m - match);
      }
      mini(res, act);
    }
    PrintRes(res, k);
  } else {
    for (int mask = 0; mask < (1 << n); mask++) {
      
      int act = 0;
      for (int bit = 1; bit <= n; bit++) {
        if (mask & (1 << (bit - 1))) {
          b[bit][1] ^= 1;
          act++;
        }
      }
      RE (i, m) {
        int match = 0;
        RE (l, n) {
          if (b[l][1] == b[l][i]) {
            match++;
          }
        }
        act += min(match, n - match);
      }
      mini(res, act);
      for (int bit = 1; bit <= n; bit++) {
        if (mask & (1 << (bit - 1))) {
          b[bit][1] ^= 1;
        }
      }
    }
    PrintRes(res, k);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}