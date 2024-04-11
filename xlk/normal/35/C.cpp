#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y;
int d[2020][2020];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int q[8000020], b, f;
bool in(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	memset(d, -1, sizeof d);
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		d[x][y] = 0;
		q[b++] = x;
		q[b++] = y;
	}
	while (f < b)
	{
		x = q[f++];
		y = q[f++];
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny))
			{
				if (d[nx][ny] == -1)
				{
					d[nx][ny] = d[x][y] + 1;
					q[b++] = nx;
					q[b++] = ny;
				}
			}
		}
	}
	cout << x << ' ' << y << endl;
	return 0;
}