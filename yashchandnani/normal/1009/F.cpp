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
vi g[1000009];
int d[1000009],mx[1000009],ans[1000009],l[1000009];
void dfs(int v,int p){
	trav(i,g[v]){
		if(i!=p) {
			dfs(i,v) ;
			if(d[i]>d[v]) d[v] = max(d[v],d[i]),mx[v]=i;
		}
	}
	d[v]++;
}
void dfs2(int v,int p,vi& x){
	if(mx[v]) dfs2(mx[v],v,x);
	x.pb(1);
	if(mx[v]){
		if(l[mx[v]]==1) ans[v] = 0,l[v] = 1;
		else ans[v] = ans[mx[v]]+1,l[v] = l[mx[v]];
	}
	else ans[v] = 0,l[v] = 1;
	trav(i,g[v]){
		if(i!=p&&i!=mx[v]){
			vi z;
			dfs2(i,v,z);
			int j = 1;
			while(!z.empty()){
				j++;
				x[sz(x)-j]+=z.back();
				if((sz(x)-j>=sz(x)-1-ans[v])&&(l[v]<=x[sz(x)-j])) ans[v] = j-1,l[v] = x[sz(x)-j];
				if((j-1>ans[v])&&(l[v]<x[sz(x)-j])) ans[v]  = j-1,l[v] = x[sz(x)-j];
				z.pop_back();
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n-1){
		int u,v;cin>>u>>v;
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1,0);
	vi x;
	dfs2(1,0,x);
	repA(i,1,n) cout<<ans[i]<<' ';
	return 0;
}