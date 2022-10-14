#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1e18;

void solve() {
	int N; cin >> N;
	vector<int> c(N);
	for (int& i : c) cin >> i;
	vector<ll> mn(2), s(2);
	mn[0] = mn[1] = inf;
	ll ans = inf;
	for (int i = 0; i < N; i++) {
		s[i % 2] += c[i];
		mn[i % 2] = min(mn[i % 2], (ll) c[i]);
		if (i > 0) {
			ll need[2];
			need[0] = N - (i + 2) / 2;
			need[1] = N - (i + 1) / 2;
			ans = min(ans, s[0] + s[1] + mn[0] * need[0] + mn[1] * need[1]);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}