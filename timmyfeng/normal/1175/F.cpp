#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 3e5;

ll pref[MX + 1], hsh[MX + 1], sum[MX + 1];
int a[MX + 1], ans, n;

void solve() {
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] ^ hsh[a[i]];
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] != 1) continue;
		int mx = 1;
		for (int j = i - 1; j && a[j] != 1; --j) {
			mx = max(mx, a[j]);
			if (j + mx - 1 <= n) {
				ans += ((pref[j + mx - 1] ^ pref[j - 1]) == sum[mx]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	mt19937 rng((uint64_t) new char);
	for (int i = 1; i <= n; ++i) {
		hsh[i] = rng();
		sum[i] = hsh[i] ^ sum[i - 1];
	}

	ans = count(a + 1, a + 1 + n, 1);
	solve();
	reverse(a + 1, a + 1 + n);
	solve();
	cout << ans << '\n';
}