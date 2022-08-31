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
const int N = 3e5 + 5;
struct Edge {
  ll a, c, type;
  Edge(int a_, int c_, int t_) : a(a_), c(c_), type(t_) {}
};
vector<Edge> slo[N];
ll dis[N];
int block[N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make3(int, n, m, k);
  RE (i, m) {
    make3(int, u, v, x);
    slo[u].PB(Edge(v, x, 0));
    slo[v].PB(Edge(u, x, 0));
  }
  RE (i, k) {
    make2(int, s, x);
    slo[1].PB(Edge(s, x, 1));
  }
  FOR (i, 2, n) {
    dis[i] = 1e18;
  }
  set<pair<ll, int> > secik;
  secik.insert(MP(0, 1));
  while (!secik.empty()) {
    auto p = *(secik.begin());
    secik.erase(p);
    int v = p.second;
    ll act_dis = p.first;
    for (auto e : slo[v]) {
      int nei = e.a;
      ll new_dis = e.c + act_dis;
      if (new_dis <= dis[nei] && e.type == 0) {
        block[nei] = 0;
      }
      if (new_dis < dis[nei]) {
        secik.erase(MP(dis[nei], nei));
        dis[nei] = new_dis;
        secik.insert(MP(dis[nei], nei));
        if (e.type == 1) {
          block[nei] = 1;
        }
      }
    }
  }
  int cnt = 0;
  RE (i, n) {
    //cerr<<i<<" "<<dis[i]<<" "<<block[i]<<endl;
    cnt += block[i];
  }
  cout<<k - cnt<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}