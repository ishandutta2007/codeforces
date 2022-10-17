#include <cstdio>
#include <algorithm>

const int N = 2000;
int n, k;
std::pair<int, int> a[N * N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		scanf("%d", &a[i * n + j].first);
		a[i * n + j].second = i * n + j;
	}
	std::sort(a, a + n * n);
	int xl = 0, xr = 2 * n, yl = -n, yr = n;
	for (int i = n * n - 1; i >= 0; --i) {
		int x = a[i].second / n + a[i].second % n, y = a[i].second / n - a[i].second % n;
		if (x >= xl && x <= xr && y >= yl && y <= yr) {
			xl = std::max(xl, x - k);
			yl = std::max(yl, y - k);
			xr = std::min(xr, x + k);
			yr = std::min(yr, y + k);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) printf("%c", i + j >= xl && i + j <= xr && i - j >= yl && i - j <= yr ? 'M' : 'G');
		printf("\n");
	}
	return 0;
}