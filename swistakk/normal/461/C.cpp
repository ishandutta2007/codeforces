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
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const int N = 1e5 + 5;
const int M = 1 << 17;
int drz[2 * M + 5];

int Read(int a, int b) {
  int res = 0;
  a += M - 1;
  b += M - 1;
  res += drz[a];
  if (a != b) {
    res += drz[b];
  }
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      res += drz[a + 1];
    }
    if (b % 2 == 1) {
      res += drz[b - 1];
    }
    a /= 2;
    b /= 2;
  }
  return res;
}

int Read(int a) {
  //assert(Read(a, a) == drz[a + M - 1]);
  return drz[a + M - 1];
}

void Add(int a, int val) {
  a += M - 1;
  while (a) {
    drz[a] += val;
    a /= 2;
  }
}

void Adjust(int& a, int st, int end) {
  a = st + end - a;
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_time = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, q);
  
  RE (i, n) {
    drz[i + M - 1] = 1;
  }
  for (int i = M - 1; i >= 0; i--) {
    drz[i] = drz[2 * i] + drz[2 * i + 1];
  }
  int st = 1, end = n, rev = 0;
  RE (zz, q) {
    make(int, type);
    if (type == 2) {
      make2(int, l, r);
      if (rev == 0) {
        cout<<Read(st + l, st + r - 1)<<"\n";
      } else {
        cout<<Read(end - r + 1, end - l)<<"\n";
      }
    } else {
      make(int, p);
      if (2 * p > (end - st + 1)) {
        rev ^= 1;
        p = end - st + 1 - p;
      }
      debug3(p, st, end);
      for (int i = 0; i < p; i++) {
        int add_here = st + p + i;
        int from_here = st + p - i - 1;
        if (rev) {
          Adjust(add_here, st, end);
          Adjust(from_here, st, end);
        }
        Add(add_here, Read(from_here, from_here));
        cerr<<"Przerzucam "<<Read(from_here, from_here)<<" z "<<from_here<<" na "<<add_here<<endl;
      }
      if (!rev) {
        st = st + p;
      } else {
        end = end - p;
      }
    }
    for (int i = st; i <= end; i++) {
      cerr<<Read(i, i)<<" ";
    }
    cerr<<"vals"<<endl;
    //assert(Read(st, end) == n);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}