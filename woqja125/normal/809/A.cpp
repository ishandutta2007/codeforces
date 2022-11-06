#include<stdio.h>
#include<algorithm>
int a[300001];
const int MOD = 1000000007;
int bp[300001];
int main() {
	long long ans = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", a + i);
	std::sort(a + 1, a + n + 1);
	bp[0] = 1;
	for (int i = 1; i <= n; i++) bp[i] = 2ll * bp[i - 1] % MOD;
	for (int i = 1; i <= n; i++) {
		ans = (ans + 1ll * bp[i - 1] * a[i] + 1ll * bp[n - i] * (MOD - a[i])) % MOD;
	}
	printf("%lld", ans);
	return 0;
}