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
const ll mod = 1000000007; // faster if const
ll f[1000009],inv[1000009];
void pre(){
	f[0] = f[1] = inv[0] = inv[1] = 1;
	repA(i,2,1000000){
		f[i] = f[i-1]*i%mod;
		inv[i] = (mod - inv[mod%i]*(mod/i)%mod)%mod;
	}
	repA(i,2,1000000) inv[i] = inv[i-1]*inv[i]%mod;

}
ll C(int n,int r){
	if(n==0&&r==0) return 1;
	if(n<r||r<0) return 0;
	return f[n]*inv[r]%mod*inv[n-r]%mod;
}
void solve(){


}
ll modpow(ll a, ll e) {
		if (e == 0) return 1;
			ll x = modpow(a * a % mod, e >> 1);
				return e & 1 ? x * a % mod : x;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,a,b;cin>>n>>m>>a>>b;
	ll ans = 0;
	repA(i,1,n-1){
		if(i<n-1) ans+=C(m-1,i-1)*modpow(m,n-1-i)%mod*C(n-2,i-1)%mod*f[i-1]%mod*(i+1)%mod*modpow(n,n-i-2)%mod;
		else ans+=C(m-1,i-1)*modpow(m,n-1-i)%mod*C(n-2,i-1)%mod*f[i-1]%mod;
	}
	cout<<ans%mod;
		
	return 0;
}