#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x;
signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		if (x % 2050) puts("-1");
		else {
			x /= 2050;
			int ans = 0;
			while (x) {
				ans += x % 10, x /= 10;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}