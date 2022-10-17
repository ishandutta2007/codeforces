#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, a[N], add[N];

bool test(int x) 
{
	add[n - 2] = 0;
	add[n - 1] = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] + add[i] < x) return 0;
		if (i >= 2) {
			add[i - 2] = 0;
			if (a[i] + add[i] > x) {
				int k = std::min(a[i], a[i] + add[i] - x) / 3;
				add[i - 2] = k * 2;
				add[i - 1] += k;
			}
		}
	}
	return 1;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int l = 1, r = 1000000000;
		while (l <= r) {
			int m = l + r >> 1;
			if (test(m)) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", l - 1);
	}
	return 0;
}