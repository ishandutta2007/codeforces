#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long s64;

const int MaxN = 1000;
const int MaxM = 1000;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

int main()
{
	int n, m;
	static int a[MaxN + 1][MaxM + 1];

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	static s64 f[2][2][MaxN + 1][MaxM + 1];

	for (int tx = 0; tx <= 1; tx++)
		for (int ty = 0; ty <= 1; ty++)
		{
			int dx = tx == 0 ? 1 : -1;
			int dy = ty == 0 ? 1 : -1;
			int sx = tx == 0 ? 1 : n;
			int ex = tx == 0 ? n + 1 : 0;
			int sy = ty == 0 ? 1 : m;
			int ey = ty == 0 ? m + 1 : 0;

			for (int i = sx; i != ex; i += dx)
				for (int j = sy; j != ey; j += dy)
				{
					f[tx][ty][i][j] = 0;
					if (i != sx)
						relax(f[tx][ty][i][j], f[tx][ty][i - dx][j]);
					if (j != sy)
						relax(f[tx][ty][i][j], f[tx][ty][i][j - dy]);
					f[tx][ty][i][j] += a[i][j];
				}
		}

	s64 res = 0;
	for (int x = 2; x <= n - 1; x++)
		for (int y = 2; y <= m - 1; y++)
		{
			relax(res, f[0][0][x][y - 1] + f[1][1][x][y + 1] + f[1][0][x + 1][y] + f[0][1][x - 1][y]);
			relax(res, f[0][0][x - 1][y] + f[1][1][x + 1][y] + f[1][0][x][y - 1] + f[0][1][x][y + 1]);
		}
	cout << res << endl;

	return 0;
}