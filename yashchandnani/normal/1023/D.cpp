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
int ans[200009];
int t[800009];
void push (int v) {
		if (t[v] != -1) {
					t[v*2] = t[v*2+1] = t[v];
							t[v] = -1;
								}
}
 
void update (int v, int tl, int tr, int l, int r, int color) {
		if (l > r)
					return;
			if (l == tl && tr == r)
						t[v] = color;
				else {
							push (v);
									int tm = (tl + tr) / 2;
											update (v*2, tl, tm, l, min(r,tm), color);
													update (v*2+1, tm+1, tr, max(l,tm+1), r, color);
														}
}
 
int get (int v, int tl, int tr, int pos) {
		if (tl == tr)
					return t[v];
			push (v);
				int tm = (tl + tr) / 2;
					if (pos <= tm)
								return get (v*2, tl, tm, pos);
						else
									return get (v*2+1, tm+1, tr, pos);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,q;cin>>n>>q;
	int ix = -1;
	rep(i,n){
		int x;cin>>x;
		if(x==0) ix = i;
		ans[i] = x;
		g[x].pb(i);
	}
	bool fg = 0;
	int cnt = 0;
	if(sz(g[q])==0){
		if(ix==-1) {
			cout<<"NO";return 0;
		}
		else ans[ix] = q;
	}
	repD(j,q,1){
		trav(i,g[j]){
			if(get(1,0,n+1,i)!=0) {
				cout<<"NO";return 0;
			}
		}
		if(sz(g[j])>0)update(1,0,n+1,g[j][0],g[j].back(),1);
	}
	cout<<"YES\n";
	rep(i,n){
		if(ans[i]==0) if(i!=0) ans[i] = ans[i-1];
	}
	repD(i,n-2,0) if(ans[i]==0) ans[i] = ans[i+1];
	rep(i,n){
		//if(ans[i]==0) ans[i] = 1;
		cout<<ans[i]<<' ';
	}

	return 0;
}