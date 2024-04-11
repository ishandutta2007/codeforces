#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		auto calc = [](ll x) {
			ll cur = 1, res = 0;
			for (int i = 0; i < 40; ++i) {
				if (x & (1LL << i)) {
					res += cur;
				}
				cur *= 3;
			}
			return res;
		};

		ll lb = 1, rb = (1LL << 40) - 1;
		while (lb < rb) {
			ll mb = (lb + rb) / 2;
			if (calc(mb) >= n) {
				rb = mb;
			} else {
				lb = mb + 1;
			}
		}
		cout << calc(lb) << '\n';
	}
}