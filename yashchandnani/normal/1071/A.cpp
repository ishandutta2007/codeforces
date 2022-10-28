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
bool vis[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int a,b;cin>>a>>b;
	int ans = 1e5;
	while(1ll*ans*(ans+1)/2>a+b) ans--;
	bool fg = 0;
	if(a>b) swap(a,b),fg=1;
	int mx = ans;
	while(mx>0&&a>0){
		mx = min(mx,a);
		a-=mx;
		vis[mx]=1;
		mx--;
	}
	vi aa,bb;
	repA(i,1,ans){
		if(vis[i]) aa.pb(i);
		else bb.pb(i);
	}
	if(!fg){
		cout<<sz(aa)<<'\n';
		trav(i,aa) cout<<i<<' ';
		cout<<'\n';
	}
		cout<<sz(bb)<<'\n';
		trav(i,bb) cout<<i<<' ';
		cout<<'\n';
	if(fg){
		cout<<sz(aa)<<'\n';
		trav(i,aa) cout<<i<<' ';
		cout<<'\n';
	}
	return 0;
}