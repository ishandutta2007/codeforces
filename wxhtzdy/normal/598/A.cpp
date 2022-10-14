#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n;
		cin >> n;
		long long sum = n * (n + 1) / 2, k = 0;
		for (long long i = 0; i < 30; i++) {
			if (1 << i <= n) {
				k += 1 << i;
			}
		}
		cout << sum - 2 * k << '\n';
	}
	return 0;
}