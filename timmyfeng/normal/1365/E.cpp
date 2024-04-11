#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	ll ans = 0;
	if (n <= 3) {
		for (auto i : a) {
			ans |= i;
		}
	} else {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int k = j + 1; k < n; ++k) {
					ans = max(ans, a[i] | a[j] | a[k]);
				}
			}
		}
	}
	cout << ans << '\n';
}