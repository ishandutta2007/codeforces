#include <iostream>
#include <cstdio>
#include <utility>
#include <climits>
#include <cstring>
using namespace std;

const int MaxN = 100;
const int MaxM = 100;
const int MaxL = 1000;

const int NLetter = 26;

int main()
{
	int n, m, qt;
	static char a[1 + MaxN + 1][1 + MaxM + 1];
	static char path[MaxL + 1];
	static int jx[NLetter], jy[NLetter];

	cin >> n >> m >> qt;
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);

	int sx, sy;
	int ex, ey;

	cin >> sx >> sy >> path >> ex >> ey;
	
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			if ('a' <= a[x][y] && a[x][y] <= 'z')
				jx[a[x][y] - 'a'] = x, jy[a[x][y] - 'a'] = y;

	int path_n = strlen(path);

	for (int i = 0; i <= path_n; i++)
	{
		int tx, ty;
		if (i < path_n)
			tx = jx[path[i] - 'a'], ty = jy[path[i] - 'a'];
		else
			tx = ex, ty = ey;
		while (sx != tx || sy != ty)
		{
			int t = '0' <= a[sx][sy] && a[sx][sy] <= '9' ? a[sx][sy] - '0' : 1;
			if (t > qt)
			{
				printf("%d %d\n", sx, sy);
				return 0;
			}
			if (sx < tx)
				sx++;
			else if (sx > tx)
				sx--;
			if (sy < ty)
				sy++;
			else if (sy > ty)
				sy--;
			qt -= t;
		}
	}

	printf("%d %d\n", sx, sy);
	
	return 0;
}