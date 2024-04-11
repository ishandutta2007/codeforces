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
const int N = 2e3 + 5;
int t[N][N];
int was[N][N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  int res = 1e7;
  int sum = 0;
  RE (i, n) {
    RE (j, m) {
      make(char, c);
      //debug(c);
      t[i][j] = (c == 'X');
      cerr<<t[i][j];
      sum += t[i][j];
    }
    cerr<<endl;
  }
  int min_i = n, max_i = 0, max_j = 0, min_j = m;
  RE (i, n) {
    RE (j, m) {
      if (t[i][j]) {
        debug2(i, j);
        mini(min_i, i);
        mini(min_j, j);
        maxi(max_i, i);
        maxi(max_j, j);
      }
    }
  }
  
  debug2(max_i, min_i);
  debug2(max_j, min_j);
  if (sum == (max_i - min_i + 1) * (max_j - min_j + 1)) {
    FOR (i, min_i, max_i) {
      FOR (j, min_j, max_j) {
        if (t[i][j] == 0) {
          goto A;
        }
      }
    }
    cout<<min(max_i - min_i + 1, max_j - min_j + 1)<<endl;
    return 0;
    A:;
  }

    
    
  
  REP (tr, 2) {
    int st_i = -1;
    int st_j = -1;
    RE (i, n) {
      RE (j, m) {
        if (t[i][j] == 1) {
          st_i = i;
          st_j = j;
          goto B;
        }
      }
    }
    B: ;
    int wid = 1;
    debug2(st_i, st_j);
    while (t[st_i][st_j + wid]) {
      wid++;
    }
//     int cor_i = st_i;
//     int cor_j = j + wid - 1;
    int fir_non = st_i;
    while (t[fir_non + 1][st_j]) {
      fir_non++;
    }
    int fir_in = st_i;
    while (t[fir_in + 1][st_j + wid] == 0 && fir_in < n + 3) {
      fir_in++;
    }
    debug2(fir_non, fir_in);
    int hei = fir_non - fir_in;
    debug2(wid, hei);
    
    int acc = wid * hei;
    
    bool ok = true;
    if (fir_in > n || hei <= 0) {
      goto C;
    }

    RE (i, n) {
      RE (j, m) {
        was[i][j] = 0;
      }
    }
    FOR (i, st_i, st_i + hei - 1) {
      FOR (j, st_j, st_j + wid - 1) {
        was[i][j] = 1;
      }
    }
    while (acc < sum && st_i <= n && st_j <= m) {
      if (!t[st_i][st_j + wid]) {
        st_i++;
        FOR (j, st_j, st_j + wid - 1) {
          was[st_i + hei - 1][j] = 1;
          acc++;
        }
      } else {
        st_j++;
        FOR (i, st_i, st_i + hei - 1) {
          was[i][st_j + wid - 1] = 1;
          acc++;
        }
      }
    }
    
    if (acc != sum) {
      goto C;
    }
    RE (i, n) {
      RE (j, m) {
        cerr<<was[i][j]<<" ";
        ok &= (t[i][j] == was[i][j]);
      }
      cerr<<endl;
    }
    if (ok) {
      mini(res, hei * wid);
    }
    C: ;
    RE (i, n) {
      for (int j = i + 1; j <= max(n, m); j++) {
        swap(t[i][j], t[j][i]);
      }
    }
    swap(n, m);
  }
  if (res > 1e6) {
    cout<<"-1"<<endl;
  } else {
    cout<<res<<endl;
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}