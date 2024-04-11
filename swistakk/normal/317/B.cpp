#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define st first
#define nd second
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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int S = 200;
int Conv(int a, int b) {
  return (a + S) * 2 * S + b + S;
}
int ants[(int)(1e6)];

void Inc(int a, int b, int c);
void Check(int a, int b) {
  while (ants[Conv(a, b)] >= 4) {
    int gr = ants[Conv(a, b)] / 4;
    ants[Conv(a, b)] -= 4 * gr;
    REP (dir, 4) {
      Inc(a + dx[dir], b + dy[dir], gr);
    }
  }
}
void Inc(int a, int b, int c) {
  ants[Conv(a, b)] += c;
  Check(a, b);
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, t);
  Inc(0, 0, n);
//   int tmp = n;
//   vector<int> bits;
//   while (tmp) {
//     bits.PB(tmp % 2);
//     tmp /= 2;
//   }
//   debugv(bits);
//   while (SZ(bits)) {
//     FOR (i, -S, S) {
//       FOR (j, -S, S) {
//         ants[Conv(i, j)] *= 2;
//       }
//     }
//     FOR (i, -S, S) {
//       FOR (j, -S, S) {
//         Check(i, j);
//       }
//     }
//     Inc(0, 0, bits.back());
//     bits.pop_back();
//     debugv(bits);
//   }
  RE (i, t) {
    make2(int, x, y);
    if (abs(x) > S || abs(y) > S) {
      cout<<"0\n";
    } else {
      cout<<ants[Conv(x, y)]<<"\n";
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}