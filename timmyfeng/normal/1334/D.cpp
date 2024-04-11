#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	ll n, l, r;
	cin >> n >> l >> r;
	bool ext = false;
	if (l >= n * (n - 1) + 1) {
		cout << 1 << '\n';
		return;
	}
	if (r >= n * (n - 1) + 1) {
		--r;
		ext = true;
	}

	ll i = 1, j = 1;
	while (i + (n - j) * 2 <= l) {
		i += (n - j) * 2;
		++j;
	}

	ll k = j + 1;
	for ( ; i <= r; ++i) {
		int ans;
		if (i % 2) {
			if (k > n) {
				++j;
				k = j + 1;
			}
			ans = j;
		} else {
			ans = k++;
		}
		if (i >= l) {
			cout << ans << ' ';
		}
	}
	if (ext) {
		cout << 1;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}