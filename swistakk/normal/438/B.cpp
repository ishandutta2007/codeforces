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
const int N = 1e6 + 5;
int rep[N];
ll sz[N];
int vis[N];
int Find(int v) {
	if (rep[v] == v) {
		return rep[v];
	}
	rep[v] = Find(rep[v]);
	return rep[v];
}
ll Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) {
		return 0;
	}
	int to_ret = sz[b];
	if (sz[a] < sz[b]) {
		swap(a, b);
	}
	rep[b] = a;
	sz[a] += sz[b];
	return to_ret;
}
ll ani[N];
vector<int> slo[N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
	make2(ll, n, m)
  VPII area;
	RE (i, n) {
		cin>>ani[i];
		area.PB(MP(ani[i], i));
		rep[i] = i;
		sz[i] = 1;
	}
	ll res = 0;
	RE (i, m) {
		make2(int, a, b);
		slo[a].PB(b);
		slo[b].PB(a);
	}
	sort(ALL(area), greater<pair<int, int> >());
	for (auto p : area) {
		
		int v = p.second;
		//debug(v);
		vis[v] = 1;
		for (auto nei : slo[v]) {
			if (!vis[nei]) {
				continue;
			}
			ll heh = sz[Find(v)];
			int new_vs = Union(v, nei);
			//cerr<<ani[v]<<" "<<new_vs<<" "<<heh<<endl;
			res += ani[v] * new_vs * heh;
		}
	}
	
	
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  cout<<2.0 * res / (n * (n - 1))<<endl;
  
  
  // nie zapomnij o ll
  return 0;
}