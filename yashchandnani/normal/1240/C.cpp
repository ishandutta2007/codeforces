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
int k;
vector<ll> dp[2];
vector<vector<pii>> g;
void dfs(int v,int p){
	vi diff;
	trav(i,g[v]){
		if(i.fst!=p){
			dfs(i.fst,v);
			if(dp[1][i.fst]+i.snd>dp[0][i.fst]) diff.pb(dp[1][i.fst]+i.snd-dp[0][i.fst]);
			dp[0][v]+=dp[0][i.fst];
		}
	}
	dp[1][v] = dp[0][v];
	sort(all(diff));
	reverse(all(diff));
	rep(i,min(sz(diff),k-1)){
		dp[1][v]+=diff[i];
	}
	rep(i,min(sz(diff),k)){
		dp[0][v]+=diff[i];
	}
}
void solve(){
	int n;cin>>n>>k;
	g.clear();
	g.resize(n);
	dp[0].clear();
	dp[0].resize(n,0);
	dp[1].clear();
	dp[1].resize(n,0);
	rep(i,n-1){
		int u,v,w;cin>>u>>v>>w;u--,v--;
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
	}
	dfs(0,-1);
	cout<<dp[0][0]<<'\n';
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();
	return 0;
}