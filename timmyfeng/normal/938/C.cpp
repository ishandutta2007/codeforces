#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;

		if (!x) {
			cout << 1 << ' ' << 1 << '\n';
			continue;
		}

		bool ok = false;
		for (int i = 1; i * i <= x && !ok; ++i) {
			if (x % i)
				continue;

			int j = x / i;
			if ((j - i) % 2 == 0 && j - i) {
				int n = (i + j) / 2;
				int k = (j - i) / 2;
				if (n / (n / k) == k) {
					cout << n << ' ' << n / k << '\n';
					ok = true;
				}
			}
		}

		if (!ok) {
			cout << -1 << '\n';
		}
	}
}