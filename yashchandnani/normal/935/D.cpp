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
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const int MOD = 1e9+7;
ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
		if (b) { ll d = euclid(b, a % b, y, x);
					return y -= a/b * x, d; }
			return x = 1, y = 0, a;
}
ll modInverse(ll a,ll p=MOD){
		ll x,y;
			euclid(a,p,x,y);
				return ((x%p+p)%p);
}
ll solve(ll a,ll b,ll m){
	if(a!=0&&b!=0){
		if(a>b) return 1;
		else return 0;
	}
	ll ans = modInverse(m);
	if(a==0&&b!=0){
		ans=ans*(m-b)%MOD;
	}
	else if(b==0&&a!=0){
		ans=ans*(a-1)%MOD;
	}
	else{
		ans = ans*(1ll*(m-1)*((MOD+1)/2)%MOD)%MOD;
	}
	return ans;
}
		
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m;cin>>n>>m;
	int a[n],b[n];
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];
	ll x=0,y=1;
	rep(i,n){
		x+=y*solve(a[i],b[i],m)%MOD;
		x%=MOD;
		if(a[i]==0||b[i]==0) y=y*modInverse(m)%MOD;
		else if(a[i]!=b[i]) y=0;
	}
	cout<<x;
	return 0;
}