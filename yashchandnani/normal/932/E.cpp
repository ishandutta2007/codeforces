#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")
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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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
const int MOD = 1e9+7;
const int l = 5009;
ll f[l],inv[l];
void pre(){
	f[0]=inv[0]=f[1]=inv[1]=1;
	repA(i,2,l-5){
		f[i] = f[i-1]*i%MOD;
		inv[i] = inv[i-1]*modInverse(i,MOD)%MOD;
	}
}
ll C(int n,int k){
	if(k>n||k<0) return 0;
	return ((f[n]*inv[k]%MOD)*inv[n-k]%MOD)%MOD;
}
ll po(int n,ll k){
	ll ans = (k%2)?n:1;
	if(k<2) return ans;
	ll z = po(n,k>>1);
	return ans*(z*z%MOD)%MOD;
}
ll poi[10000];
ll S(int n,int k){
	ll ans = 0;
	rep(j,k+1){
		ll z = ((k-j)%2)?-1:1;
		z=z*C(k,j)%MOD;
		z=z*poi[j]%MOD;
		ans+=z;
	}
	ans%=MOD;
	ans*=inv[k];
	ans=(ans%MOD+MOD)%MOD;
	return ans;
}
ll dp[10000];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();	
	int n,k;cin>>n>>k;
	ll ans = 0;
	if(k==0){
		cout<<(po(2,n)-1+MOD)%MOD;
		return 0;
	}
	if(n<k){
		repA(i,1,n){
			ans+=po(i,k)*C(n,i)%MOD;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	dp[0] = 1;
	rep(i,k+3){
		poi[i] = po(i,k);
	}
	rep(i,k+1){
		ll z = dp[i];
		z=z*po(2,k-i)%MOD;
		z=z*f[i]%MOD;
		z=z*S(k,i)%MOD;
		ans+=z;
		dp[i+1] = (dp[i]*(n-i)%MOD)*modInverse(i+1,MOD)%MOD;
	}
	ans%=MOD;
	ans*=po(2,n-k);
	ans%=MOD;
	cout<<ans;
	return 0;
}