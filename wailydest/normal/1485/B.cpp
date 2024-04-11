#include <cstdio>

const int N = 100000;
int n, q, k, a[N], s[N], l, r;

int main() 
{
	scanf("%d%d%d", &n, &q, &k);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 1; i < n - 1; ++i) s[i] = s[i - 1] + a[i + 1] - a[i - 1] - 2;
	while (q--) {
		scanf("%d%d", &l, &r);
		if (r - l) printf("%d\n", s[r - 2] - s[l - 1] + a[l] - 2 + k - a[r - 2] - 1);
		else printf("%d\n", k - 1);
	}
	return 0;
}