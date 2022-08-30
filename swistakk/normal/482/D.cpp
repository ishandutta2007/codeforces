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
const int P = 1e9 + 7;
int dp[N][2];
vector<int> slo[N];
int p[N];
void Dfs(int v) {
  for (auto nei : slo[v]) {
    Dfs(nei);
  }
  int dp_all[2] = {};
  int dp_even = 1;
  int dp_odd_even = 1;
  int dp_odd_odd = 0;
  dp_all[1] = 1;
  for (auto nei : slo[v]) {
    dp_even = (dp_even * dp[nei][0]) % P;
    int tmp = dp_odd_even;
    dp_odd_even = (dp_odd_even + dp_odd_odd * dp[nei][1]) % P;
    dp_odd_odd = (dp_odd_odd + tmp * dp[nei][1]) % P;
    int new_dp[2] = {};
    REP (par_so_far, 2) {
      REP (son_par, 2) {
        new_dp[par_so_far ^ son_par] += dp_all[par_so_far] * dp[nei][son_par];
      }
    }
    REP (i, 2) {
      dp_all[i] = new_dp[i] % P;
    }
  }
  debug(v);
  debug(dp_even);
  debug(dp_odd_even);
  debug(dp_odd_odd);
  dp[v][0] = (1 + 2 * dp_all[0] - dp_odd_odd + P) % P;
  dp[v][1] = (2 * dp_all[1] - dp_even + P) % P;
  //dp[v][0] = (1 + 2 * dp_all[0] - dp_even + P) % P;
  //dp[v][1] = (2 * dp_all[1] - dp_odd_odd + P) % P;
  debug(dp_all[0]);
  debug(dp_all[1]);
  debug(dp[v][0]);
  debug(dp[v][1]);
  return;
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  FOR (i, 2, n) {
    cin>>p[i];
    slo[p[i]].PB(i);
  }
  Dfs(1);
  
  cout<<(dp[1][0] + dp[1][1] + P - 1) % P<<endl;
  
  return 0;
}