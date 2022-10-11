#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

typedef std::pair<int, int> ii;

const int ms = 100100;

int a[ms];
ii b[ms];
int to[ms];
bool visit[ms];

std::vector<std::vector<int> > ans;

void dfs(int on, std::vector<int> &dude)
{
	visit[on] = true;
	dude.push_back(on + 1);
	if(!visit[to[on]])
		dfs(to[on], dude);
}

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		b[i] = ii(a[i], i);
	}
	std::sort(b, b + n);
	for(int i = 0; i < n; i++)
		to[b[i].second] = i;
	for(int i = 0; i < n; i++)
	{
		if(!visit[i])
		{
			std::vector<int> dude;
			dfs(i, dude);
			ans.push_back(dude);
		}
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
	{
		std::cout << ans[i].size() << ' ';
		for(int j = 0; j < ans[i].size(); j++)
		{
			if(j)
				std::cout << ' ';
			std::cout << ans[i][j];
		}
		std::cout << '\n';
	}
}