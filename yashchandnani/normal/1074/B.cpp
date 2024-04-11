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
bool vis1[1009],vis2[1009];
vi g[1009];
int ans;
void dfs(int v,int p){
	if(vis1[v]) {
		ans = v;
		return;
	}
	trav(i,g[v]) if(i!=p) dfs(i,v);
}
void solve(){
	fill(vis1);
	fill(vis2);
	int n;cin>>n;
	rep(i,n+1) g[i].clear();
	rep(i,n-1){
		int u,v;cin>>u>>v;
		g[u].pb(v);g[v].pb(u);
	}
	int k1,k2;cin>>k1;
	rep(i,k1){
		int x;cin>>x;
		vis1[x]=1;
	}
	cin>>k2;
	int lst = -1;
	rep(i,k2){
		int x;cin>>x;lst = x;
		vis2[x] = 1;
	}
	cout<<"B "<<lst<<endl;
	cin>>lst;
	dfs(lst,-1);
	cout<<"A "<<ans<<endl;
	cin>>lst;
	if(vis2[lst]) cout<<"C "<<ans<<endl;
	else cout<<"C "<<-1<<endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	return 0;
}