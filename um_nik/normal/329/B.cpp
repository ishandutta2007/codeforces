#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int INF = (int)1e9;
const int N = 1010;
const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};
int n, m;
char s[N][N];
int dist[N][N];
int q[N * N][2];
int topQ;

bool checkCell(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return s[x][y] != 'T';
}

void BFS(int x, int y)
{
	q[topQ][0] = x;
	q[topQ][1] = y;
	topQ++;
	dist[x][y] = 0;
	for (int k = 0; k < topQ; k++)
	{
		x = q[k][0];
		y = q[k][1];
		for (int i = 0; i < 4; i++)
		{
			int xx = x + DX[i], yy = y + DY[i];
			if (!checkCell(xx, yy)) continue;
			if (dist[xx][yy] <= dist[x][y] + 1) continue;
			dist[xx][yy] = dist[x][y] + 1;
			q[topQ][0] = xx;
			q[topQ][1] = yy;
			topQ++;
		}
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf(" %s ", s[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j] = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'E')
				BFS(i, j);
	int D = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'S')
				D = dist[i][j];
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] < '0' || s[i][j] > '9') continue;
			if (dist[i][j] <= D)
				ans += (int)(s[i][j] - '0');
		}
	printf("%d\n", ans);

	return 0;
}