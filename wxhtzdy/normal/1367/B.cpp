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
		int a[n];
		int bad1 = 0, bad2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i % 2 != a[i] % 2) {
				if (i % 2 == 0) bad1++;
				else bad2++;
			}
		}
		if (bad1 != bad2) {
			cout << -1 << endl;
			continue;
		}
		cout << bad1 << endl;
	}
	return 0;
}