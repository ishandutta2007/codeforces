#include <bits/stdc++.h>
using namespace std;

const int MXA = 200;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	int ans = 0;
	for (int k = 1; k <= MXA; ++k) {
		int i = -1, j = n, rep = 0, mx = 0;
		while (i < j) {
			int l = i + 1, r = j - 1;
			for ( ; l < n && a[l] != k; ++l);
			for ( ; r >= 0 && a[r] != k; --r);
			if (l >= r) break;
			i = l, j = r;
			++rep;
		}
		vector<int> cnt(MXA + 1);
		for (int it = i + 1; it < j; ++it) {
			mx = max(mx, ++cnt[a[it]]);
		}
		for ( ; rep; --rep) {
			ans = max(ans, rep * 2 + mx);
			for (--i; i >= 0 && a[i] != k; --i) {
				mx = max(mx, ++cnt[a[i]]);
			}
			for (++j; j < n && a[j] != k; ++j) {
				mx = max(mx, ++cnt[a[j]]);
			}
		}
		ans = max(ans, mx);
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