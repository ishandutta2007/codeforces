#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

const int ms = 100100;
const int me = 18;

int n, m, q;

std::vector<int> edges[ms], people[ms];

int height[ms];
int parent[ms][me];
int lcs[ms][me][20];
int size[ms][me];

void dfs(int on, int par = -1, int h = 0)
{
	height[on] = h;
	parent[on][0] = par;
	//std::cout << "parent of " << on << " is " << par << " and h = " << h << '\n';
	for(int i = 0; i < edges[on].size(); i++)
	{
		int to = edges[on][i];
		if(to == par)
			continue;
		dfs(to, on, h + 1);
	}
}

std::vector<int> my_merge(std::vector<int> &b, std::vector<int> &c)
{
	std::vector<int> a;
	a.resize(b.size() + c.size());
	std::merge(b.begin(), b.end(), c.begin(), c.end(), a.begin());
	if(a.size() > 10)
		a.resize(10);
	return a;
}

void init()
{
	dfs(0);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < people[i].size(); j++)
			lcs[i][0][size[i][0]++] = people[i][j];
	}
	for(int j = 1; j < me; j++)
	{
		for(int i = 0; i < n; i++)
		{
			if(parent[i][j - 1] != -1)
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
			else
			{
				parent[i][j] = -1;
				continue;
			}
			std::merge(lcs[i][j - 1], lcs[i][j - 1] + size[i][j - 1], lcs[parent[i][j - 1]][j - 1], lcs[parent[i][j - 1]][j - 1] + size[parent[i][j - 1]][j - 1], lcs[i][j]);
			size[i][j] = std::min(10, size[i][j - 1] + size[parent[i][j - 1]][j - 1]);
		}
	}
}

std::vector<int> solve(int a, int b)
{
	if(a == b)
		return people[a];
	std::vector<int> ans;
	if(height[a] < height[b])
		std::swap(a, b);
	//std::cout << "solving (" << a << ", " << b << ")\n";
	int up = height[a] - height[b];
	//std::cout << "going up " << up << '\n';
	for(int i = me - 1; i >= 0; i--)
	{
		if(up & (1 << i))
		{
			std::vector<int> temp;
			for(int j = 0; j < size[a][i]; j++)
				temp.push_back(lcs[a][i][j]);
			ans = my_merge(ans, temp);
			a = parent[a][i];
		}
	}
	//std::cout << "went to " << a << ", " << b << "\n";
	if(a == b)
	{
		//std::cout << "got ans, a == b == " << a << '\n';
		std::vector<int> temp;
		for(int j = 0; j < size[a][0]; j++)
			temp.push_back(lcs[a][0][j]);
		ans = my_merge(ans, temp);
		return ans;
	}
	for(int i = me - 1; i >= 0; i--)
	{
		if(parent[a][i] != parent[b][i])
		{
			std::vector<int> temp;
			for(int j = 0; j < size[a][i]; j++)
				temp.push_back(lcs[a][i][j]);
			ans = my_merge(ans, temp);
			temp.clear();
			for(int j = 0; j < size[b][i]; j++)
				temp.push_back(lcs[b][i][j]);
			ans = my_merge(ans, temp);
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	std::vector<int> temp;
	for(int j = 0; j < size[a][0]; j++)
		temp.push_back(lcs[a][0][j]);
	ans = my_merge(ans, temp);
	a = parent[a][0];
	temp.clear();
	for(int j = 0; j < size[a][0]; j++)
		temp.push_back(lcs[a][0][j]);
	ans = my_merge(ans, temp);
	temp.clear();
	for(int j = 0; j < size[b][0]; j++)
		temp.push_back(lcs[b][0][j]);
	ans = my_merge(ans, temp);
	return ans;
}

int main()
{
	std::cin >> n >> m >> q;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%i %i", &u, &v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 0; i < m; i++)
	{
		int u;
		scanf("%i", &u);
		u--;
		people[u].push_back(i);
	}
	for(int i = 0; i < n; i++)
	{
		if(people[i].size() > 10)
			people[i].resize(10);
	}
	init();
	while(q--)
	{
		int u, v, a;
		scanf("%i %i %i", &u, &v, &a);
		u--;v--;
		std::vector<int> ans = solve(u, v);
		if(ans.size() > a)
			ans.resize(a);
		printf("%i ", int(ans.size()));
		for(int i = 0; i < ans.size(); i++)
		{
			if(i)
				printf(" ");
			printf("%i", ans[i] + 1);
		}
		printf("\n");
	}
}