#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using ld = long double;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int h, c, t;
		cin >> h >> c >> t;

		if (t <= (h + c) / 2) {
			cout << 2 << '\n';
			continue;
		}

		auto calc = [&](ll a) {
			return (ld)((a + 1) * h + a * c) / (2 * a + 1);
		};

		ll lb = 0, rb = 1e12;
		while (lb < rb) {
			ll mb = (lb + rb + 1) / 2;
			if (calc(mb) < t) {
				rb = mb - 1;
			} else {
				lb = mb;
			}
		}

		if (abs(t - calc(lb)) <= abs(t - calc(lb + 1))) {
			cout << lb * 2 + 1 << '\n';
		} else {
			cout << lb * 2 + 3 << '\n';
		}
	}
}