#include <cstdio>

const int N = 200000;
int t, n, a[N], b[N];

bool test(int k) 
{
	if (!k) return 1;
	int l = 0;
	for (int i = 0; i < n; ++i) {
		if (l >= k - 1 - a[i] && l <= b[i]) ++l;
		if (l == k) return 1;
	}
	return 0;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d%d", a + i, b + i);
		int l = 0, r = n;
		while (l <= r) {
			int m = l + r >> 1;
			if (test(m)) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", l - 1);
	}
	return 0;
}