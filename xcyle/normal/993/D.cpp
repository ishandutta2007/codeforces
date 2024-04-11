#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 55
using namespace std;
const long long INF = 9e15;
int n, a[maxn], b[maxn], tmp[maxn];
long long f[maxn][maxn][maxn * 100];
int t[maxn][maxn];
bool cmp(int x, int y)
{
	return x > y;
}
long long Min(long long x, long long y)
{
	return  x > y ? y : x;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) tmp[i] = a[i];
	sort(tmp + 1, tmp + n + 1);
	int len = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(tmp + 1, tmp + len + 1, a[i]) - tmp;
		t[a[i]][++t[a[i]][0]] = b[i];
	}
	for (int i = 1; i <= len; i++)
	{
		sort(t[i] + 1, t[i] + t[i][0] + 1, cmp);
//		printf("%d %d\n", tmp[i], t[i][0]);
//		for (int j = 1; j <= t[i][0]; j++) printf("%d ", t[i][j]);
//		printf("\n");
	}
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			for (register int k = 0; k < maxn * 100; k++)
			{
				f[i][j][k] = INF;
			}
		}
	}
	f[len + 1][0][0] = 0;
	int cnt = 0;
	for (int i = len + 1; i >= 0; i--)
	{
		cnt += t[i][0];
		for (int j = 0; j <= cnt; j++)
		{
			for (int k = 0; k <= cnt * 100; k++)
			{
//				if(k < 60 && f[i][j][k] != INF) printf("%d %d %d %lld\n", i, j, k, f[i][j][k]);
				if(!i) continue;
				int s = 0;
				for (register int c = 1; c <= max(t[i][0] - j, 0) - 1; c++) s += t[i][c];
				for (register int c = max(0, t[i][0] - j); c <= t[i][0]; c++)
				{
					if(c) s += t[i][c];
					f[i - 1][j - (t[i][0] - c) + c][k + s] = Min(f[i - 1][j - (t[i][0] - c) + c][k + s], f[i][j][k] + (long long)c * tmp[i]);
				}
			}
		}
	}
	long long ans = INF;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 1; j <= n * 100; j++)
		{
			ans = min(ans, (long long)(f[0][i][j] * 1000 + j - 1) / j);
		}
	}
	printf("%lld", ans);
	return 0;
}