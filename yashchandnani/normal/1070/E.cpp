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
int p[200009];
void solve(){
	int n,m;ll t;cin>>n>>m>>t;
	vi v(1,1);
	rep(i,n) cin>>p[i],v.pb(p[i]);
	sort(all(v));
	int lo = 0,hi = n;
	while(lo<hi){
		int md = (lo+hi)/2;
		md++;
		int d = v[md];
		int k = (md)/m*m;
		if(md%m==0) k-=m;
		ll s = 0;
		int cnt =0;
		rep(i,n) {
			if(p[i]>d) continue;
			if(s+p[i]>t) break;
			if(k) s+=2*p[i],k--;
			else s+=p[i];
			cnt++;
		}
		if(cnt>=md) lo = md;
		else hi = md-1;
	}
	cout<<lo<<' '<<v[lo]<<'\n';
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	
	
	return 0;
}