#include<cstdio>
long long c[31];
int main() {
	int n, l;
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)scanf("%lld", c + i);
	for (int i = 1; i <= 30; i++) {
		if (c[i] == 0 || c[i] > c[i - 1] * 2ll) c[i] = c[i - 1] * 2ll;
	}
	long long ans = 0;
	for (int i = 0; i <= 30; i++) {
		if ((l >> i) & 1) {
			ans += c[i];
		}
		else if (ans > c[i]) ans = c[i];
	}
	printf("%lld\n", ans);
	return 0;
}