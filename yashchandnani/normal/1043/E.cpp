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
int x[300009],y[300009];
ll ans[300009];
vector<pii> v;
void solve(){


}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	ll tx=0,ty=0;
	rep(i,n){
		cin>>x[i]>>y[i];
		tx+=x[i],ty+=y[i];
		v.pb(mp(y[i]-x[i],i));
	}
	sort(all(v));
	ll cx = 0,cy=0;
	rep(i,n){
		ans[v[i].snd]+=1ll*(i)*x[v[i].snd]+1ll*(n-i-1)*y[v[i].snd] + cy + tx-cx-x[v[i].snd];
		cx+=x[v[i].snd];
		cy+=y[v[i].snd];
	}
	rep(i,m){
		int u,v;cin>>u>>v;
		u--,v--;
		ans[u]-=min(x[u]+y[v],x[v]+y[u]);
		ans[v]-=min(x[u]+y[v],x[v]+y[u]); 
	}
	rep(i,n) cout<<ans[i]<<' ' ;
	return 0;
}