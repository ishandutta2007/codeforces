#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		bool find = false;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				int k = n - i * 3 - j * 5;
				if (k >= 0 && k % 7 == 0) {
					cout << i << " " << j << " " << k / 7 << '\n';
					find = true;
					break;
				}
			}
			if (find) {
				break;
			}
		}
		if (!find) {
			cout << -1 << '\n';
		}
	}
	return 0;
}