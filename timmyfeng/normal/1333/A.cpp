#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (n * m % 2 == 0 && (i + j) % 2) {
					if (i == n - 1 && !ok) {
						cout << 'B';
						ok = true;
						continue;
					} else if (j == m - 1 && !ok) {
						cout << 'B';
						ok = true;
						continue;
					}
				}
				if ((i + j) % 2) {
					cout << 'W';
				} else {
					cout << 'B';
				}
			}
			cout << '\n';
		}
	}
}