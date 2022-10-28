#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f.pb(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F& f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,n) if (comp[i] < 0) dfs(i, g, f);
}
vector<vi> g,f,e;
bool vis[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m,h;cin>>n>>m>>h;
	int u[n+1];g.resize(n);
	repA(i,1,n) cin>>u[i];
	rep(i,m){
		int x,y;cin>>x>>y;
		if(u[x]+1==u[y]||(u[x]==h-1&&u[y]==0)) g[x-1].pb(y-1);
		if(u[y]+1==u[x]||(u[y]==h-1&&u[x]==0)) g[y-1].pb(x-1);
	}
	repA(i,1,n){
		if(sz(g[i-1])==0) {cout<<1<<'\n'<<i;return 0;}
	}
	scc<vector<vi>,vector<vi>>(g,f);
	e.resize(sz(f));
	rep(i,n){
		trav(j,g[i]) if(comp[i]!=comp[j]) e[comp[i]].pb(comp[j]);
	}
	int mn = n+1,ix=-1;
	rep(i,sz(f)){
		if(sz(e[i])==0&&sz(f[i])<mn){
			mn = sz(f[i]);ix=i;
		}
	}
	cout<<mn<<'\n';
	trav(i,f[ix]) cout<<i+1<<' ';
	return 0;
}