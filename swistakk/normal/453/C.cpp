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
#else
#define debug(x)
#define debugv(x)
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
using std::endl;
using std::cout;
using std::cin;
using std::cerr;
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
const int N = 1e5 + 5;
int vis[N];
int need[N];
vector<int> slo[N];
int dfs_comp(int v) {
  vis[v] = 1;
  int acc = need[v];
  for (auto nei : slo[v]) {
    if (vis[nei]) {
      continue;
    }
    acc += dfs_comp(nei);
  }
  return acc;
}
vector<int> res;
int Upd(int v) {
  need[v] ^= 1;
  res.PB(v);
}
void dfs_create(int v) {
  Upd(v);
  vis[v] = true;
  for (auto nei : slo[v]) {
    if (vis[nei]) {
      continue;
    }
    dfs_create(nei);
    Upd(v);
    if (need[nei]) {
      Upd(nei);
      Upd(v);
    }
  }
  //Upd(v);
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  RE (i, m) {
    make2(int, a, b);
    slo[a].PB(b);
    slo[b].PB(a);
  }
  RE (i, n) {
    cin>>need[i];
  }
  int root = 1;
  int nonzero_comps = 0;
  RE (i, n) {
    if (!vis[i]) {
      int tmp = dfs_comp(i);
      if (tmp) {
        nonzero_comps++;
        root = i;
      }
    }
  }
  if (nonzero_comps == 0) {
    cout<<0<<endl;
    return 0;
  } else if (nonzero_comps > 1) {
    cout<<-1<<endl;
    return 0;
  }
  RE (i, n) {
    vis[i] = 0;
  }
  dfs_create(root);
  if (need[root]) {
    res.pop_back();
  }
  cout<<res.size()<<endl;
  for (auto v : res) {
    cout<<v<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}