#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 3005
using namespace std;
const long long INF = 9e15;
int n;
long long a[maxn], b[maxn];
long long f[maxn][maxn][2];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%lld", &a[i]);
		a[i] += n - i; 
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int len = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
	{
		int loc = lower_bound(b + 1, b + len + 1, a[i]) - b;
//		printf("%d\n", loc);
		long long ans = INF;
		if(i == 1) ans = 0;
		for (int j = 1; j < loc; j++)
		{
			ans = min(ans, f[i - 1][j][0] * b[j] + f[i - 1][j][1]);
			if(f[i - 1][j][0] < 0) 
			{
				f[i][j][0] = f[i - 1][j][0] - 1;
				f[i][j][1] = f[i - 1][j][1] + a[i];
			}
			else
			
			{
				f[i][j][0] = -1;
				f[i][j][1] = ans + a[i]; 
			}
//			printf("%d %d %lld %lld\n", i, j, f[i][j][0], f[i][j][1]);
		}
		for (int j = loc; j <= len; j++)
		{
			ans = min(ans, f[i - 1][j][0] * b[j] + f[i - 1][j][1]);
			if(f[i - 1][j][0] < 0) 
			{
				f[i][j][0] = f[i - 1][j][0] + 1;
				f[i][j][1] = f[i - 1][j][1] - a[i];
			}
			else
			{
				f[i][j][0] = 1;
				f[i][j][1] = ans - a[i]; 
			}
//			printf("%d %d %lld %lld\n", i, j, f[i][j][0], f[i][j][1]);
		}
	}
	long long res = INF;
	for (int i = 1; i <= len; i++) 
	{
//		printf("%d ", b[i]);
		res = min(res, f[n][i][0] * (b[i]) + f[n][i][1]);
//		res = min(res, f[n][i][0] * (b[i + 1]) + f[n][i][1]);
	}
	printf("%lld", res);
	return 0;
}