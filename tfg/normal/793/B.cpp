#include <iostream>
#include <string>

int n, m;

std::string board[1001];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool visit[1001][1001][3][4];

void dfs(int x, int y, int turns, int dir)
{
	if(x < 0 || x >= n || y < 0 || y >= m)
		return;
	if(turns >= 3 || visit[x][y][turns][dir] || board[x][y] == '*')
		return;
	//std::cout << "on (" << x << ", " << y << ", " << turns << ", " << dir << ")\n";
	visit[x][y][turns][dir] = true;
	for(int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i], turns + (i != dir ? 1 : 0), i);
}

int main()
{
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
		std::cin >> board[i];
	int x[2], y[2];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(board[i][j] == 'S')
			{
				x[0] = i;
				y[0] = j;
			}
			else if(board[i][j] == 'T')
			{
				x[1] = i;
				y[1] = j;
			}
		}
	}
	for(int i = 0; i < 4; i++)
		dfs(x[0], y[0], 0, i);
	bool ans = false;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			ans = ans || visit[x[1]][y[1]][i][j];
		}
	}
	if(ans)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}