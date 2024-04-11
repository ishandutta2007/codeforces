#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5050;
int n, b, c[MAXN], d[MAXN], fa[MAXN], sum[MAXN], f[MAXN][MAXN], g[MAXN][MAXN];
int buff[MAXN], bufg[MAXN];
int main()
{
	memset(f, 63, sizeof(f));
	memset(g, 63, sizeof(g));
	scanf("%d%d", &n, &b);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &c[i], &d[i]);
		if(i > 1)
			scanf("%d", &fa[i]);
		sum[i] = 1;
		f[i][1] = c[i] - d[i];
		g[i][0] = 0;
		g[i][1] = c[i];
		if(f[i][1] > b && g[i][1] > b)
			sum[i] = 0;
	}
	for(int i = n; i >= 2; i--)
	{
		memcpy(buff, f[fa[i]], sizeof(buff));
		memcpy(bufg, g[fa[i]], sizeof(bufg));
		for(int j = 0; j <= sum[i]; j++)
			for(int k = 0; k <= sum[fa[i]]; k++)
			{
				f[fa[i]][j + k] = min(f[fa[i]][j + k], min(f[i][j], g[i][j]) + buff[k]);
				g[fa[i]][j + k] = min(g[fa[i]][j + k], g[i][j] + bufg[k]);
			}
		sum[fa[i]] += sum[i];
		while(f[fa[i]][sum[fa[i]]] > b && g[fa[i]][sum[fa[i]]] > b)
			sum[fa[i]]--;
	}
	printf("%d\n", sum[1]);
	return 0;
}