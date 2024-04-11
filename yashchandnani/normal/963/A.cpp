#include <bits/stdc++.h>
using namespace std;

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
int s[100009];
const ll mod = 1e9+9;
ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}

ll cal(ll k,ll a,ll b,ll n){
	ll c = modpow(a,n);
	ll d = 1;
	ll ans = 0;
	ll inv = modpow(a,mod-2);
	rep(i,k){
		ans+=(c*d*s[i])%mod;
		c=c*inv%mod;
		d=d*b%mod;
	}
	ans%=mod;
	ans+=mod;
	ans%=mod;
	return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	ll n,a,b,k;cin>>n>>a>>b>>k;	
	rep(i,k){
		char c;cin>>c;
		if(c=='+') s[i]=1;
		else s[i]=-1;
	}
	ll val = cal(k,a,b,n);
	if(val==0) {
		cout<<0;return 0;
	}
	ll t = (n+1)/k;
	if(a==b){
		ll ans = val*t%mod;
		ans+=mod;ans%=mod;
		cout<<ans;
		return 0;
	}
	ll r = 1ll*modpow(modpow(a,mod-2),k)*modpow(b,k)%mod;
	if(r==1){
		ll ans = val*t%mod;
		ans+=mod;ans%=mod;
		cout<<ans;
		return 0;
	}
	
	ll x = 1ll*(1ll*modpow(r,t)-1)*modpow(r-1,mod-2)%mod;
	ll ans = x*val%mod;
	ans%=mod;
	ans+=mod;
	ans%=mod;
	cout<<ans;
	return 0;
}