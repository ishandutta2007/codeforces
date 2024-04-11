#include <iostream>
#include <cstdio>
#include <vector>

typedef long long ll;

const int ms=100100;

int par[ms], size[ms], color[ms];

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

std::vector<int> edges[ms];
ll freq[3];

bool dfs(int on)
{
	//std::cout << on << " is color " << color[on] << '\n';
	freq[color[on]]++;
	int nxt_color;
	if(color[on]==1)
		nxt_color=2;
	else
		nxt_color=1;
	bool ans=true;
	for(int i=0;i<edges[on].size() && ans;i++)
	{
		int to=edges[on][i];
		if(color[to]==-1)
		{
			color[to]=nxt_color;
			ans=dfs(to);
		}
		else
		{
			if(color[to]==color[on])
			{
				//std::cout << "failed from " << on << " to " << to << '\n';
				ans=false;
			}
		}
	}
	return ans;
}

ll create_cycle(ll x)
{
	return (x*(x-1))/2;
}

int hmm[ms];

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		color[i]=-1;
		size[i]=1;
		par[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		int u, v;
		scanf("%i %i",&u,&v);
		u--;v--;
		make_union(u, v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int dafak=0;
	bool bi=true;
	ll haha=0;
	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
			dafak=std::max(dafak, size[get_par(i)]);
			hmm[size[get_par(i)]]++;
			freq[1]=freq[2]=0;
			color[i]=1;
			bi=bi&&dfs(i);
			haha+=create_cycle(freq[1])+create_cycle(freq[2]);
		}
	}
	if(dafak==1)
	{
		std::cout << 3 << ' ' << ((ll)n*(ll)(n-1)*(ll)(n-2))/6 << '\n';
	}
	else if(dafak==2)
	{
		std::cout << 2 << ' ' << (ll)(n-2)*(ll)(hmm[2]);
	}
	else
	{
		if(!bi)
			std::cout << "0 1\n";
		else
			std::cout << 1 << ' ' << haha << '\n';
	}
}