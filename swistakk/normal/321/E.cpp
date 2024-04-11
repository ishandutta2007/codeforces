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
const int N = 4e3 + 5;
const int K = 1e3 + 5;
int a[N][N];
int pr[N][N];
int dp[N][K];
int Val(int i, int j) {
  return pr[j][j] - pr[i - 1][j] - pr[j][i - 1] + pr[i - 1][i - 1];
}

void Rec(int l_need, int r_need, int l_ans, int r_ans, int k) {
  if (l_need > r_need) {
    return;
  }
  int m = (l_need + r_need) / 2;
  int best_cost = 1e9;
  int where = -1;
  FOR (i, l_ans, min(r_ans, m - 1)) {
    int cand = dp[i][k - 1] + Val(i + 1, m);
    if (cand < best_cost) {
      best_cost = cand;
      where = i;
    }
  }
  dp[m][k] = best_cost;
  Rec(l_need, m - 1, l_ans, where, k);
  Rec(m + 1, r_need, where, r_ans, k);
}

int main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, k);
  RE (i, n) {
    RE (j, n) {
      cin>>a[i][j];
      pr[i][j] = pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1] + a[i][j];
    }
  }
//   while (1) {
//     make2(int, a, b);
//     cerr<<Val(a, b)<<endl;
//   }
  RE (i, n) {
    dp[i][0] = 1e9;
  }
  RE (kk, k) {
    Rec(1, n, 0, n, kk);
    RE (i, n) {
      cerr<<dp[i][kk]<<" ";
    }
    cerr<<endl;
  }
  cout<<dp[n][k] / 2<<"\n";
  
  return 0;
}