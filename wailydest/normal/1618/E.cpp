#include <cstdio>
#include <cstring>

const int N = 40000;
int t, n, a[N], c[N], res[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		memcpy(c, a, n << 2);
		int la = a[n - 1];
		for (int i = n - 1; i > 0; --i) a[i] -= a[i - 1];
		a[0] -= la;
		la = a[n - 1];
		bool ok = 1;
		for (int i = n - 1; i > 0; --i) {
			a[i] -= a[i - 1];
			if (a[i] % n) ok = 0;
			else a[i] /= -n;
		}
		a[0] -= la;
		if (a[0] % n) ok = 0;
		else a[0] /= -n;
		int s = 0;
		long long ss = 0;
		for (int i = 1; i < n; ++i) {
			s += a[i];
			ss += (long long)s * (n - i);
		}
		long long k = (long long)n * (n + 1) / 2;
		if ((c[n - 1] - ss) % k) ok = 0;
		else {
			res[0] = (c[n - 1] - ss) / k;
			if (res[0] <= 0) ok = 0;
			int sum = res[0];
			for (int i = 1; i < n; ++i) {
				res[i] = res[i - 1] + a[i];
				sum += res[i];
				if (res[i] <= 0 || sum > 1000000000) ok = 0;
			}
			for (int i = 0; i < n; ++i) if (c[i] - c[i ? i - 1 : n - 1] != sum - (long long)n * res[i]) ok = 0;
		}
		if (ok) {
			printf("YES\n");
			for (int i = 0; i < n; ++i) printf("%d ", res[i]);
			printf("\n");
		} else printf("NO\n");
	}
	return 0;
}