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
const ll mod= 998244353;
ll f[1009],inv[1009];
ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
		if (b) { ll d = euclid(b, a % b, y, x);
					return y -= a/b * x, d; }
			return x = 1, y = 0, a;
}
ll modInverse(ll a,ll p){
		ll x,y;
			euclid(a,p,x,y);
				return ((x%p+p)%p);
}
void pre(){
 f[0] = f[1] = inv[0] =inv[1] = 1;
 repA(i,2,1003){
	 f[i] = f[i-1]*i%mod;
	inv[i] = inv[i-1]*modInverse(i,mod)%mod;
 }

}
ll C(int n,int r){
	if(r<0||r>n) return 0;
	else return f[n]*inv[r]%mod*inv[n-r]%mod;
}
void solve(){


}
ll ans[1009];
ll fns;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vi v(n);
	rep(i,n) cin>>v[i];
	ans[0] = 1;
	rep(i,n){
		ans[i+1]+=ans[i];
		rep(j,i){
			if(v[j]>i-j) continue;
			ll y = C(i-j-1,v[j]-1);
			ans[i+1]+=ans[j]*y%mod;
		}
		ans[i+1]%=mod;
		fns+=(ans[i+1]-ans[i]+mod)%mod;
	}
	cout<<fns%mod;	
	return 0;
}