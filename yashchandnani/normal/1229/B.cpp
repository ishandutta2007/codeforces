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
vector<pair<ll,int>> g[100009];
ll x[100009];
vi g2[100009];
ll fns = 0;
const ll mod = 1e9+7;
void dfs(int v,int p){
	g[v].pb(mp(x[v],1));
	int j = sz(g[p]);
	while(j){
		if(g[v].back().fst==__gcd(g[p][j-1].fst,x[v])) g[v].back().snd+=g[p][j-1].snd;
		else g[v].pb(mp(__gcd(g[p][j-1].fst,x[v]),g[p][j-1].snd));
		j--;
	}
	reverse(all(g[v]));
	trav(i,g[v]) fns+=i.fst*i.snd%mod;
	trav(i,g2[v]) if(i!=p) dfs(i,v);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	repA(i,1,n) cin>>x[i];
	rep(i,n-1) {
		int u,v;cin>>u>>v;
		g2[u].pb(v);
		g2[v].pb(u);
	}
	dfs(1,0);
	cout<<fns%mod;
	return 0;
}