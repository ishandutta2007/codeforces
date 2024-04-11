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

vector<PII> ans[2];
const int N = 1e5 + 5;
int x[N];
int y[N];
int z[N];
int goal[N];
int fix[N];
int Magic(int n) {
  return n - (n & (n - 1));
}
map<int, int> where_fir_x;
map<int, int> where_fir_y;
void Xor(int i, int j, int which) {
  if (j == 0) {
    cout<<"-1\n";
    exit(0);
  }
  if (which == 0) {
    x[i] ^= x[j];
  } else {
    y[i] ^= y[j];
  }
  ans[which].PB(MP(i, j));
}
void Swap(int i, int j, int which) {
  if (i == j) {
    return;
  }
  Xor(i, j, which);
  Xor(j, i, which);
  Xor(i, j, which);
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  RE (i, n) {
    cin>>x[i];
    z[i] = x[i];
  }
  RE (i, n) {
    cin>>y[i];
    goal[i] = y[i];
  }
  int pot = 1;
  int st_x = 1;
  while (pot < (1 << 30)) {
    bool got = false;
    for (int i = st_x; i <= n; i++) {
      if (x[i] & pot) {
        Swap(i, st_x, 0);
        got = true;
        break;
      }
    }
    if (got) {
      for (int i = 1; i <= n; i++) {
        if (i != st_x && (x[i] & pot)) {
          Xor(i, st_x, 0);
        }
      }
      where_fir_x[pot] = st_x;
      st_x++;
//       RE (i, n) {
//         cerr<<x[i]<<" ";
//       }
//       cerr<<endl;
    }
    pot *= 2;
  }
  
  RE (i, n) {
    cerr<<x[i]<<" ";
  }
  cerr<<endl;
  
  
  pot = 1;
  int st_y = 1;
  while (pot < (1 << 30)) {
    bool got = false;
    for (int i = st_y; i <= n; i++) {
      if (y[i] & pot) {
        Swap(i, st_y, 1);
        got = true;
        break;
      }
    }
    if (got) {
      for (int i = 1; i <= n; i++) {
        if (i != st_y && (y[i] & pot)) {
          Xor(i, st_y, 1);
        }
      }
      where_fir_y[pot] = st_y;
      if (where_fir_x[pot] == 0) {
        cout<<"-1\n";
        return 0;
      }
      st_y++;
    }
    pot *= 2;
  }
  cerr<<"Y\n";
  RE (i, n) {
    cerr<<y[i]<<" ";
  }
  cerr<<endl;
  
  for (int i = 1; i <= st_y - 1; i++) {
  //for (int i = st_y - 1; i >= 1; i--) {
    debug(y[i]);
    int want = y[i];
    vector<int> want_x;
    while (want) {
      int ind = 0;
      for (int j = st_x - 1; j >= 1; j--) {
        if (Magic(x[j]) == Magic(want)) {
          ind = j;
          break;
        }
      }
      if (ind == 0) {
        cout<<"-1\n";
        cerr<<"Not in span\n";
        return 0;
      }
      want ^= x[ind];
      want_x.PB(ind);
    }
    int need_swap = 1;
    for (int j = 0; j < want_x.size(); j++) {
      int p = want_x[j];
      if (p == i) {
        need_swap = 0;
        swap(want_x[j], want_x.back());
        want_x.pop_back();
        break;
      }
    }
        
    if (need_swap) {
      swap(want_x[0], want_x.back());
      Swap(i, want_x.back(), 0);
      want_x.pop_back();
    }
    for (auto p : want_x) {
      Xor(i, p, 0);
    }
    assert(x[i] == y[i]);
    fix[i] = 1;
    cerr<<"Ustawiamy "<<i<<"\n";
    RE (j, n) {
      cerr<<x[j]<<" ";
    }
    cerr<<endl;
  }
  FOR (i, st_y, n) {
    Xor(i, i, 0);
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  reverse(ALL(ans[1]));
  cout<<ans[0].size() + SZ(ans[1])<<endl;
  REP (i, 2) {
    for (auto p : ans[i]) {
      cout<<p.first<<" "<<p.second<<"\n";
      z[p.first] ^= z[p.second];
    }
  }
  RE (i, n) {
    assert(z[i] == goal[i]);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}