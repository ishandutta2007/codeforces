#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 200000;
int t, n, x, a[N];
bool u[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &x);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		std::sort(a, a + n);
		memset(u, 0, n);
		int ans = 0;
		for (int i = n - 1, j = n - 1; i >= 0; --i) if (!u[i]) {
			while (j >= 0 && (long long)a[j] * x > a[i]) --j;
			if (j >= 0 && (long long)a[j] * x == a[i]) {
				u[j] = 1;
				--j;
			} else ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}