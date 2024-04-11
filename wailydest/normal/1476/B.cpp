#include <cstdio>

const int N = 100;
int t, n, a[N], k;

bool test(long long v) 
{
	long long s = a[0] + v;
	for (int i = 1; i < n; ++i) {
		if ((long long)a[i] * 100 > k * s) return false;
		s += a[i];
	}
	return true;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		long long l = 0, r = 10000000000000000, ans;
		while (l <= r) {
			long long m = (l + r) >> 1;
			if (test(m)) {
				ans = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}