#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5;

int hp[MX], dmg[MX], delta[MX], ndx[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	b = min(b, n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> hp[i] >> dmg[i];
		delta[i] = max(0, hp[i] - dmg[i]);
		ans += dmg[i];
	}

	if (!b) {
		cout << ans << '\n';
		return 0;
	}

	iota(ndx, ndx + n, 0);
	sort(ndx, ndx + n, [&](int a, int b) { return delta[a] > delta[b]; });

	vector<bool> used(n);
	for (int i = 0; i < b; ++i) {
		ans += delta[ndx[i]];
		used[ndx[i]] = true;
	}

	ll mx = 0;
	for (int i = 0; i < n; ++i) {
		ll res = (1LL << a) * hp[i] - dmg[i];
		if (used[i]) {
			res -= delta[i];
		} else {
			res -= delta[ndx[b - 1]];
		}

		if (res > mx) {
			mx = res;
		}
	}
	ans += mx;
	cout << ans << '\n';
}