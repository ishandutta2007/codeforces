#include <iostream>
#include <cstdio>
#define maxn 105
using namespace std;
const int INF = 0x3f3f3f3f;
int n, a[maxn];
int f[maxn][maxn][2];
int main()
{
	scanf("%d", &n);
	int last = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] != 0)
		{
			a[i] &= 1;
			if(i == 1)
			{
				f[1][0][0] = f[1][0][1] = f[1][1][0] = f[1][1][1] = INF;
				f[1][a[i]][a[i]] = 0;
				continue;
			}
			for (int j = 0; j <= i; j++)
			{
				f[i][j][0] = f[i][j][1] = INF;
				for (int k = 0; k <= 1; k++)
				{
					if(j - a[i] >= 0 && j - a[i] <= i - 1) f[i][j][a[i]] = min(f[i][j][a[i]], f[i - 1][j - a[i]][k] + (a[i] != k ? 1 : 0));
				}
			}
		}
		else
		{
			if(i == 1)
			{
				f[1][0][1] = f[1][1][0] = INF;
				f[1][0][0] = f[1][1][1] = 0;
				continue;
			}
			for (int j = 0; j <= i; j++)
			{
				f[i][j][0] = f[i][j][1] = INF;
				for (int last = 0; last <= 1; last++)
				{
					for (int now = 0; now <= 1; now++)
					{
						if(j - now >= 0 && j - now <= i - 1) f[i][j][now] = min(f[i][j][now], f[i - 1][j - now][last] + (now != last ? 1 : 0));
					}
				}
			}
		}
		for (int j = 0; j <= i; j++)
		{
			for (int now = 0; now <= 1; now++)
			{
//				printf("%d %d %d %d\n", i, j, now, f[i][j][now]);
			}
		}
	}
	printf("%d", min(f[n][(n + 1) / 2][0], f[n][(n + 1) / 2][1]));
	return 0;
}