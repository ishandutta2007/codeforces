#include <stdio.h>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char dat[55][55];
bool visit[55][55];
int dr[4][2]=
{
	1,0,-1,0,0,1,0,-1
};

using lake = vector < pair<int, int> > ;
int n, m;

lake bfs(int x, int y)
{
	bool border = false;
	lake ret;

	queue<pair<int, int>> que;
	visit[x][y] = true;
	que.emplace(x, y);
	ret.emplace_back(x, y);

	while (que.empty() == false)
	{
		int tx, ty;
		tie(tx, ty) = que.front();
		que.pop();

		if (tx == 1 || tx == n || ty == 1 || ty == m) border = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dr[i][0];
			int ny = ty + dr[i][1];
			if (visit[nx][ny] || dat[nx][ny] != '.') continue;
			visit[nx][ny] = true;
			que.emplace(nx, ny);
			ret.emplace_back(nx, ny);
		}
	}

	if (border) ret.clear();

	return ret;
}

vector<lake> lakes;

int main()
{
	int k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", dat[i] + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dat[i][j] != '.') continue;
			if (visit[i][j]) continue;

			lakes.push_back(bfs(i, j));
		}
	}

	sort(lakes.begin(), lakes.end(), [](const lake &a1, const lake &a2)
	{
		return a1.size() > a2.size();
	});

	int ans = 0;

	while (lakes.size() > k)
	{
		ans += lakes.back().size();

		if (lakes.back().empty())
		{
			lakes.pop_back();
			continue;
		}

		for (auto &&p : lakes.back())
		{
			dat[p.first][p.second] = '*';
		}

		lakes.pop_back();
	}

	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) puts(dat[i] + 1);
}