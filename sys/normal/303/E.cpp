#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 85;
int n, ct, l[Maxn], r[Maxn], a[2 * Maxn];
double f[Maxn][Maxn], g[Maxn][Maxn], ans[Maxn][Maxn];
double occur(int x, int lt, int rt)
{
	lt = max(lt, l[x]), rt = min(rt, r[x]);
	return max(0.0, (a[rt] - a[lt]) / (double) (a[r[x]] - a[l[x]]));
}
void trans(int x, int pos)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; i + j < n; j++)
			g[i][j] = f[i][j], f[i][j] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; i + j < n; j++)
			if (abs(g[i][j]) > 1e-10)
			{
				f[i][j + 1] += g[i][j] * occur(x, pos, pos + 1);
				f[i + 1][j] += g[i][j] * occur(x, 1, pos);
				f[i][j] += g[i][j] * occur(x, pos + 1, ct);
			}
}
void work(int lt, int rt, int pos)
{
	if (lt == rt)
	{
		if (pos < l[lt] || pos > r[lt]) return ;
		for (int i = 0; i < n; i++)
			for (int j = 0; i + j < n; j++)
				if (abs(f[i][j]) > 1e-10)
				{
					double val = f[i][j] * occur(lt, pos, pos + 1) / (j + 1.0);
					ans[lt][i + 1] += val;
					ans[lt][i + j + 2] -= val;
				}
	}
	else
	{
		int mid = (lt + rt) >> 1;
		double tmp[Maxn][Maxn];
		for (int i = 0; i < n; i++)
			for (int j = 0; i + j < n; j++)
				tmp[i][j] = f[i][j];
		for (int i = mid + 1; i <= rt; i++)
			trans(i, pos);
		work(lt, mid, pos);
		for (int i = 0; i < n; i++)
			for (int j = 0; i + j < n; j++)
				f[i][j] = tmp[i][j];
		for (int i = lt; i <= mid; i++)
			trans(i, pos);
		work(mid + 1, rt, pos);
	}
}
int main()
{
    scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &l[i], &r[i]), a[++ct] = l[i], a[++ct] = r[i];
	sort(a + 1, a + 1 + ct);
	ct = unique(a + 1, a + 1 + ct) - a - 1;
	for (int i = 1; i <= n; i++)
	{
		l[i] = lower_bound(a + 1, a + 1 + ct, l[i]) - a;
		r[i] = lower_bound(a + 1, a + 1 + ct, r[i]) - a;
	}
	for (int i = 1; i < ct; i++)
	{
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		work(1, n, i);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < n; j++)
			ans[i][j + 1] += ans[i][j];
		for (int j = 1; j <= n; j++)
			printf("%.10lf ", ans[i][j]);
		puts("");
	}
	return 0;
}