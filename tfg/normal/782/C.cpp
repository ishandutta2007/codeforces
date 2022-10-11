#include <iostream>
#include <vector>
#include <cstdio>

const int ms=200100;

std::vector<int> edges[ms];
int color[ms];

int step[ms];
int cur_step=0;

void solve(int on, int par=-1)
{
	cur_step++;
	for(int i=0;i<edges[on].size();i++)
	{
		int to=edges[on][i];
		step[color[to]]=cur_step;
	}
	step[color[on]]=cur_step;
	int cur=1;
	while(step[cur]==cur_step)
		cur++;
	if(!color[on])
	{
		//std::cout << "self-coloring " << on << " with " << cur << '\n';
		color[on]=cur;
		step[cur]=cur_step;
		while(step[cur]==cur_step)
			cur++;
	}
	for(int i=0;i<edges[on].size();i++)
	{
		int to=edges[on][i];
		if(color[to])
			continue;
		//std::cout << "coloring " << to << " with " << cur << '\n';
		color[to]=cur;
		step[cur]=cur_step;
		while(step[cur]==cur_step)
			cur++;
	}
	for(int i=0;i<edges[on].size();i++)
	{
		int to=edges[on][i];
		if(to==par)
			continue;
		solve(to, on);
	}
}

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int u, v;
		scanf("%i %i",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	solve(1);
	int k=0;
	for(int i=1;i<=n;i++)
		k=std::max(k, color[i]);
	std::cout << k << '\n';
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
			printf(" ");
		printf("%i",color[i]);
	}
	std::cout << '\n';
}