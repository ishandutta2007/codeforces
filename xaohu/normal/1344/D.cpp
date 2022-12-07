#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;

int n, a[1 << 17];
ll k, b[1 << 17];

ll f(int i, ll x) {
	return -3 * x * x - 3 * x - 1 + a[i];
}

ll solve(ll delta) {
	for (int i = 0; i < n; ++i) {
		ll l = 0, r = a[i];
		while (l < r) {
			ll m = (l + r + 1) / 2;
			if (f(i, m - 1) >= delta)
				l = m;
			else
				r = m - 1;
		}
		b[i] = l;
	}
	return accumulate(b, b + n, 0LL);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	ll l = -4e18, r = 4e18;
	while (l < r) {
		ll m = l + (r - l) / 2;
		if (solve(m) > k)
			l = m + 1;
		else
			r = m;
	}
	k -= solve(l);
	for (int i = 0; i < n; ++i)
		if (k && f(i, b[i]) == l - 1 && b[i] < a[i]) {
			k--;
			b[i]++;
		}
	assert(!k);
	for (int i = 0; i < n; ++i)
		cout << b[i] << " ";
	return 0;
}