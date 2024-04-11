#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int t, n;
long long k;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (1ll << (min(n - 1, 60)) < k) {
			cout << "-1\n";
			continue;
		}
		for (int i = 1; i <= n;) {
			for (int j = 1;; j++) {
				long long here = 1ll << (min(60, max(0, (n - i + 1) - j - 1)));
				if (here < k) 
					k -= here;
				else {
					for (int k = i + j - 1; i <= k; k--)
						cout << k << " ";
					i += j;
					break;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}