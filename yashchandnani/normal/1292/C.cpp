#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
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
vi g[3009];
int s[3009],n;
int pr[3009];
int d[3009][3009];
void dfs(int u,int p){
	s[u]=1;
	pr[u] = p;
	trav(i,g[u]){
		if(i!=p){
			dfs(i,u);
			s[u]+=s[i];
			d[u][i] = s[i];
		}
	}
	if(p) d[u][p] = n-s[u];
}
ll dp[3009][3009];
bool vis[3009][3009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	cin>>n;
	vector<pii> ed;
	rep(i,n-1){
		int u,v;cin>>u>>v;
		ed.pb(mp(u,v));
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	queue<pair<pii,pii>> q;
	ll fns=  0;
	trav(i,ed){
		int u = i.fst,v=  i.snd;
		if(pr[u]==v) swap(u,v);
		dp[u][v] = dp[v][u] = 1ll*s[v]*(n-s[v]);
		fns= max(fns,dp[u][v]);
		q.push(mp(mp(u,v),mp(v,u)));
	}
	while(!q.empty()){
		pair<pii,pii> z = q.front();
		int u = z.fst.fst,v=z.fst.snd,pu = z.snd.fst,pv=z.snd.snd;
		q.pop();
		if(vis[u][v]) continue;
		vis[u][v] = vis[v][u] = 1;
		trav(i,g[u]) if(i!=pu) {
			dp[i][v] = max(dp[i][v],dp[u][v]+1ll*d[u][i]*d[pv][v]);
			dp[v][i] = dp[i][v];
			fns=max(fns,dp[i][v]);
			q.push(mp(mp(i,v),mp(u,pv)));
		}
		swap(u,v);swap(pu,pv);
		trav(i,g[u]) if(i!=pu) {
			dp[i][v] = max(dp[i][v],dp[u][v]+1ll*d[u][i]*d[pv][v]);
			dp[v][i] = dp[i][v];
			fns=max(fns,dp[i][v]);
			q.push(mp(mp(i,v),mp(u,pv)));
		}
	}
	cout<<fns;
	return 0;
}