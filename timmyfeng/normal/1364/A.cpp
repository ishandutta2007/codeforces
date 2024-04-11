#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		int sum = 0;
		for (auto& i : a) {
			cin >> i;
			sum += i;
		}

		if (sum % x) {
			cout << n << '\n';
		} else {
			int i = 0;
			while (i < n && a[i] % x == 0) {
				++i;
			}

			int j = n - 1;
			while (j >= 0 && a[j] % x == 0) {
				--j;
			}

			if (i == n) {
				cout << -1 << '\n';
			} else {
				cout << max(j, n - 1 - i) << '\n';
			}
		}
	}
}