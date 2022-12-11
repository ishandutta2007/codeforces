#include <bits/stdc++.h>
using namespace std;

char dat[105][105];
tuple<int, int, int, int> vis[105][105][2][2];
int n, m;
int flipX, flipY;

bool canX(int x, int y)
{
	return n > 1 && dat[x - 1][y] != '*' && dat[x + 1][y] != '*';
}

bool canY(int x, int y)
{
	return m > 1 && dat[x][y - 1] != '*' && dat[x][y + 1] != '*';
}

pair<int, int> button(char ch)
{
	printf("%c\n", ch);
	fflush(stdout);
	int x, y;
	int ret = scanf("%d%d", &x, &y);
	if (ret != 2 || x == -1 || y == -1 || dat[x][y] == 'F') exit(0);

	return { x, y };
}

void testX(int x, int y)
{
	int nx, ny;
	tie(nx, ny) = button('U');

	if (nx < x || nx == 1)
	{
		flipX = 1;
	}
	else
	{
		flipX = -1;
	}

	if (nx != x) button('D');
}

void testY(int x, int y)
{
	int nx, ny;
	tie(nx, ny) = button('L');

	if (ny < y || ny == 1)
	{
		flipY = 1;
	}
	else
	{
		flipY = -1;
	}

	if (ny != y) button('R');
}

void movepos(int x, int y)
{
	if (x * flipX == 1) button('D');
	if (x * flipX == -1) button('U');
	if (y * flipY == 1) button('R');
	if (y * flipY == -1) button('L');
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", dat[i] + 1);

	queue<tuple<int, int, int, int>> que;
	vis[1][1][canX(1, 1)][canY(1, 1)] = make_tuple(-1, -1, -1, -1);
	que.emplace(1, 1, canX(1, 1), canY(1, 1));

	int cnt = 0;
	int x, y, X, Y;

	while (que.empty() == false)
	{
		tie(x, y, X, Y) = que.front(); que.pop();

		if (dat[x][y] == 'F') break;

		if (X)
		{
			for (int nx = x - 1; nx <= x + 1; nx++)
			{
				if (nx == x) continue;
				if (nx <= 0 || nx > n) continue;
				if (dat[nx][y] == '*') continue;
				int nY = Y || canY(nx, y);
				if (get<0>(vis[nx][y][X][nY]) == 0)
				{
					vis[nx][y][X][nY] = make_tuple(x, y, X, Y);
					que.emplace(nx, y, X, nY);
				}
			}
		}

		if (Y)
		{
			for (int ny = y - 1; ny <= y + 1; ny++)
			{
				if (ny == y) continue;
				if (ny <= 0 || ny > m) continue;
				if (dat[x][ny] == '*') continue;
				int nX = X || canX(x, ny);
				if (get<0>(vis[x][ny][nX][Y]) == 0)
				{
					vis[x][ny][nX][Y] = make_tuple(x, y, X, Y);
					que.emplace(x, ny, nX, Y);
				}
			}
		}
	}

	vector<pair<int, int>> path;

	while (x != -1)
	{
		path.emplace_back(x, y);
		tie(x, y, X, Y) = vis[x][y][X][Y];
	}

	reverse(path.begin(), path.end());

	for (int i = 1; i < path.size(); i++)
	{
		tie(x, y) = path[i - 1];
		if (flipX == 0 && canX(x, y)) testX(x, y);
		if (flipY == 0 && canY(x, y)) testY(x, y);

		movepos(path[i].first - x, path[i].second - y);
	}
}