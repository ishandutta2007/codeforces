/* 
 * Wzorcowka do zadania PRZ
 * Autor: Wojtek Nadara
 */

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
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

const int N = 1e3 + 5;
ll dp[N][N][2];
const int kMaxM = 1e6 + 2;
bool left_constraint[kMaxM], right_constraint[kMaxM];
const int M = 1e9 + 7;
int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make2(int, n, m);
  //make(int, left_constraints);
  int left_constraints = 1;
  RE (i, left_constraints) {
    make(int, l);
    //int l = 1;
    left_constraint[l] = true;
    if (l > m) {
      cout<<"0"<<endl;
      return 0;
    }
  }
  //make(int, right_constraints);
  int right_constraints = 0;
  RE (i, right_constraints) {
    make(int, l);
    right_constraint[l] = true;
    if (l > m) {
      cout<<"0"<<endl;
      return 0;
    }
  }
  if (n > m) {
    cout<<"0"<<endl;
    return 0;
  }
  ll res = 0;
  dp[0][0][0] = 1;
  int t = 1;
  FOR (i, 1, m) {
    FOR (j, 0, n) {
      FOR (k, j, n) {
        dp[j][k][t] = 0;
        REP (r1, 2) {
          if (j < r1) {
            continue;
          }
          if (r1 == 0 && right_constraint[i]) {
            continue;
          }
          if (k > 0) {
            dp[j][k][t] += dp[j - r1][k - 1][1 - t];
          }
          if (!left_constraint[i]) {
            dp[j][k][t] += dp[j - r1][k][1 - t];
          }
        }
        dp[j][k][t] %= M;
      }
    }
    t = 1 - t;
  }
  res = dp[n][n][1 - t];
  RE (i, n) {
    res *= i;
    res %= M;
  }
  cout<<res<<endl;
  // nie zapomnij o ll
  return 0;
}