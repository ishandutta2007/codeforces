#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, a[N], d[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int ans = 0;
		for (int i = 0; i < n;) {
			int res = 0;
			do {
				++i;
				++res;
			} while (i < n && a[i] == a[i - 1]);
			for (int j = i; j < n;) {
				++res;
				j = std::lower_bound(a + j, a + n, a[j] + a[j] - a[i - 1]) - a;
			}
			ans = std::max(ans, res);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}