#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 200005
using namespace std;
int n, m, x, a[maxn];
int b[maxn];
int t[maxn];
int f[maxn], g[maxn];
int l[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
		t[b[i]]++; 
	}
	for (int i = 1; i < maxn; i++) t[i] += t[i - 1]; 
	sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
	a[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		l[i] = (a[i - 1] == a[i] - 1 ? l[i - 1] : i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		g[i] = max(g[i - 1], g[i]);
		for (int j = 1; j <= m; j++)
		{
			if(b[j] > a[i]) continue;
			int tmp = a[i] - b[j];
			if(i - tmp >= 1) f[i] = max(f[i], g[l[i - tmp] - 1] + t[a[i]] - t[b[j] - 1]);
		}
		g[i] = max(g[i], f[i]);
		f[i] = max(f[i], g[l[i] - 1] + t[a[i]] - t[a[l[i]] - 1]);
		for (int j = 1; j <= m; j++)
		{
			if(b[j] < a[i]) continue;
			int tmp = b[j] - a[i];
			if(i + tmp <= n) g[i + tmp] = max(g[i + tmp], f[i] + t[b[j]] - t[a[i]]);
		}
		ans = max(ans, f[i]);
		ans = max(ans, g[i]);
	}
//	for (int i = 1; i <= n; i++) printf("%d ", f[i]);
//	printf("\n");
//	for (int i = 1; i <= 10; i++) printf("%d ", g[i]);
//	printf("\n");
	printf("%d", ans);
	return 0;
}