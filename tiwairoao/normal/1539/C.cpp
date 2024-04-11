#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;

ll a[N + 5], d[N + 5], k, x; int n;
int main() {
	scanf("%d%lld%lld", &n, &k, &x);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) d[i - 2] = (a[i] == a[i - 1]) ? 0 : (a[i] - a[i - 1] - 1) / x;
	d[n - 1] = k + 1, std::sort(d, d + n);

	// for (int i = 0; i < n; i++) printf("%lld ", d[i]); puts("");
	for (int i = 0; i < n; i++) {
		if (k < d[i]) {printf("%d\n", n - i); break;}
		else k -= d[i];
	}
}