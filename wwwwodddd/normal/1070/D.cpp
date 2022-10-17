#include <bits/stdc++.h>
using namespace std;
int n, k, a[200020];
long long ans = 0;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int t = (a[i - 1] + k - 1) / k;
		int l = t * k - a[i - 1];
		a[i] = max(0, a[i] - l);
		ans += t;
	}
	printf("%lld\n", ans);
	return 0;
}