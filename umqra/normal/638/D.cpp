#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 111;
char s[N];
bool a[N][N][N];
int n, m, k;
int ans;

bool solve(int x, int y, int z)
{
	if (!a[x][y][z]) return false;
	if (a[x - 1][y][z] && a[x + 1][y][z]) return true;
	if (a[x][y - 1][z] && a[x][y + 1][z]) return true;
	if (a[x][y][z - 1] && a[x][y][z + 1]) return true;
	if (a[x - 1][y][z] && a[x][y + 1][z] && !a[x - 1][y + 1][z]) return true;
	if (a[x - 1][y][z] && a[x][y][z + 1] && !a[x - 1][y][z + 1]) return true;
	if (a[x][y - 1][z] && a[x + 1][y][z] && !a[x + 1][y - 1][z]) return true;
	if (a[x][y - 1][z] && a[x][y][z + 1] && !a[x][y - 1][z + 1]) return true;
	if (a[x][y][z - 1] && a[x + 1][y][z] && !a[x + 1][y][z - 1]) return true;
	if (a[x][y][z - 1] && a[x][y + 1][z] && !a[x][y + 1][z - 1]) return true;
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf(" %s ", s);
			for (int p = 0; p < k; p++)
				a[i][j][p + 1] = (s[p] == '1');
		}
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			for (int z = 1; z <= k; z++)
				ans += solve(x, y, z);
	printf("%d\n", ans);

	return 0;
}