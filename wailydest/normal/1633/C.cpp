#include <cstdio>

int t, dc, dm, k, w;
long long hc, hm, a;

long long di(long long a, long long b) {
	return (a - 1) / b + 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%d", &hc, &dc);
		scanf("%lld%d", &hm, &dm);
		scanf("%d%d%lld", &k, &w, &a);
		bool ok = 0;
		for (int i = 0; i <= k; ++i) if (di(hm, dc + (long long)i * w) <= di(hc + a * (k - i), dm)) ok = 1;
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}