#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

const int me = 12;
const int ms = 3001;

std::vector<int> edges[ms];

short int visit[ms][ms];
short int par[ms][me][ms];
short int height[ms][ms];
bool cant[ms][ms];

short int dfs(short int world, short int on, bool dirty = false, short int h = 0)
{
	//std::cout << "on (" << world << ", " << on << ", " << dirty << ", " << h << ")\n";
	height[world][on] = h;
	short int ans = -1;
	visit[world][on] = 1;
	for(auto a : edges[on])
	{
		if(visit[world][a] == 2)
			continue;
		else if(visit[world][a] == 1)
		{
			if(ans == -1 || height[world][ans] > height[world][a])
				ans = a;
		}
		else
		{
			par[world][0][a] = on;
			short int cur_ans = dfs(world, a, ans != -1 || dirty, h + 1);
			if(ans == -1 || (cur_ans != -1 && height[world][ans] > height[world][cur_ans]))
				ans = cur_ans;
		}
	}
	if(dirty)
		cant[world][on] = true;
	visit[world][on] = 2;
	//std::cout << "out (" << world << ", " << on << ", " << cant[world][on] << ") = " << ans << "\n";
	return ans == on ? -1 : ans;
}

int up(int u, int v, int k)
{
	int diff = height[u][v] - k + 1;
	while(diff > (1 << (me - 1)))
	{
		diff -= (1 << (me - 1));
		v = par[u][me - 1][v];
	}
	for(int i = me - 1; i >= 0; i--)
	{
		if((diff & (1 << i)) != 0)
			v = par[u][i][v];
	}
	return v;
}

int main()
{
	int n, m, q;
	std::cin >> n >> m >> q;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%i %i", &u, &v);
		//std::cin >> u >> v;
		edges[u].push_back(v);
	}
	for(int i = 1; i <= n; i++)
		std::sort(edges[i].begin(), edges[i].end());
	for(int i = 1; i <= n; i++)
	{
		//std::cout << "STARTING WORLD " << i << "\n";
		dfs(i, i);
		for(int j = 0; j + 1 < me; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				int to = par[i][j][k];
				par[i][j + 1][k] = par[i][j][to];
			}
		}
	}
	while(q--)
	{
		int u, v, k;
		scanf("%i %i %i", &u, &v, &k);
		//std::cin >> u >> v >> k;
		//std::cout << "trying (" << u << ", " << v << "), height is " << height[u][v] << ", k = " << k << "\n";
		if(visit[u][v] == 0 || cant[u][v] || height[u][v] < k - 1)
		{
			std::cout << "-1\n";
		}
		else
		{
			std::cout << up(u, v, k) << '\n';
		}
	}
}