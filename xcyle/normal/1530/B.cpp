#include <iostream>
#include <cstdio>
#define maxn 1005
using namespace std;
int t, h, w;
int a[maxn][maxn];
void solve()
{
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h + 5; i++)
	{
		for (int j = 1; j <= w + 5; j++)
		{
			a[i][j] = 0;
		}
	}
	if(h % 2 == 1 || w % 2 == 1)
	{
		for (int i = 1; i <= w; i++)
		{
			if(i & 1) a[1][i] = 1;
			else a[1][i] = 0;
		}
	}
	else
	{
		for (int i = 1; i <= w; i++)
		{
			if(i & 1) a[1][i] = 0;
			else a[1][i] = 1;
		}
	}
	for (int i = 2; i <= h; i++)
	{
		if(a[i - 1][1] || a[i - 1][2]) a[i][1] = 0;
		else a[i][1] = 1;
		if(a[i - 1][w] || a[i - 1][w - 1]) a[i][w] = 0;
		else a[i][w] = 1;
	}
	for (int j = 2; j < w; j++)
	{
	if(a[h][j - 1] || a[h][j + 1] || a[h - 1][j - 1] || a[h - 1][j + 1]) a[h][j] = 0;
	else a[h][j] = 1;
	}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
}
int main()
{
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}