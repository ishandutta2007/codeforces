#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	ll ans = 0;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans += a[i];
	}

	int q;
	cin >> q;
	vector<int> cnt(n + 1);
	map<pair<int, int>, int> mp;
	while (q--) {
		int u;
		pair<int, int> pos;
		cin >> pos.first >> pos.second >> u;

		if (mp.count(pos)) {
			int old = mp[pos];
			--cnt[old];
			if (cnt[old] < a[old]) {
				++ans;
			}
			mp.erase(pos);
		}

		if (u) {
			++cnt[u];
			if (cnt[u] <= a[u]) {
				--ans;
			}
			mp[pos] = u;
		}

		cout << ans << "\n";
	}
}