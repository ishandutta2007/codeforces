#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, a[N], b[N], c[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", c + i);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		for (int i = 0; i < n; ++i) scanf("%d", b + i);
		long long ans = 0, pr = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i] == b[i]) {
				ans = std::max(ans, (long long)c[i] + 1);
				pr = 2;
			}
			else {
				if (pr) ans = std::max(ans, pr + c[i] + c[i - 1] - abs(a[i] - b[i]));
				ans = std::max(ans, (long long)c[i] + abs(a[i] - b[i]) + 1);
				if (pr) pr = pr + c[i - 1] - abs(a[i] - b[i]) + 1;
				pr = std::max(pr, (long long)abs(a[i] - b[i]) + 2);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}