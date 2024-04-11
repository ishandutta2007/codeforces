#include <iostream>
#include <vector>

int gcd(int a, int b)
{
	if(!b)
		return a;
	else
		return gcd(b, a % b);
}

const int ms = 300100;

int a[ms], ans[ms], freq[ms];
std::vector<int> edges[ms], divs[ms];

void go(int on, int h, int par = -1, int best = 0)
{
	ans[on] = best;
	best = 0;
	for(int i = 0; i < divs[a[on]].size(); i++)
	{
		int cur = divs[a[on]][i];
		freq[cur]++;
		if(freq[cur] >= h)
			ans[on] = std::max(ans[on], cur);
		if(freq[cur] == h + 1)
			best = std::max(best, cur);
	}
	for(int i = 0; i < edges[on].size(); i++)
	{
		int to = edges[on][i];
		if(to == par)
			continue;
		go(to, h + 1, on, best);
	}
	for(int i = 0; i < divs[a[on]].size(); i++)
	{
		int cur = divs[a[on]][i];
		freq[cur]--;
	}
}


int main()
{
	for(int i = 1; i < ms; i++)
	{
		for(int j = i; j < ms; j += i)
		{
			divs[j].push_back(i);
		}
	}
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	go(0, 0);
	for(int i = 0; i < n; i++)
		std::cout << ans[i] << '\n';
}