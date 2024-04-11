#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5;
int ps[MX + 1];
vector<int> v[MX + 1];

void solve() {
	int n;
	cin >> n;
	fill(ps, ps + n + 1, 0);
	fill(v, v + n + 1, vector<int>());
	for (int i = 0 ; i< n; ++i) {
		int m, p;
		cin >> m >> p;
		++ps[m];
		v[m].push_back(p);
	}
	for (int i = 1; i <= n; ++i) {
		ps[i] += ps[i - 1];
	}

	long long ans = 0;
	multiset<int> ava;
	int ct = 0;
	for (int i = n; i; --i) {
		for (auto j : v[i]) {
			ava.insert(j);
		}
		for ( ; ct + ps[i - 1] < i; ++ct) {
			ans += *ava.begin();
			ava.erase(ava.begin());
		}
	}
	cout << ans << '\n';
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