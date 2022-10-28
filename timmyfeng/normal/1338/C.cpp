#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<ll, ll> memo;

ll solve(ll n) {
	if (memo.count(n)) return memo[n];
	ll ext = n >> 2;
	return memo[n] = (solve(ext) << 2) ^ (solve((ext << 2) ^ n));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	memo[0] = 0;
	memo[1] = 2;
	memo[2] = 3;
	memo[3] = 1;
	while (t--) {
		ll n;
		cin >> n;
		ll sum = 0;
		ll inc = 1;
		ll v = 1;
		while (sum + inc < (n - 1) / 3 + 1) {
			sum += inc;
			inc *= 4;
			v <<= 2;
		}
		v += (n - 1) / 3 - sum;
		if (n % 3 == 1) {
			cout << v << '\n';
		} else if (n % 3 == 2) {
			cout << solve(v) << '\n';
		} else {
			cout << (v ^ solve(v)) << '\n';
		}
	}
}