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
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
const int N = 1e3 + 5;
ll mat[N][N];
ll row[N];
ll col[N];
ll prof_row[N * N];
ll prof_col[N * N];
const ll INF = 1e18;
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(ll, n, m);
  make2(ll, k, p);
  RE (i, n) {
    RE (j, m) {
      make(int, a);
      row[i] += a;
      col[j] += a;
    }
  }
  multiset<ll> vals;
  vals.clear();
  for (int i = 1; i <= n; i++) {
    vals.insert(-row[i]);
  }
  for (int i = 1; i <= k; i++) {
    auto it = vals.begin();
    ll act = -(*it);
    prof_row[i] = prof_row[i - 1] + act;
    vals.erase(it);
    act -= m * p;
    vals.insert(-act);
  }
  
  vals.clear();
  for (int i = 1; i <= m; i++) {
    vals.insert(-col[i]);
  }
  for (int i = 1; i <= k; i++) {
    auto it = vals.begin();
    ll act = -(*it);
    prof_col[i] = prof_col[i - 1] + act;
    vals.erase(it);
    act -= n * p;
    vals.insert(-act);
  }
  
  
  ll best = -INF;
  for (int i = 0; i <= k; i++) {
    maxi(best, prof_col[i] + prof_row[k - i] - p * i * (k - i));
  }
  cout<<best<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}