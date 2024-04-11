#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAXN 1010
int n, m, k, a[MAXN][MAXN];
long long b[3][MAXN][MAXN];
long long ans;
int ax, ay;
long long up(int x, int y)
{
	return b[0][x][y + k - 1] - b[0][x][y - k] - b[1][x - 1][y + k - 1] - b[2][x - 1][y - k + 1] + b[1][x - k][y] + (x >= k + 1 ? b[2][x - k - 1][y + 1] : 0);
}
long long down(int x, int y)
{
	return b[1][x + k - 1][y] + b[2][x + k - 2][y + 1] - b[0][x - 1][y + k - 1] + b[0][x - 1][y - k] - b[2][x - 1][y + k] - b[1][x - 1][y - k];
}
long long left(int x, int y)
{
	return b[1][x + k - 1][y] - b[1][x - 1][y - k] - b[2][x - 1][y - k + 1] + (x >= k + 1 ? b[2][x - k - 1][y + 1] : 0);
}
long long right(int x, int y)
{
	return b[2][x + k - 1][y] - b[2][x - 1][y + k] - b[1][x - 1][y + k - 1] + (x >= k + 1 ? b[1][x - k - 1][y - 1] : 0);
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= n + 1; i++)
		for(int j = 1; j <= m + 1; j++)
		{
			b[0][i][j] = b[0][i - 1][j] + b[0][i][j - 1] - b[0][i - 1][j - 1] + a[i][j];//square
			b[1][i][j] = b[1][i - 1][j] + b[1][i - 1][j - 1] - (i >= 2 ? b[1][i - 2][j - 1] : 0) + a[i][j];//triangle1
			b[2][i][j] = b[2][i - 1][j] + b[2][i - 1][j + 1] - (i >= 2 ? b[2][i - 2][j + 1] : 0) + a[i][j];//triangle2
		}
	long long now = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			now += a[i][j] * max(0, k - abs(i - k) - abs(j - k));
	ans = now, ax = k, ay = k;
	for(int i = k; i <= n - k + 1; i += 2)
	{
		for(int j = k + 1; j <= m - k + 1; j++)
		{
			now = now - left(i, j - 1) + right(i, j);
			if(now > ans)
				ans = now, ax = i, ay = j;
		}
		if(i == n - k + 1)
			break;
		now = now - up(i, m - k + 1) + down(i + 1, m - k + 1);
		if(now > ans)
			ans = now, ax = i + 1, ay = m - k + 1;
		for(int j = m - k; j >= k; j--)
		{
			now = now - right(i + 1, j + 1) + left(i + 1, j);
			if(now > ans)
				ans = now, ax = i + 1, ay = j;
		}
		if(i == n - k)
			break;
		now = now - up(i + 1, k) + down(i + 2, k);
		if(now > ans)
			ans = now, ax = i + 2, ay = k;
	}
	printf("%d %d\n", ax, ay);
	return 0;
}