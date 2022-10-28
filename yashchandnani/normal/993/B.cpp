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
set<int> xy;
set<int> ans1[13],ans2[13],tns;
int cnt(pii x,pii y,int& z){
	int ans = 0;
	if(x.fst==y.fst||x.fst==y.snd) ans++,z=x.fst;
	if(x.snd==y.fst||x.snd==y.snd) ans++,z=x.snd;
	return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	vector<pii> x,y;
	int n,m;cin>>n>>m;
	rep(i,n){
		int u,v;cin>>u>>v;
		if(u>v) swap(u,v);
		x.pb(mp(u,v));
	}
	rep(i,m){
		int u,v;cin>>u>>v;
		if(u>v) swap(u,v);
		y.pb(mp(u,v));
	}
	int z;
	rep(i,n){
		rep(j,m){
			if(cnt(x[i],y[j],z)==1) ans1[i].insert(z),ans2[j].insert(z),xy.insert(z);
		}
	}
	if(sz(xy)==1) {
		cout<<*(xy.begin());
		return 0;
	}
	bool fx=1,fy=1;
	rep(i,n) if(sz(ans1[i])>1) fx=0;
	rep(i,m) if(sz(ans2[i])>1) fy=0;
	if(fx&&fy) cout<<0;
	else cout<<-1;
	return 0;
}