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
int x[300009],y[300009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int mnx = 1e9,mxx = -1e9,mny=1e9,mxy=-1e9;
	rep(i,n) {
		cin>>x[i]>>y[i];
		mnx = min(x[i],mnx);
		mny = min(y[i],mny);
		mxx = max(x[i],mxx);
		mxy = max(y[i],mxy);
	}
	vi pts;
	rep(i,n){
		if(x[i]==mnx||x[i]==mxx||y[i]==mny||y[i]==mxy) pts.pb(i);
	}
	int ans = 0;
	rep(i,sz(pts)){
		rep(j,i){
			rep(k,n){
				if(k==pts[i]||k==pts[j]) continue;
				ans = max(ans,max(x[k],max(x[pts[i]],x[pts[j]])) - min(x[k],min(x[pts[i]],x[pts[j]])) + max(y[k],max(y[pts[i]],y[pts[j]])) - min(y[k],min(y[pts[i]],y[pts[j]])) );
			}
		}
	}
	cout<<2*ans<<' ';
	rep(i,n-3) cout<<2*(mxx-mnx)+2*(mxy-mny)<<' ';
	return 0;
}