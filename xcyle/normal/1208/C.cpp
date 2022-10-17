#include <iostream>
#include <cstdio>
#define maxn 1005
using namespace std;
int a[4][4] = {8, 9, 1, 13,
3, 12, 7, 5,
0, 2, 4, 11,
6, 10, 15, 14}, n;
int ans[maxn][maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n / 4; i++)
	{
		for (int j = 0; j < n / 4; j++)
		{
			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					ans[i * 4 + x][j * 4 + y] = a[x][y] + (i * (n / 4) + j) * 16; 
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}