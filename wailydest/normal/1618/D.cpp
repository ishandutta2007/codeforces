#include <cstdio>
#include <algorithm>

const int N = 100;
int t, n, k, a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		std::sort(a, a + n);
		int res = 0;
		for (int i = 0; i < n - 2 * k; ++i) res += a[i];
		for (int i = n - 2 * k; i < n;) {
			int amt = 0;
			do {
				++i;
				++amt;
			} while (i < n && a[i] == a[i - 1]);
			if (amt > k) res += amt - k;
		}
		printf("%d\n", res);
	}
	return 0;
}