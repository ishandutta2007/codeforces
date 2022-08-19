#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 110;
const int Z = 53;
int n;
char t[N][N];
bool a[N][N];
bool b[N][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %s ", t[i]);

	for (int x = -(n - 1); x < n; x++)
		for (int y = -(n - 1); y < n; y++)
			a[Z + x][Z + y] = 1;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
		{
			if (t[x][y] != 'o') continue;
			for (int xx = 0; xx < n; xx++)
				for (int yy = 0; yy < n; yy++)
				{
					if (t[xx][yy] != '.') continue;
					int dx = xx - x;
					int dy = yy - y;
					a[Z + dx][Z + dy] = 0;
				}
		}
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
		{
			if (t[x][y] != 'o') continue;
			for (int xx = 0; xx < n; xx++)
				for (int yy = 0; yy < n; yy++)
				{
					int dx = xx - x;
					int dy = yy - y;
					if (a[Z + dx][Z + dy])
						b[xx][yy] = 1;
				}
		}
	bool ok = true;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			if (t[x][y] == 'x' && !b[x][y])
				ok = false;
	if (!ok)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int x = -(n - 1); x < n; x++)
	{
		for (int y = -(n - 1); y < n; y++)
		{
			if (x == 0 && y == 0)
				printf("o");
			else if (a[Z + x][Z + y])
				printf("x");
			else
				printf(".");
		}
		printf("\n");
	}

	return 0;
}