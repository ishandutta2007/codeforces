#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<bool> used(n + 1);
	int unmar = 0;
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		bool mar = false;
		while (k--) {
			int g;
			cin >> g;
			if (!used[g] && !mar) {
				used[g] = true;
				mar = true;
			}
		}
		if (!mar) {
			unmar = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			cout << "IMPROVE" << '\n';
			cout << unmar << ' ' << i << '\n';
			return;
		}
	}
	cout << "OPTIMAL" << '\n';
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