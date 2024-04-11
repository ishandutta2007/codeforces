#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, ex, ey;
char s[1020][1020];
int d[1020][1020];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			if (s[i][j] == 'E')
			{
				ex = i;
				ey = j;
			}
		}
	}
	memset(d, -1, sizeof d);
	d[ex][ey] = 0;
	q.push(make_pair(ex, ey));
	while (q.size() > 0)
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];
			if (in(nx, ny) && s[nx][ny] != 'T')
			{
				if (d[nx][ny] == -1)
				{
					d[nx][ny] = d[u.first][u.second] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (isdigit(s[i][j]) && d[i][j] != -1 && d[i][j] <= d[sx][sy])
			{
				z += s[i][j] - '0';
			}
		}
	}
	cout << z << endl;
	return 0;
}