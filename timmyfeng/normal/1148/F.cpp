#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

const int LOG_M = 62;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> val(n);
	vector<ll> mask(n);
	ll init = 0;
	for (int i = 0; i < n; ++i) {
		cin >> val[i] >> mask[i];
		init += val[i];
	}

	if (init < 0) {
		for (auto& i : val) {
			i = -i;
		}
	}

	ll ans = 0;
	for (int i = 0; i < LOG_M; ++i) {
		ll sum = 0;
		for (int j = 0; j < n; ++j) {
			if ((mask[j] & (1LL << i)) && !(mask[j] >> (i + 1LL))) {
				sum += val[j];
			}
		}

		if (sum > 0) {
			ans |= 1LL << i;
			for (int j = 0; j < n; ++j) {
				if ((mask[j] & (1LL << i)) && (mask[j] >> (i + 1LL))) {
					val[j] = -val[j];
				}
			}
		}
	}
	cout << ans << "\n";
}