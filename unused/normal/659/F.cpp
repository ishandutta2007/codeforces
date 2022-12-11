#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string.h>
using namespace std;

int dat[1005][1005];

set<int> dv;
int n, m;
long long k;
bool visited[1005][1005];
int dr[4][2] = {
	1, 0,
	0, 1,
	-1, 0,
	0, -1
};

bool bfs(int x, int y, bool output)
{
	queue<pair<int, int>> que;
	int target = k / dat[x][y] - 1;
	visited[x][y] = true;
	que.emplace(x, y);

	while (que.empty() == false && target > 0)
	{
		auto t = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = t.first + dr[i][0];
			int ny = t.second + dr[i][1];
			if (nx < 0 || nx >= n ||
				ny < 0 || ny >= m) continue;

			if (dat[nx][ny] < dat[x][y]) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = true;
			--target;
			que.emplace(nx, ny);
			if (target == 0) break;
		}
	}

	if (target == 0)
	{
		if (output == false)
		{
			memset(visited, 0, sizeof(visited));
			return bfs(x, y, true);
		}

		printf("YES\n");

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (visited[i][j]) printf("%d ", dat[x][y]);
				else printf("0 ");
			}
			printf("\n");
		}

		return true;
	}

	return false;
}

int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &dat[i][j]);
			if (k % dat[i][j] == 0 && k / dat[i][j] <= n * m) dv.insert(dat[i][j]);
		}
	}

	for (auto itr : dv)
	{
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (dat[i][j] == itr && visited[i][j] == false)
				{
					if (bfs(i, j, false)) return 0;
				}
			}
		}
	}

	printf("NO\n");
}