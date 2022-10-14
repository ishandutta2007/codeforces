#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	solve();

}
vector<ll> a;

void precomp() {
	for(ll i = 0; i < mxn; i++) a.push_back(i * (i+1) >> 1);
}
bool check(ll p) {
	return p == *lower_bound(a.begin(), a.end(), p);
}

void gogogo() {
	ll n, k;

	cin >> n >> k;

	ll dist = abs( n - k);
	if(dist == 0) {
		cout << 0 << "\n";
		return;
	}
	auto works = [&](int t, int d) {
		ll a = t * 1LL * (t + 1) / 2;
		return (a < d ? false : a % 2 == d % 2);
	};
	int ans = 1;
	while(!works(ans, dist)) ans++;
	cout << ans << "\n";

}
void solve() {
	precomp();
	int t; cin >> t;
	while(t--) {
		gogogo();
	}
}