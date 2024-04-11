
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define ar array

const int mxN = 2e5 + 5;

ll modpow(ll x, ll y, ll mod) {
	ll result = 1;

	while(y) {
		if(y&1)
			result = ((result % mod) * (x%mod)) % mod;
		x = (x*x) % mod;
		y >>= 1;
	}
	return result;
}

bool miller_rabin(ll n) {
	if(n < 2)
		return false;

	for(int64_t pr : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
		if(n % pr == 0)
			return n == pr;


	int64_t r = __builtin_ctz(n);
	int64_t d = (n-1) >> r;

	for(int64_t pr : {2, 3, 61}) {
		ll res = modpow(pr % n, d, n);
		if(res == 1 || res == n - 1) continue;

		while(d != n - 1) {
			res *= res;
			res %= n;
			d >>= 1;

			if(res == 1)
				return false;
			else if(res == n-1)
				break;
		}

		if(res != n - 1)
			return false;
	}
	return true;
}

const ll mod = 1e9+7;
ll fac[200001];
void solve() {
	int n; cin >> n;
	fac[0]=1;
	for(int i = 1; i <= 100000; i++) {
		fac[i] = fac[i-1] * (ll) i;
		fac[i] %= n;
	}

	vector<int> re;
	for(int i = 1; i <= n; i++) {
		if(i == 1 || __gcd(i, n) == 1) {
			re.push_back(i);
		}
	}

	ll sup=1;
	for(auto &i : re)
		sup = (sup * i) % n;

	vector<int> ans;
	for(auto &i : re) {
		if(sup != 1 && i == sup) {
			sup /= i;
		} else {
			ans.push_back(i);
		}
	}
	cout << ans.size() << "\n";
	for(auto &e: ans)
		cout << e << " ";

	cout << "\n";



}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin >> t;
	int i = 1;
	while(t--) {
		solve();
		++i;
	}
}