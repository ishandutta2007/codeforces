#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = (int)1e9 + 10;
const int N = 1010;
const int V = N * N * 4;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};
int n, m;
int dist[N][N][4];
int q[V][3];
int topQ;
int sx, sy, tx, ty;
char t[N][N];
int a[N][N];

int getMask(char c)
{
	if (c == '*') return 0;
	if (c == '+') return 15;
	if (c == '-') return 10;
	if (c == '|') return 5;
	if (c == '^') return 1;
	if (c == '>') return 2;
	if (c == 'v') return 4;
	if (c == '<') return 8;
	if (c == 'L') return 7;
	if (c == 'D') return 11;
	if (c == 'R') return 13;
	if (c == 'U') return 14;
	throw;
}

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf(" %s ", t[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = getMask(t[i][j]);
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	sx--;sy--;tx--;ty--;
	return;
}

void addQ(int x, int y, int tm)
{
	q[topQ][0] = x;
	q[topQ][1] = y;
	q[topQ][2] = tm;
	topQ++;
	return;
}
void tryRelax(int x, int y, int tm, int nd)
{
	if (dist[x][y][tm] <= nd) return;
	dist[x][y][tm] = nd;
	addQ(x, y, tm);
	return;
}

bool checkCell(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool haveDoor(int x, int y, int tm, int dir)
{
	dir = (dir + 4 - tm) % 4;
	return (a[x][y] >> dir) & 1;
}

bool canGo(int x, int y, int tm, int d)
{
	int nx = x + DX[d], ny = y + DY[d];
	if (!checkCell(nx, ny)) return false;
	return haveDoor(x, y, tm, d) && haveDoor(nx, ny, tm, d ^ 2);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 4; k++)
				dist[i][j][k] = INF;
	tryRelax(sx, sy, 0, 0);
	for (int k = 0; k < topQ; k++)
	{
		int x = q[k][0], y = q[k][1], tm = q[k][2];
		tryRelax(x, y, (tm + 1) % 4, dist[x][y][tm] + 1);
		for (int d = 0; d < 4; d++)
		{
			if (!canGo(x, y, tm, d)) continue;
			int nx = x + DX[d], ny = y + DY[d];
			tryRelax(nx, ny, tm, dist[x][y][tm] + 1);
		}
	}
	int ans = INF;
	for (int i = 0; i < 4; i++)
		ans = min(ans, dist[tx][ty][i]);
	if (ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}