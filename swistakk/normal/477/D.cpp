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

const int MOD_RES = 1e9 + 7;
const int P = 999999197;
const int MOD_POW = 1e9 + 13;
const int N = 5e3 + 5;
const int INF = 2e9;
const int LOG = 20;
int pot[N];
string in;
int t[N];
#undef int
int val[N][N];
vector<int> dp[N], shortest_pr[N], where_shortest[N];
int sum_pref[N][N];
int heheczki[N][N];
#define int long long
int pref[N];
double pot2[N];
double val_pref[N];
bool NotGreater(PII p1, PII p2) {
  int faj = heheczki[p1.first][p2.first];
  if (faj >= p1.second) {
    return true;
  }
  return in[p1.first + faj] < in[p2.first + faj];
}


#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  getline(cin, in);
  int n = in.length();
  in = ' ' + in;
  cerr<<in<<endl;
  pot2[0] = 1;
  REP (i, n + 1) {
    t[i] = (int)(in[i]);
    pot2[i] = pot2[i - 1] * 2;
    dp[i].resize(i + 2);
    where_shortest[i].resize(i + 2);
    shortest_pr[i].resize(i + 2);
  }
  RE (i, n) {
    int act = 0;
    FOR (j, i, n) {
      act = 2 * act % MOD_RES;
      val[i][j] = (act + (in[j] == '1')) % MOD_RES;
      act = val[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      if (in[i] != in[j]) {
        heheczki[i][j] = 0;
      } else {
        heheczki[i][j] = 1 + heheczki[i + 1][j + 1];
      }
    }
  }
  dp[0][0] = 1;
  REP (i, 1) {
    sum_pref[0][i] = 1;
    where_shortest[0][i] = 0;
    shortest_pr[0][i] = 0;
  }
  RE (i, n) {
    RE (j, i) {
      int max_len = j - 1;
      int wh = INF;
      if (in[i - j + 1] == '0') {
        goto A;
      }
      if (i >= 2 * j && NotGreater(MP(i - 2 * j + 1, j), MP(i - j + 1, j))) {
        max_len = j;
      }
      mini(max_len, i - j);
      dp[i][j] = (dp[i][j] + sum_pref[i - j][max_len]) % MOD_RES;
      wh = where_shortest[i - j][max_len];
      A: ;
      if (wh == INF) {
        shortest_pr[i][j] = INF;
      } else {
        shortest_pr[i][j] = shortest_pr[i - j][wh] + 1;
      }
    }
    shortest_pr[i][0] = INF;
    where_shortest[i][0] = INF;
    RE (j, i) {
      sum_pref[i][j] = (sum_pref[i][j - 1] + dp[i][j]) % MOD_RES;
      if (j <= i && ((where_shortest[i][j - 1] == INF && shortest_pr[i][j] != INF) || 
        (where_shortest[i][j - 1] != INF && shortest_pr[i][j] < shortest_pr[i][where_shortest[i][j - 1]]))) {
        where_shortest[i][j] = j;
      } else {
        where_shortest[i][j] = where_shortest[i][j - 1];
      }
    }
  }
  cout<<sum_pref[n][n]<<endl;
  int a = INF;
  RE (i, n) {
    if (i < 20) {
      mini(a, 1ll * shortest_pr[n][i] + val[n - i + 1][n]);
    } else {
      if (a == INF && shortest_pr[n][i] != INF) {
        cout<<(shortest_pr[n][i] + val[n - i + 1][n]) % MOD_RES<<endl;
        return 0;
      }
    }
  }
  cout<<a<<endl;
  return 0;
}