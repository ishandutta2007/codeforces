#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		long long n, k;
		cin >> n >> k;
		if (n <= k) {
			cout << 1 << endl;
			continue;
		}
		long long ans = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i != 0) {
				continue;
			}
			if (n / i <= k) {
				ans = max(n /i, ans);
			} else {
				if(i <= k) {
					ans = max(ans, (long long)i);
				}
			}
		}
		cout << n / ans << endl;
	}
}