#include <iostream>
#include <vector>
#include <cstdio>

const int ms = 200200;

int pos[ms];
std::vector<int> edges[ms];
bool visit[ms];

int dfs(int on, int dist = 0)
{
	if(visit[on])
		return 0;
	visit[on] = true;
	int ans = dist;
	for(auto a : edges[on])
		ans = std::max(ans, dfs(a, dist + 1));
	visit[on] = false;
	return ans;
}

int main()
{
	int n, k;
	std::cin >> n >> k;
	int leaf = k;
	int mid = n - leaf;
	for(int i = 1; i <= leaf; i++)
	{
		edges[i].push_back(n);
		edges[n].push_back(i);
	}
	for(int i = leaf + 1; i < n; i++)
	{
		edges[i].push_back(i - leaf);
		edges[i - leaf].push_back(i);
	}
	std::cout << dfs(n - 1) << '\n';
	for(int i = 1; i <= leaf; i++)
		printf("%i %i\n", i, n);
	for(int i = leaf + 1; i < n; i++)
		printf("%i %i\n", i - leaf, i);
}