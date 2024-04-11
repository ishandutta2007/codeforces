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
ll p[500069];
map<ll,vector<pii>> m;
ll c[500009];
const ll mod = 1e9+7;
vi g[500009];
bool vis[500009];
int s;
void dfs(int v){
	vis[v] = 1;s++;
	trav(i,g[v]){
		if(!vis[i]) dfs(i);
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,mm,k;cin>>n>>mm>>k;
	p[0] = 1;
	repA(i,1,500067){
		p[i] = (p[i-1]*2)%mod;
	}
	rep(i,n) cin>>c[i];
	rep(i,mm){
		int u,v;cin>>u>>v;
		u--,v--;
		m[c[u]^c[v]].pb(mp(u,v));
	}
	ll ans = p[k+n];
	trav(i,m){
		int c= 0;
		trav(j,i.snd){
			g[j.fst].pb(j.snd);
			g[j.snd].pb(j.fst);
		}
		s = 0;
		trav(j,i.snd){
			if(!vis[j.fst]) dfs(j.fst),c++;
			if(!vis[j.snd]) dfs(j.snd),c++;

		}
		trav(j,i.snd){
			g[j.fst].clear();
			g[j.snd].clear();
			vis[j.fst]=vis[j.snd] = 0;
		}
		ans-=(p[n]-p[n-s+c]);
	}
	cout<<(ans%mod+mod)%mod;
	return 0;
}