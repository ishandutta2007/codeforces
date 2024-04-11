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
vi g[200009];
int a[200009],ix[200009],pt[200009];
vector<pii> v;
void dfs(int v,int p){
	pt[v] = p;
	trav(i,g[v]){
		if(p<0||i!=a[p]) dfs(i,ix[v]);
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n-1){
		int x,y;cin>>x>>y;
		g[x].pb(y);g[y].pb(x);
	}
	rep(i,n){
		int x;cin>>x;
		ix[x] = i;a[i] = x;
	}
	dfs(1,-1);
	bool fg=1;
	int ans = -1;
	rep(i,n){
		if(ans>pt[a[i]]) fg = 0;
		ans = pt[a[i]];
	}
	if(fg) cout<<"Yes";
	else cout<<"No";
	return 0;
}