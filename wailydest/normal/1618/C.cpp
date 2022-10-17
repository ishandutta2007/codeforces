#include <cstdio>
#include <algorithm>

const int N = 100;
int t, n;
long long a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long g = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", a + i);
			if (i & 1 ^ 1) g = std::__gcd(g, a[i]);
		}
		bool ok = 1;
		for (int i = 1; i < n; i += 2) if (!(a[i] % g)) ok = 0;
		if (ok) printf("%lld\n", g);
		else {
			ok = 1;
			g = 0;
			for (int i = 1; i < n; i += 2) g = std::__gcd(g, a[i]);
			for (int i = 0; i < n; i += 2) if (!(a[i] % g)) ok = 0;
			if (ok) printf("%lld\n", g);
			else printf("0\n");
		}
	}
	return 0;
}