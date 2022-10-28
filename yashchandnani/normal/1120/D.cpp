#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
bool lf[200009];
int c[200009];
ll val[200009][2];
int fns=0;
vi ffns;
vi g[200009];
vector<ll> ans[200009];
void dfs2(int u,int p){
	lf[u]=1;
	trav(i,g[u]) if(i!=p){
		dfs2(i,u);
		lf[u]=0;
		val[u][0]+=min(val[i][0],val[i][1]);
		ans[u].pb(val[i][1]-min(val[i][0],val[i][1])+c[u]-c[i]);
	}
	if(lf[u]){
		val[u][0] = 1e16;
		val[u][1] = c[u];
	}
	else{
		sort(all(ans[u]));
		val[u][1] = val[u][0] + ans[u][0];
	}
}
void dfs3(int u,int p,bool fg){
	if(val[u][1]<=val[u][0]&&!fg) {
		fns++,ffns.pb(u);
		if(val[u][1]<val[u][0]) fg=1;
	}
	if(sz(ans[u])>1&&ans[u][0]==ans[u][1]) fg=0;
	trav(i,g[u]) if(i!=p){
		if(fg&&ans[u][0]==val[i][1]-min(val[i][0],val[i][1])+c[u]-c[i]) dfs3(i,u,1);
		else dfs3(i,u,0);
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	repA(i,1,n) cin>>c[i];
	rep(i,n-1){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs2(1,0);
	dfs3(1,0,0);
	cout<<min(val[1][0],val[1][1])<<' '<<fns<<'\n';
	sort(all(ffns));
	trav(i,ffns) cout<<i<<' ';
	return 0;
}