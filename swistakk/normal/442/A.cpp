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
const int N = 5;
int row[N];
int col[N];
int pres[N][N], press[N][N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  set<char> letters, vals;
  RE (i, n) {
    make(char, c);
    make(int, val);
    val--;
    int let;
    if (c == 'R') {
      let = 0;
    } else if (c == 'G') {
      let = 1;
    } else if (c == 'B') {
      let = 2;
    } else if (c == 'Y') {
      let = 3;
    } else {
      let = 4;
    }
    press[let][val] = 1;
    //cerr<<let<<" "<<val<<endl;
  }
  int res = 10;
  for (int m = 0; m < (1 << 10); m++) {
    int heh = 0;
    for (int i = 0; i < 5; i++) {
      row[i] = 0;
      col[i] = 0;
    }
    for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
        if (press[y][x]) {
          row[y]++;
          col[x]++;
          heh++;
          pres[y][x] = 1;
        } else {
          pres[y][x] = 0;
        }
      }
    }
    
    bool got;
    do {
      got = false;
      REP (y, 5) {
        REP (x, 5) {
          if (pres[y][x] && (m & (1 << y)) && (m & (1 << (5 + x)))) {
            got = true;
            pres[y][x] = 0;
            col[x]--;
            row[y]--;
            heh--;
          } else if (pres[y][x] && col[x] == 1 && (m & (1 << (5 + x)))) {
            got = true;
            pres[y][x] = 0;
            col[x]--;
            row[y]--;
            heh--;
          } else if (pres[y][x] && row[y] == 1 && (m & (1 << y))) {
            got = true;
            pres[y][x] = 0;
            col[x]--;
            row[y]--;
            heh--;
          }
        }
      }
    } while (got);
    if (heh <= 1) {
      mini(res, __builtin_popcount(m));
    }
    //cerr<<heh<<endl;
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}