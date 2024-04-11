#include <iostream>
#include <cstdio>
#define maxn 205
#define ll long long
using namespace std;
const int mo = 1e9 + 7;
int n, f[maxn][maxn * maxn], sum[maxn][maxn * maxn];
int b[maxn], c[maxn], q, xx, ans[200005];
int M = 100000;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9') 
	{
		w |= ch == '-';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return w ? -x : x;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i < n; i++) scanf("%d", &b[i]);
	f[0][0] = 1;
	int low = n * 100, upp = -n * 100; 
	for (int i = 0; i <= n * 100; i++) sum[0][i] = 1;
	int tppp = 1;
	for (int i = 1; i <= n; i++) tppp = (ll)tppp * (c[i] + 1) % mo;
	for (int x = -M; x <= M; x++)
	{
		int flag1 = 0, flag2 = 1;
		int tmp = 0;
		int tt = 0;
		for (int i = 1; i <= n; i++)
		{
			tt += b[i - 1] * (i - 1);
			tmp += b[i - 1];
			int t = i * x - tt + i * tmp;
			if(i * 100 < t) flag1 = 1;
			if(t >= 0) flag2 = 0;
		}
		if(flag1) continue;
		if(flag2)
		{
			ans[x + M] = tppp;
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			int t = i * x;
			for (int j = 1; j < i; j++) t +=  b[j] * (i - j);
	//		printf("%d ", t);
			for (register int j = 0; j < t; j++) sum[i][j] = 0;
			for (register int j = max(0, t); j <= n * 100; j++)
			{
				f[i][j] = sum[i - 1][j];
//				printf("%d %d %d %d ", x, i, j, f[i][j]);
				if(c[i] < j) f[i][j] = (f[i][j] - sum[i - 1][j - c[i] - 1] + mo) % mo;
				sum[i][j] = (sum[i][j - 1] + f[i][j]) % mo;
				if(i == n) ans[M + x] = (ans[M + x] + f[i][j]) % mo;
//				printf("%d\n", f[i][j]);
			}
		}
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		xx = read();
		printf("%d\n", ans[xx + M]);
	}
	return 0;
}