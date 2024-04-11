#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calc(ll n) {
	ll res = 0, i = 1, k = 9, j = 9;
	for ( ; j < n; ++i, k *= 10, j += k) {
		res += i * k * (k + 1) / 2;
		res += i * k * (n - j);
	}
	k = n - j / 10;
	res += i * k * (k + 1) / 2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		ll k;
		cin >> k;
		--k;

		ll lb = 0, rb = 1e9;
		while (lb < rb) {
			ll mb = (lb + rb + 1) / 2;
			if (calc(mb) > k) {
				rb = mb - 1;
			} else {
				lb = mb;
			}
		}

		k -= calc(lb);
		ll cnt = 9, len = 1;
		while (k >= cnt * len) {
			k -= cnt * len;
			cnt *= 10;
			++len;
		}
		cout << to_string(cnt / 9 + k / len)[k % len] << '\n';
	}
}