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
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
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

const int N = 3e5 + 5;
int rep[N];
int path[N];
int dp[N];
vector<int> slo[N];
int Find(int v) {
  if (rep[v] == v) {
    return v;
  }
  rep[v] = Find(rep[v]);
  return rep[v];
}

void Union(int a, int b, bool merge) {
  a = Find(a);
  b = Find(b);
  if (a == b) {
    return;
  }
  if (merge) {
    path[a] = max({path[a], path[b], (path[a] + 1) / 2 + (path[b] + 1) / 2 + 1});
  }
  rep[b] = a;
}

bool vis[N];

int Dfs(int v) {
  vis[v] = 1;
  vector<int> sons;
  sons.PB(0);
  sons.PB(0);
  int from_sons = 0;
  for (auto nei: slo[v]) {
    if (vis[nei]) {
      continue;
    }
    int tmp = Dfs(nei);
    maxi(from_sons, tmp);
    sons.PB(dp[nei] + 1);
  }
  sort(ALL(sons), greater<int>());
  dp[v] = sons[0];
  return max(from_sons, sons[0] + sons[1]);
}
  
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make3(int, n, m, q);
  
  RE (i, n) {
    rep[i] = i;
  }
  
  RE (i, m) {
    make2(int, a, b);
    debug2(a, b);
    debug3(a, b, n);
    slo[a].PB(b);
    slo[b].PB(a);
    Union(a, b, false);
  }
  
  RE (i, n) {
    if (vis[i]) {
      continue;
    }
    path[Find(i)] = Dfs(i);
    cerr<<path[Find(i)]<<"\n";
  }
  
  RE (i, q) {
    make(int, t);
    if (t == 1) {
      make(int, a);
      cout<<path[Find(a)]<<"\n";
    } else {
      make2(int, a, b);
      Union(a, b, true);
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}