#include <iostream>
#include <vector>

const int ms = 200200;

std::vector<int> edges[ms];
int dist[ms][2];
int to[ms][2];

void dfs(int on, int type, int h = 0, int par = 0)
{
	dist[on][type] = h;
	to[on][type] = par;
	for(int i = 0; i < edges[on].size(); i++)
	{
		int to = edges[on][i];
		if(to == par)
			continue;
		dfs(to, type, h + 1, on);
	}
}

int main()
{
	int n, x;
	std::cin >> n >> x;
	for(int i = 1; i < n; i++)
	{
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1, 0);
	dfs(x, 1);
	int ans = 0;
	for(int i = 2; i <= n; i++)
	{
		if(dist[i][0] >= dist[i][1])
		{
			if(i == x || dist[to[i][0]][0] != dist[to[i][0]][1] || dist[to[i][1]][0] > dist[i][0])
				ans = std::max(ans, dist[i][0] * 2);
			//std::cout << "on " << i << ", dists are (" << dist[to[i][1]][0] << ", " << dist[i][0] << ")\n";
		}
	}
	std::cout << ans << '\n';
}