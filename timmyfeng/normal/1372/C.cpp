#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		bool zero = true;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			--a[i];
			zero &= (i == a[i]);
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] != i && (a[i + 1] == i + 1 || i + 1 == n)) {
				++cnt;
			}
		}

		if (zero) {
			cout << 0 << "\n";
		} else if (cnt == 1) {
			cout << 1 << "\n";
		} else {
			cout << 2 << "\n";
		}
	}
}