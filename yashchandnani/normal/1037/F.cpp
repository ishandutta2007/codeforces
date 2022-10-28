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
int a[1000009];
int l[1000009],r[1000009];
ll cnt[1000009];
int fns[1000009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,k;cin>>n>>k;
	rep(i,n) cin>>a[i];
	vector<pii> v;
	v.pb(mp(1e9+7,-1));
	ll ans = 0;	
	rep(i,n){
		while(v.back().fst<a[i]) v.pop_back();
		l[i] = i-v.back().snd-1;
		v.pb(mp(a[i],i));
	}
	v.clear();
	v.pb(mp(1e9+7,n));
	repD(i,n-1,0){
		while(v.back().fst<=a[i]) v.pop_back();
		r[i] = v.back().snd-i-1;
		v.pb(mp(a[i],i));
	}
	repA(i,1,n){
		int st = i-k+1;
		if(st<=0) continue;
		int x = st/(k-1);
		int en = st-(x*(k-1));
		cnt[i] = 1ll*(x+1)*(st+en)/2;
		cnt[i]%=1000000007;
	}
	rep(i,n){
		ans+=1ll*a[i]*(cnt[l[i]+r[i]+1]-cnt[l[i]]-cnt[r[i]])%1000000007;
	}
	cout<<ans%1000000007;


	return 0;
}