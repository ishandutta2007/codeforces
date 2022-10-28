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
const int l = 2000009;
ll f[l],inv[l];
void pre(){
		f[0]=inv[0]=f[1]=inv[1]=1;
		repA(i,2,l-5){
			f[i] = f[i-1]*i%MOD;
			inv[i] = inv[i-1]*modInverse(i,MOD)%MOD;
		}
}
ll fx(int n,int m){
	ll ans = f[n+m+1]*modInverse(n+1,MOD)%MOD;
	return ans;
}
int a[1000009],m[1000009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	ll ans =0;
	rep(i,n){
		cin>>a[i];
	}
	sort(a,a+n);
	rep(i,n){
		if(a[i]==a[n-1]) break;
		if(i!=0&&a[i]==a[i-1]) m[i] = m[i-1];
		else m[i] = i;
		ans+=1ll*(1ll*fx(n-1-m[i],m[i])*a[i]%MOD);
	}
	cout<<ans%MOD;
	return 0;
}