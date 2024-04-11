#include <iostream>
#include <cstdio>
#include <vector>

const int ms=100100;

int n;

std::vector<int> edges[ms];

int c[ms];

int par[ms];
int size[ms];
int step[ms];

int get_par(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=get_par(par[x]);
}

void make_union(int a, int b)
{
	a=get_par(a);
	b=get_par(b);
	if(a==b)
		return;
	size[a]+=size[b];
	par[b]=a;
}


int main()
{
	std::cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int u, v;
		scanf("%i %i",&u,&v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%i", c+i);
		par[i]=i;
		size[i]=1;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<edges[i].size();j++)
		{
			int to=edges[i][j];
			if(c[to]==c[i])
				make_union(to, i);
		}
	}
	
	int groups=0;
	int cur_step=1;
	for(int i=0;i<n;i++)
	{
		int on=get_par(i);
		if(step[on]==cur_step)
			continue;
		step[on]=1;
		groups++;
	}
	
	for(int i=0;i<n;i++)
	{
		cur_step++;
		int others=0;
		for(int j=0;j<edges[i].size();j++)
		{
			int to=edges[i][j];
			if(step[get_par(to)]==cur_step)
				continue;
			step[get_par(to)]=cur_step;
			others++;
		}
		int hmm=groups;
		if(size[get_par(i)]==1)
			hmm--;
		if(others==hmm)
		{
			std::cout << "YES\n" << i+1 << '\n';
			return 0;
		}
	}
	std::cout << "NO\n";
	
}