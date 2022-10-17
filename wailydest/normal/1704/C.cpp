#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, m, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) scanf("%d", a + i);
		std::sort(a, a + m);
		int fi = a[0] - a[m - 1] + n - 1;
		for (int i = m - 1; i > 0; --i) a[i] = a[i] - a[i - 1] - 1;
		a[0] = fi;
		std::sort(a, a + m);
		int ans = 0;
		for (int i = m - 1; i >= 0 && a[i] - 4 * (m - i - 1) > 0; --i) {
			int k = a[i] - 4 * (m - i - 1);
			if (k == 1) ++ans;
			else ans += k - 1;
		}
		printf("%d\n", n - ans);
	}
	return 0;
}