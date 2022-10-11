#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

const int ms = 100100;

std::vector<int> edges[ms];
int deg[ms];
int ans[ms];

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		std::cin >> u >> v;
		deg[u]++;
		edges[v].push_back(u);
	}
	std::priority_queue<int> hp;
	for(int i = 1; i <= n; i++)
	{
		if(deg[i] == 0)
			hp.push(i);
	}
	int pt = n;
	while(!hp.empty())
	{
		int on = hp.top();
		hp.pop();
		ans[on] = pt--;
		for(auto to : edges[on])
		{
			deg[to]--;
			if(deg[to] == 0)
				hp.push(to);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(i != 1)
			std::cout << ' ';
		std::cout << ans[i];
	}
	std::cout << '\n';
}