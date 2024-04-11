#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long s64;

const int MaxN = 1000;
const int MaxM = 1000;

int main()
{
	int n, m, l;
	static int a[MaxN + 1][MaxM + 1];

	static int f[MaxN + MaxM + 1][MaxM + 1];
	static int g[MaxN + MaxM + 1][MaxM + 1];
	static int sr[MaxN + 1][MaxM + 1];
	static int sc[MaxN + 1][MaxM + 1];

	cin >> n >> m >> l;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
		{
			scanf("%d", &a[x][y]);

			f[x + y][y] += a[x][y];
			g[x + m - y][y] += a[x][y];
		}
	for (int i = 1; i <= n + m; i++)
		for (int j = 1; j <= m; j++)
		{
			f[i][j] += f[i][j - 1];
			g[i][j] += g[i][j - 1];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			sr[i][j] = sr[i][j - 1] + a[i][j];
			sc[i][j] = sc[i - 1][j] + a[i][j];
		}

	static s64 sum[MaxN + 1][MaxM + 1];

	s64 resVal = -1;
	int resX, resY;

	for (int x = l; x <= n - l + 1; x++)
	{
		for (int y = l; y <= m - l + 1; y++)
		{
			if (y > l + 1)
			{
				sum[x][y] = 2 * sum[x][y - 1] - sum[x][y - 2];
				sum[x][y] += g[x + m - y - l + 1][y + l - 1] - g[x + m - y - l + 1][y - 1];
				sum[x][y] += f[x + y - 1 - l][y - 2] - f[x + y - 1 - l][y - 2 - l];
				sum[x][y] += f[x + y + l - 1][y + l - 2] - f[x + y + l - 1][y - 1];
				sum[x][y] += g[x + m - y + 1 + l][y - 2] - g[x + m - y + 1 + l][y - 1 - l];
				sum[x][y] -= (sc[x + l - 1][y - 1] - sc[x - l][y - 1]) * 2;
			}
			else if (x > l + 1)
			{
				sum[x][y] = 2 * sum[x - 1][y] - sum[x - 2][y];

				sum[x][y] += f[x + y + l - 1][y + l - 1] - f[x + y + l - 1][y - 1];
				sum[x][y] += g[x + m - y - 1 - l][y + l - 1] - g[x + m - y - 1 - l][y - 1];
				sum[x][y] += g[x + m - y + l - 1][y - 1] - g[x + m - y + l - 1][y - l];
				sum[x][y] += f[x + y - l - 1][y - 1] - f[x + y - l - 1][y - l];
				sum[x][y] -= (sr[x - 1][y + l - 1] - sr[x - 1][y - l]) * 2;
			}
			else
			{
				sum[x][y] = 0;
				for (int i = -l; i <= l; i++)
					for (int j = -l + abs(i); j <= l - abs(i); j++)
						sum[x][y] += (l - abs(i) - abs(j)) * a[x + i][y + j];
			}
			if (sum[x][y] > resVal)
				resVal = sum[x][y], resX = x, resY = y;
		}
	}
	cout << resX << " " << resY << endl;

	return 0;
}