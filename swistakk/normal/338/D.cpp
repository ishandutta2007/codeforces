#include <bits/stdc++.h>
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
typedef long long LL;
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

LL gcd(LL a,LL b,LL& x,LL& y){
  if (a<b) return gcd(b,a,y,x);
  if( b==0) {
    x=1;
    y=0;
    return a;
  }
  LL xp;
  LL pom = gcd(b,a%b,xp,x);
  y = xp - x * (a / b);
  return pom;
}
LL mul_bin(LL a, LL b, LL P) {
  LL res = 0;
  while (b) {
    if (b % 2 == 1) {
      res = (res + a) % P;
    }
    a = (a + a) % P;
    b /= 2;
  }
  return res;
}
LL Adjust(LL a, LL mod) {
  return (a % mod + mod) % mod;
}
LL INF = 1e18;
pair<LL, LL> nww(LL a, LL b, LL r1, LL r2) {
  r1 = Adjust(r1, a);
  r2 = Adjust(r2, b);
  LL x, y;
  LL d = gcd(a, b, x, y);
  x = Adjust(x, b);
  if (r1 % d != r2 % d) {
    return MP(-1, -1);
  }
  if (a / d > INF / b + 2) {
    return MP(-1, -1);
  }
  LL N = a / d * b;
  LL s = mul_bin(Adjust(r2 - r1, b) / d, x, b);
  LL new_r = (r1 + mul_bin(a, s, N)) % N;
  assert(new_r % a == r1 && new_r % b == r2);
  return MP(N, new_r);
}

pair<LL, LL> CRT(vector<pair<LL, LL>>& vec) {
  LL N = 1, r = 0;
  for (auto& p : vec) {
    pair<LL, LL> new_pair = nww(N, p.first, r, p.second);
    if (new_pair.first == -1) {
      return make_pair(-1, -1);
    }
    N = new_pair.first;
    r = new_pair.second;
  }
  return make_pair(N, r);
}
  


const int NN = 1e5 + 5;
LL gcds[NN];

int main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
//   debug(nww(5, 7, 2, 3));
//   debug(nww(7, 9, 3, 2));
//   debug(nww(8, 6, 5, 3));
//   debug(nww(6, 8, 0, 2));
//   debug(nww(16, 24, 9, 1));
//   debug(nww(144, 216, 12, 84));
  debug(nww(75317, 1217, 19015, 17));
  //return 0;
  make3(LL, n, m, k);
  vector<pair<LL, LL>> vec;
  RE (i, k) {
    cin>>gcds[i];
    //TODO!!
    vec.PB(MP(gcds[i], gcds[i] - (i - 1) % gcds[i]));
//     PII new_pair = nww(N, gcds[i], r, gcds[i] - (i - 1) % gcds[i]);
//     debug2(N, gcds[i]);
//     debug2(r, (i - 1) % gcds[i]);
//     debug(new_pair);
//     if (new_pair.first == -1) {
//       cout<<"NO\n";
//       return 0;
//     }
//     N = new_pair.first;
//     r = new_pair.second;
    //debug2(N, r);
  }
  pair<LL, LL> crt = CRT(vec);
  LL N = crt.first;
  LL r = crt.second;
  if (r == 0) {
    r += N;
  }
  if (N == -1 || N > n || r + k - 1 > m) {
    cout<<"NO\n";
    return 0;
  }
  RE (i, k) {
    LL x, y;
    if (gcd(N, r + i - 1, x, y) != gcds[i]) {
      cout<<"NO\n";
      return 0;
    }
  }
  debug2(N, r);
  cout<<"YES\n";
  return 0;
}