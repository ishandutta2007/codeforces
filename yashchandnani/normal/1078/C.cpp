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
vi g[300009];
int n;
ll d[300009][4];
const ll mod=998244353;
void dfs(int v,int p=-1){
	d[v][0] = 1;
	d[v][2] = 1;
	d[v][3] = 1;
	trav(i,g[v]){
		if(i!=p){
			dfs(i,v);
			ll cur0 = d[v][0],cur1 = d[v][1],cur2 = d[v][2];
				d[v][0] = (2ll*cur0*d[i][1]+cur0*d[i][2])%mod;
				d[v][1] = (cur1*(2ll*d[i][1]+d[i][2])+d[v][3]*d[i][0])%mod;
				d[v][2] = cur2*(d[i][1]+d[i][2])%mod;
				d[v][3] = d[v][3]*(2*d[i][1]+d[i][2])%mod;
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	cin>>n;
	rep(i,n-1){
		int u,v;cin>>u>>v;
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	cout<<(d[0][1]+d[0][2])%mod;
	return 0;
}