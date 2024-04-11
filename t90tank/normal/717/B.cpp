#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
const ll mod1 = (ll)1e9+9;
const ll mod2 = (ll)1e9+7; 

ll n, c0, c1; 

ll getmul(ll a, ll k, ll mod) {
	ll ret = 1; 
	while (k > 0) {
		if (k & 1) ret = (ret * a) % mod; 
		k /= 2; 
		a = (a*a) % mod; 
	}
	return ret; 
}

ll C(ll n, ll m) {
	ll r1 = 1, r2 = 1; 
	for (ll i = 1; i <= m; ++i) {
		r1 = (r1 * (n-i+1)) % mod1 * getmul(i,mod1-2,mod1) % mod1; 
		r2 = (r2 * (n-i+1)) % mod2 * getmul(i,mod2-2,mod2) % mod2; 
	}
	if (r1 != r2) return -1; 
	return r1; 
}

bool check(ll c) {
	//cout<<c<<endl; 
	ll sum = 0; 
	for (ll i = 0; i*c0 <= c; ++i) {
		ll j = (c-i*c0)/c1; 
		ll tmp = C(i+j+1,i+1); 
		//cout<<i<<' '<<j<<' '<<tmp<<endl; 
		if (tmp == -1) return true;
		sum += tmp; 
		if (sum >= n-1) return true; 
	}
	return false; 
}

void solve(ll c) {
	//cout<<c<<endl; 
	ll ans = 0; 
	ll sum = 0; 
	for (ll i = 0; i*c0 <= c; ++i) {
		if (i == 0) {
			ll t = c/c1+1; 
			ans += ((t-1)*c1)*t/2; 
			sum += t; 
		}
		else {
			for (ll j = 0; i*c0+j*c1 <= c; ++j) {
				ll t = min(sum, C(i+j,i)); 
				ans += t*(i*c0+j*c1); 
				sum += t; 
			}
		}
	}
	cout<<ans-(sum-(n-1))*c+(c0+c1)*(n-1)<<endl; 
}

int main() {
	cin>>n>>c0>>c1; 
	if (c0*c1 == 0) {
		cout<<ll(n-1)*(c0+c1)<<endl; 
		return 0; 
	}
	if (c0 < c1) swap(c0, c1); 
	ll l = 0, r = c1*n*100; 
	while (l + 1 < r) {
		ll m = (l + r) / 2; 
		if (check(m)) r = m; 
		else l = m; 
	}
	solve(r); 
}