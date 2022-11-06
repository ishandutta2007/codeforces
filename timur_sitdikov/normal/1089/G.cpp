#include <bits/stdc++.h>
using namespace std;

void solve() {
	int k;
	cin >> k;
	vector<int> a(7);
	int cnt = 0;
	for (auto &x: a) {
		cin >> x;
		cnt += x;
	}
	int mindays = 1 + (k - 1) * 7;
	for (int i = 0; i < 7; i++) {
		if (!a[i]) {
			continue;
		}
		int days = 1 + ((k - 1) / cnt) * 7;
		for (int j = (i + 1) % 7, rem = (k - 1) % cnt; rem; j = (j + 1) % 7) {
			days++;
			if (a[j]) {
				rem--;
			}
		}
		mindays = min(mindays, days);
	}
	cout << mindays << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}