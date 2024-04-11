#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int Maxn = 400005;
int T, n, m, cnt;
bool vis[Maxn];
pair <int, int> edge[Maxn];
vector <int> Ve[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cnt = 0;
		scanf("%d%d", &n, &m);
		memset(vis, 0, sizeof(bool[n + 1]));
		for (int i = 1; i <= n; i++)
			Ve[i].clear();
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &edge[i].x, &edge[i].y);
			Ve[edge[i].x].push_back(edge[i].y);
		}
		sort(edge + 1, edge + 1 + m, [](pair <int, int> x, pair <int, int> y){return x.second < y.second;});
		for (int i = 1; i <= m; i++)
			if (!vis[edge[i].x] && !vis[edge[i].y])
				for (vector <int> :: iterator it = Ve[edge[i].y].begin(); it != Ve[edge[i].y].end(); it++)
					vis[*it] = true;
		for (int i = 1; i <= n; i++)
			if (vis[i]) cnt++;
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++)
			if (vis[i]) printf("%d ", i);
		puts("");
	}
	return 0;
}