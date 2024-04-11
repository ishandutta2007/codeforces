#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5;
int l[MX], r[MX], amb[MX];

void solve() {
	int n;
	long long s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
	}

	int lo = 1, hi = 1e9;
	while (lo <= hi) {
		int mi = (lo + hi) / 2;
		long long cost = 0;
		int ctg = 0, cte = 0, ctl = 0;
		for (int i = 0; i < n; ++i) {
			if (mi < l[i]) {
				++ctg;
				cost += l[i];
			} else if (mi > r[i]) {
				++ctl;
				cost += l[i];
			} else {
				amb[cte++] = l[i];
			}
		}
		sort(amb, amb + cte);
		for (int i = 0; i < cte; ++i) {
			if (i + ctl < n / 2) {
				cost += amb[i];
			} else {
				cost += mi;
			}
		}
		if (ctg + cte > n / 2 && cost <= s) {
			lo = mi + 1;
		} else {
			hi = mi - 1;
		}
	}
	cout << hi << '\n';
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