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
#define int long long
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

void pre(){


}

void solve(){


}
const ll mod = 998244353;
signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vi a,b,c,d;
	map<ll,int> m,m2;
	rep(i,n){
		ll x;cin>>x;
		ll y = sqrt(x)+0.5;
		if(y*y==x){
			ll z = sqrt(y)+0.5;
			if(z*z*z*z==x) {
				d.pb(z);
				m[z]+=4;
			}
			else {
			z = cbrt(x)+0.5;
			if(z*z*z==x) {
				d.pb(z);
				m[z]+=3;
			}
			else{d.pb(y);
				m[y]+=2;
			}
			}
		}
		else {
			ll z = cbrt(x)+0.5;
			if(z*z*z==x) {
				d.pb(z);
				m[z]+=3;
			}
			else a.pb(x),d.pb(x);
		}
	}
	ll ans = 1;
	while(!a.empty()){
		ll x = a.back();
		a.pop_back();
		bool fg = 0;
		rep(i,n){
			ll y = __gcd(x,d[i]);
			if(y!=1&&y!=x){
				m[y]++;
				m[x/y]++;
				fg = 1;
				break;
			}
		}
		if(!fg) {
			m2[x]++;
		}
	}
	trav(i,m) ans = (ans*(i.snd+1))%mod;
	trav(i,m2) ans = (ans*(i.snd+1)*(i.snd+1))%mod;
	cout<<ans;
	
	return 0;
}