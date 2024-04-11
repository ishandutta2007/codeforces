#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 505;
int n, l, k, d[N][N], p[N], a[N];

int main() 
{
	scanf("%d%d%d", &n, &l, &k);
	for (int i = 0; i < n; ++i) scanf("%d", p + i);
	p[n] = l;
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	memset(*d, 0x3f, N * N << 2);
	d[0][0] = 0;
	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < i; ++j) 
			for (int k = i - j - 1; k < i; ++k) 
				d[i][k] = std::min(d[i][k], d[j][k - (i - j - 1)] + (p[i] - p[j]) * a[j]);
	int ans = ~(1 << 31);
	for (int i = 0; i <= k; ++i) ans = std::min(ans, d[n][i]);
	printf("%d\n", ans);
	return 0;
}