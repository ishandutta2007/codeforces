#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <cstring>
#include <vector>

typedef std::pair<int, int> ii;

const int ms = 220;

int n, m, qq;

std::string board[ms];

ii to[ms][ms];

int dx[10], dy[10];

int can[ms][ms];
int dist[ms][ms];

int degree[ms][ms];
int d[ms][ms];

int dfs(int i, int j, int num)
{
	if(dist[i][j])
		return num;
	dist[i][j] = 1;
	int ans = dfs(to[i][j].first, to[i][j].second, num | (1 << (board[i][j] - '0')));
	can[i][j] |= ans;
	return ans;
}

int main()
{
	std::cin >> n >> m >> qq;
	for(int i = 0; i < n; i++)
		std::cin >> board[i];
	for(int i = 0; i < 10; i++)
		std::cin >> dx[i] >> dy[i];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			to[i][j] = ii(i + dx[board[i][j] - '0'], j + dy[board[i][j] - '0']);
			if(to[i][j].first < 0 || to[i][j].first >= n || to[i][j].second < 0 || to[i][j].second >= m)
				to[i][j] = ii(i, j);
			degree[to[i][j].first][to[i][j].second]++;
			can[i][j] |= (1 << (board[i][j] - '0'));
		}
	}
	std::queue<ii> q;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			d[i][j] = degree[i][j];
			if(d[i][j] == 0)
				q.push(ii(i, j));
		}
	}
	while(!q.empty())
	{
		ii cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();
		d[to[x][y].first][to[x][y].second]--;
		if(d[to[x][y].first][to[x][y].second] == 0)
			q.push(ii(to[x][y].first, to[x][y].second));
		dist[x][y] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			dfs(i, j, 0);
		}
	}
	while(qq--)
	{
		memset(dist, 0, sizeof dist);
		std::string str;
		std::cin >> str;
		std::vector<int> missing (str.size() + 1, 0);
		for(int i = str.size() - 1; i >= 0; i--)
		{
			missing[i] = missing[i + 1] | (1 << (str[i] - '0'));
		}
		str += '#';
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				d[i][j] = degree[i][j];
				if(d[i][j] == 0)
					q.push(ii(i, j));
			}
		}
		while(!q.empty())
		{
			ii cur = q.front();
			q.pop();
			int x = cur.first, y = cur.second;
			if(str[dist[x][y]] == board[x][y])
				dist[x][y]++;
			if(to[x][y].first == x && to[x][y].second == y)
				continue;
			d[to[x][y].first][to[x][y].second]--;
			dist[to[x][y].first][to[x][y].second] = std::max(dist[to[x][y].first][to[x][y].second], dist[x][y]);
			if(d[to[x][y].first][to[x][y].second] == 0)
				q.push(ii(to[x][y].first, to[x][y].second));
		}
		bool ans = false;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				ans = ans || ((missing[dist[i][j]] & ~can[i][j]) == 0);
			}
		}
		if(ans)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}