#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm>

typedef std::pair<int, int> ii;

const int ms = 110;

int n, m;
std::string board[ms];

int dist[ms][ms];
int from[ms][ms];
ii prv[ms][ms];
int auxi[] = {0, 1, 0, -1};
int auxj[] = {1, 0, -1, 0};
char aux[] = {'R', 'D', 'L', 'U'};

ii apply(ii a, int dir)
{
	a.first += auxi[dir];
	a.second += auxj[dir];
	return a;
}

bool valid(ii a, int dir)
{
	a = apply(a, dir);
	if(a.first < 0 || a.first >= n || a.second < 0 || a.second >= m)
		return false;
	else
		return board[a.first][a.second] != '*';
}

int main()
{
	std::cin >> n >> m;
	ii end;
	for(int i = 0; i < n; i++)
	{
		std::cin >> board[i];
		for(int j = 0; j < m; j++)
		{
			if(board[i][j] == 'F')
				end = ii(i, j);
		}
	}
	std::queue<ii> q;
	q.push(ii(0, 0));
	memset(dist, 0x3f, sizeof dist);
	dist[0][0] = 0;
	while(!q.empty())
	{
		ii cur = q.front();
		int cur_dist = dist[cur.first][cur.second];
		q.pop();
		//std::cout << "on (" << cur.first << ", " << cur.second << ") dist is " << cur_dist << '\n';
		for(int i = 0; i < 4; i++)
		{
			if(valid(cur, i))
			{
				ii nxt = apply(cur, i);
				if(dist[nxt.first][nxt.second] > cur_dist + 1)
				{
					dist[nxt.first][nxt.second] = cur_dist + 1;
					from[nxt.first][nxt.second] = i;
					prv[nxt.first][nxt.second] = cur;
					q.push(nxt);
				}
			}
		}
	}
	std::vector<int> steps;
	std::vector<ii> pos;
	while(end != ii(0, 0))
	{
		steps.push_back(from[end.first][end.second]);
		pos.push_back(end);
		end = prv[end.first][end.second];
	}
	std::reverse(steps.begin(), steps.end());
	std::reverse(pos.begin(), pos.end());
	for(int i = 0; i < steps.size(); i++)
	{
		std::cout << aux[steps[i]] << std::endl;
		std::cin >> end.first >> end.second;
		end.first--;end.second--;
		if(end != pos[i])
		{
			std::swap(aux[steps[i]], aux[steps[i] ^ 2]);
			i--;
			continue;
		}
	}
}