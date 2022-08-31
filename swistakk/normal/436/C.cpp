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
int dis[N][N];
char lev[N][12][12];
int rep[N];
int Find(int v) {
  if (rep[v] == v) {
    return v;
  }
  rep[v] = Find(rep[v]);
  return rep[v];
}
bool Union(int a, int b) {
  a = Find(a);
  b = Find(b);
  if (a == b) {
    return false;
  }
  rep[b] = a;
  return true;
}
int vis[N];
vector<int> slo[N];
void dfs(int v, int par) {
  cout<<v<<" "<<par<<endl;
  vis[v] = 1;
  for (auto nei : slo[v]) {
    if (!vis[nei]) {
      dfs(nei, v);
    }
  }
}
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  vector<pair<int, pair<int, int> > > edges;
  make2(int, n, m);
  make2(int, k, w);
  int res = n * m * k;
  RE (l, k) {
    rep[l] = l;
    RE (i, n) {
      RE (j, m) {
        cin>>lev[l][i][j];
      }
    }
    RE (prev, l - 1) {
      int diff = 0;
      RE (i, n) {
        RE (j, m) {
          if (lev[l][i][j] != lev[prev][i][j]) {
            //cerr<<l<<" "<<prev<<" "<<i<<" "<<j<<endl;
            diff++;
          }
        }
      }
      edges.PB(MP(diff, MP(l, prev)));
    }
    //cerr<<"l\n";
  }
  sort(ALL(edges));
  //debugv(edges);
  for (auto e : edges) {
    int v1 = e.second.first;
    int v2 = e.second.second;
    int c = e.first;
    if (w * c <= n * m && Union(v1, v2)) {
      res -= n * m - w * c;
      slo[v1].PB(v2);
      slo[v2].PB(v1);
    }
  }
  cout<<res<<endl;
  RE (i, k) {
    if (vis[i]) {
      continue;
    }
    dfs(i, 0);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}