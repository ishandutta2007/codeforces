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
		int odd = 0;
		int even = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if (a % 2 != i % 2) {
				if (i % 2) {
					++odd;
				} else {
					++even;
				}
			}
		}

		if (odd != even) {
			cout << -1 << "\n";
		} else {
			cout << odd << "\n";
		}
	}
}