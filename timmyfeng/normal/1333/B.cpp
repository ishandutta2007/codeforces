#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : b) {
		cin >> i;
	}
	vector<bool> pos(n), neg(n);
	for (int i = 1; i < n; ++i) {
		pos[i] = (pos[i - 1] || a[i - 1] == 1);
		neg[i] = (neg[i - 1] || a[i - 1] == -1);
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) continue;
		if (a[i] > b[i]) {
			if (!neg[i]) {
				cout << "NO" << '\n';
				return;
			}
		} else {
			if (!pos[i]) {
				cout << "NO" << '\n';
				return;
			}
		}
	}
	cout << "YES" << '\n';
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