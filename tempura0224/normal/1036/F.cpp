#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	set<ll> st;
	vector<int> issq(1000001);
	for (int i = 1; i <= 1000; i++) issq[i * i] = 1;
	for (ll i = 2; i <= 1000000; i++) {
		if (issq[i]) continue;
		ll cur = i;
		ll sqi = i * i;
		while (1) {
			if ((double)cur * sqi > 2e18) break;
			cur *= sqi;
			st.insert(cur);
		}
	}
	vector<ll> ngs(st.size());
	int i = 0;
	for (auto e : st) ngs[i++] = e;
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll ng3 = upper_bound(ngs.begin(), ngs.end(), n) - ngs.begin();
		ll ng2 = (int)sqrt(n) + 2;
		while (ng2 * ng2 > n) --ng2;
		cout << n - ng3 - ng2 << "\n";
	}
	return 0;
}