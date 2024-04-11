#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	
	int best = 1e9, ans = 0;
	for (int i = 0; i + k < n; ++i) {
		if (a[i + k] - a[i] < best) {
			best = a[i + k] - a[i];
			ans = a[i] + best / 2;
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