#include <stdio.h>
#include <string.h>
#define MAXN 101010
int n, q, a[MAXN], b[MAXN];
double f[MAXN][105], ans = 0.0;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(!a[i])
			ans += 1.0;
	}
	memcpy(b, a, (n + 1) * sizeof(int));
	scanf("%d", &q);
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++)
		f[i][a[i]] = 1.0;
	for(int i = 1; i <= q; i++)
	{
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		ans -= f[u][0];
		for(int k1 = 1; k1 <= k; a[u]--, k1++)
			for(int j = 0; j <= a[u] && j <= b[u]; j++)
				f[u][j] = f[u][j] * (1 - (double)j / a[u]) + f[u][j + 1] * ((double)(j + 1) / a[u]);
		a[v] += k;
		printf("%.12f\n", ans += f[u][0]);
	}
	return 0;
}