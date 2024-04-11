#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long ta, tb;
long long a[200020];
long long b[200020];
long long ans;
int main() {
	scanf("%d%d%lld%lld%d", &n, &m, &ta, &tb, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%lld", &b[i]);
	}
	ans = 0;
	if (k >= n || k >= m) {
		ans = 1e18;
	}
	for (int i = 0; i < n && i <= k; i++) {
		int pb = lower_bound(b, b + m, a[i] + ta) - b;
		if (pb + k - i >= m) {
			ans = 1e18;
		} else {
			ans = max(ans, b[pb + k - i]);
		}
	}
	if (ans == 1e18) {
		cout << -1 << endl;
	} else {
		cout << ans + tb << endl;
	}
	return 0;
}