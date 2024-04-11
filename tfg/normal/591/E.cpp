#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#include <string>

typedef std::pair<int, int> ii;
typedef long long ll;

const int ms = 1010;
const ll INF = 1e10;

int n, m;
std::string board[ms];

bool valid(ii a)
{
	if(a.first < 0 || a.first >= n || a.second < 0 || a.second >= m)
		return false;
	else
		return board[a.first][a.second] != '#';
}

ll dist[ms][ms][3];
ll side[3][3];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

ll bfs(int type)
{
	for(int i = 0; i < 3; i++)
		side[type][i] = INF + 2;
	std::queue<ii> q;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(board[i][j] == '1' + type)
			{
				q.push(ii(i, j));
				dist[i][j][type] = 0;
			}
		}
	}
	while(!q.empty())
	{
		ii cur = q.front();
		ll cur_dist = dist[cur.first][cur.second][type];
		q.pop();
		if(board[cur.first][cur.second] != '.')
			side[type][board[cur.first][cur.second] - '1'] = std::min(cur_dist, side[type][board[cur.first][cur.second] - '1']);
		for(int i = 0; i < 4; i++)
		{
			int x = cur.first + dx[i];
			int y = cur.second+ dy[i];
			if(valid(ii(x, y)) && cur_dist + 1 < dist[x][y][type])
			{
				dist[x][y][type] = cur_dist + 1;
				q.push(ii(x, y));
			}
		}
	}
	//std::cout << "type " << type << " got (" << side[type][0] << ", " << side[type][1] << ", " << side[type][2] << ") = " << side[type][0] + side[type][1] + side[type][2] << '\n';
	return side[type][0] + side[type][1] + side[type][2] - 2;
}

int main()
{
	for(int i = 0; i < ms; i++)
	{
		for(int j = 0; j < ms; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				dist[i][j][k] = INF;
			}
		}
	}
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
		std::cin >> board[i];
	ll ans = std::min(bfs(0), std::min(bfs(1), bfs(2)));
	if(ans >= INF)
	{
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			ll sum = 0;
			for(int k = 0; k < 3; k++)
				sum += dist[i][j][k];
			if(sum < INF)
				ans = std::min(ans, sum - 2);
		}
	}
	ans = std::min(side[0][1] + side[0][2] - 2, ans);
	ans = std::min(side[0][1] + side[1][2] - 2, ans);
	ans = std::min(side[0][2] + side[0][1] - 2, ans);
	ans = std::min(side[0][2] + side[1][2] - 2, ans);
	std::cout << ans << '\n';
}