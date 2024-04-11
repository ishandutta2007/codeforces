#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, h;

ll get_sum(ll a) {
	return a * (a + 1) / 2;
}

ll calc(ll a) {
	ll required = get_sum(a) +
			(a > h ? get_sum(a - 1) - get_sum(h - 1) : 0);
	if (required > n)
		return 1e18;
	ll required_cnt = a + (a > h ? a - h : 0);
	return required_cnt + (n - required) / a + !!((n - required) % a);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> h;

	ll lb = 1, rb = 2e9;
	while (lb < rb) {
		ll mb = (lb + rb) / 2;
		if (calc(mb + 1) != 1e18) {
			lb = mb + 1;
		} else {
			rb = mb;
		}
	}

	cout << calc(lb) << '\n';
}