#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 2020;
const int oo = 2020202020;
int n, m, x;
int a[MAXN], b[MAXN];
int fa[MAXN], fb[MAXN];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	scanf("%d", &x);
	a[0] = b[0] = 0;
	for(int i = 2; i <= n; i++)
		a[i] += a[i - 1];
	for(int i = 2; i <= m; i++)
		b[i] += b[i - 1];
	for(int i = 1; i <= n; i++)
	{
		fa[i] = oo;
		for(int j = 1; j + i - 1 <= n; j++)
			fa[i] = min(fa[i], a[j + i - 1] - a[j - 1]);
	}
	for(int i = 1; i <= m; i++)
	{
		fb[i] = oo;
		for(int j = 1; j + i - 1 <= m; j++)
			fb[i] = min(fb[i], b[j + i - 1] - b[j - 1]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if((long long)fa[i] * fb[j] <= x)
				ans = max(ans, i * j);
	printf("%d\n", ans);
	return 0;
}