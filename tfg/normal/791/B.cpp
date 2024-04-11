#include <iostream>
#include <cstdio>
#include <vector>

const int ms=200200;

std::vector<int> edges[ms];
int size[ms], par[ms], tot[ms];

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
	size[a]=std::min(size[a], size[b]);
	tot[a]+=tot[b];
	par[b]=a;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	while(m--)
	{
		int u, v;
		scanf("%i %i", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		size[i]=edges[i].size();
		par[i]=i;
		tot[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<edges[i].size();j++)
			make_union(i, edges[i][j]);
	}
	bool ans=true;
	for(int i=1;i<=n;i++)
	{
		int on=get_par(i);
		if(tot[on]-1!=size[on])
		{
			ans=false;
		}
	}
	if(ans)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}