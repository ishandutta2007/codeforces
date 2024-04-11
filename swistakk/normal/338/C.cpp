#include <bits/stdc++.h>
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
using std::bitset;
using std::abs;
using std::__gcd;
using std::unordered_set;
using std::unordered_map;
using std::sqrt;
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

const int N = 10;
int a[N];
int b[N];
const int INF = 1e9;
int Bt(int to_consider, int want, int need_root, int acc) {
  if (to_consider > want) {
    return acc + need_root;
  }
  int res = INF;
  FOR (i, 0, to_consider - 1) {
    if (i == 0) {
      int bt = Bt(to_consider + 1, want, need_root | (to_consider > 1), acc + b[to_consider]); 
      mini(res, bt);
    } else {
      if (a[i] % a[to_consider] == 0) {
        a[i] /= a[to_consider];
        int bt = Bt(to_consider + 1, want, need_root, acc);
        mini(res, bt);
        a[i] *= a[to_consider];
      }
    }
  }
  return res;
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);

  
  RE (i, n) {
    cin>>a[i];
  }
  sort(a + 1, a + 1 + n, greater<int>());
  int primes = 0;
  RE (i, n) {
    int tmp = a[i];
    for (int j = 2; j * j <= tmp; j++) {
      while (tmp % j == 0) {
        tmp /= j;
        b[i]++;
      }
    }
    if (tmp > 1) {
      b[i]++;
    }
    if (a[i] == tmp) {
      primes++;
    }
  }
  cout<<n + Bt(1, n, 0, 0) - primes<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}