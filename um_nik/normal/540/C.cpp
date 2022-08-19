#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 510;
int n, m;
char t[N][N];
int X, Y;
int XX, YY;
bool used[N][N];
const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};

bool checkPos(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return t[x][y] == '.';
}

void dfs(int x, int y)
{
	used[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + DX[i], ny = y + DY[i];
		if (!checkPos(nx, ny)) continue;
		if (used[nx][ny]) continue;
		dfs(nx, ny);
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf(" %s ", t[i]);
	scanf("%d%d%d%d", &X, &Y, &XX, &YY);
	X--;Y--;XX--;YY--;
	t[X][Y] = '.';

	if (X == XX && Y == YY)
	{
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int x = X + DX[i], y = Y + DY[i];
			if (checkPos(x, y)) cnt++;
		}
		if (cnt >= 1)
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}

	dfs(X, Y);

	bool ok = false;
	for (int i = 0; i < 4; i++)
	{
		int x = XX + DX[i], y = YY + DY[i];
		if (!checkPos(x, y)) continue;
		if (used[x][y]) ok = true;
	}
	if (!ok)
	{
		printf("NO\n");	
		return 0;
	}
	if (t[XX][YY] == 'X')
	{
		printf("YES\n");
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = XX + DX[i], y = YY + DY[i];
		if (checkPos(x, y)) cnt++;
	}
	if (cnt >= 2)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}