#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		int ndx = find(a.begin(), a.end(), i) - a.begin();
		if (ndx == mx) {
			++mx;
		}
		if (ndx < mx)
			continue;
		rotate(a.begin() + mx, a.begin() + ndx, a.begin() + ndx + 1);
		mx = ndx;
	}

	for (auto i : a) {
		cout << i << ' ';
	}
	cout << '\n';
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