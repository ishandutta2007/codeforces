#include <cstdio>
#include <algorithm>

const int N = 2000005;
int n, lb[N];
long long a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lld", a + i);
	lb[N - 1] = n;
	for (int i = N - 2, j = n; i >= 0; --i) {
		while (j && a[j - 1] == i) --j;
		lb[i] = j;
	}
	std::sort(a, a + n);
	long long ans = -1;
	for (int i = 1; ans == -1; ++i) if ((long long)i * i + i >= a[0]) {
		long long linc = std::max((long long)0, a[0] - (long long)i * i), rinc = i;
		long long delta = (long long)i * i - a[0];
		for (int j = i;; ++j) {
			long long need = (long long)j * j + j + 1 - delta;
			int p;
			if (need < 0) p = 0;
			else p = lb[std::min((long long)N - 1, need)];
			if (p) rinc = std::min(rinc, (long long)j * j + j - a[p - 1] - delta);
			if (p < n) linc = std::max(linc, (long long)(j + 1) * (j + 1) - a[p] - delta);
			else break;
		}
		if (linc <= rinc) ans = delta + linc;
	}
	printf("%lld\n", ans);
	return 0;
}