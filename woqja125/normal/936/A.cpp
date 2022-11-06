#include<cstdio>
int main() {
	long long k, d, t;
	scanf("%lld%lld%lld", &k, &d, &t);
	if (d <= k) {
		if (k%d == 0) {
			printf("%lld\n", t);
			return 0;
		}
		d = (k / d + 1) * d;
	}
	long long ans = 0;
	long long cycle = k + d;
	ans += (t * 2) / cycle * d * 2;
	t = t * 2 % cycle;

	if (t <= k * 2) {
		ans += t;
	}
	else {
		ans += k * 2;
		t -= k * 2;
		ans += t * 2;
	}
	if (ans % 2 == 0) printf("%lld\n", ans / 2);
	else printf("%lld.5\n", ans / 2);
	return 0;
}