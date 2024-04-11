#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[501], b[501];
bool dp[501], pos[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll suma = 0, sumb = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		suma += a[i];
		sumb += b[i];
	}
	
	pos[0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			if (a[i] < j || b[i] < k - j)
				continue;
			memset(dp, false, sizeof dp);
			for (int l = 0; l < k; ++l) {
				if (pos[l]) {
					dp[(l + j) % k] = true;
				}
			}
			for (int l = 0; l < k; ++l) {
				pos[l] |= dp[l];
			}
		}
	}

	ll ans = suma / k + sumb / k;
	for (int i = 0; i < k; ++i) {
		if (!pos[i])
			continue;
		if (i <= suma % k && k - i <= sumb % k) {
			cout << ans + 1 << '\n';
			return 0;
		}
	}
	cout << ans << '\n';
}