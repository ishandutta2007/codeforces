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
vector<pii> g[500009];
ll ans = 0,dpx[500009],dp2[500009];
vector<pair<ll,int>> dp[500009];
int w[500009];
int cp[500009];
void dfs(int v,int pr = -1){
	dpx[v] = w[v];
	dp[v].pb(mp(w[v],v));
	trav(i,g[v]){
		if(i.fst!=pr){
			cp[i.fst] = i.snd;
			dfs(i.fst,v);
			if(dpx[i.fst]>=i.snd){
				dpx[v] = max(dpx[v],dpx[i.fst]-i.snd+w[v]);
				dp[v].pb(mp(dpx[i.fst]-i.snd+w[v],i.fst));
			}
		}
	}
	sort(all(dp[v]));
}
void dfs2(int v,int pr=-1){
	dp2[v] = dpx[v];
	if(pr!=-1){
		repD(i,sz(dp[pr])-1,0){
			if(dp[pr][i].snd==v) continue;
			if(cp[v]<=dp[pr][i].fst){
				dp2[v] = max(dp2[v],dp[pr][i].fst-cp[v]+w[v]);
				dp[v].pb(mp(dp[pr][i].fst-cp[v]+w[v],pr));
				sort(all(dp[v]));
			}
			break;
		}
	}
	ans = max(ans,dp2[v]);
	trav(i,g[v]){
		if(i.fst!=pr) dfs2(i.fst,v);
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cin>>w[i];
	rep(i,n-1){
		int u,v,c;cin>>u>>v>>c;u--,v--;
		g[u].pb(mp(v,c));
		g[v].pb(mp(u,c));
	}
	dfs(0);
	dfs2(0);
	cout<<ans;	
	
	return 0;
}