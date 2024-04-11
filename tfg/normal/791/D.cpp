#include <iostream>
#include <cstdio>
#include <vector>

typedef long long ll;

const int ms=200100;

int n, k;

bool exist[ms];

int cur_step=0;

std::vector<int> edges[ms];

int down[ms], max_down[ms], to[ms], step[ms];

int dfs1(int on)
{
	if(step[on]==cur_step)
		return 0;
	step[on]=cur_step;
	max_down[on]=down[on]=0;
	for(int i=0;i<edges[on].size();i++)
	{
		int t=edges[on][i];
		if(!exist[t])
		{
			std::swap(edges[on][i], edges[on].back());
			edges[on].pop_back();
			i--;
			continue;
		}
		int ans=dfs1(t);
		if(ans>max_down[on])
		{
			max_down[on]=ans;
			to[on]=t;
		}
		down[on]+=ans;
	}
	return down[on]+1;
}

int get_centroid(int on)
{
	int v=dfs1(on);
	while(max_down[on]>v/2)
		on=to[on];
	return on;
}

ll global_ans=0;
ll global_sum;
std::vector<ll> paths;

int dfs2(int on, int dist, std::vector<ll> &x)
{
	if(step[on]==cur_step)
		return 0;
	step[on]=cur_step;
	global_sum+=dist;
	x[dist%k]++;
	int ans=1;
	for(int i=0;i<edges[on].size();i++)
	{
		int t=edges[on][i];
		if(!exist[t])
		{
			std::swap(edges[on][i], edges[on].back());
			edges[on].pop_back();
			i--;
			continue;
		}
		ans+=dfs2(t, dist+1, x);
	}
	return ans;
}

int solve(int on)
{
	ll last=global_ans;
	cur_step++;
	on=get_centroid(on);
	
	ll total_size=1;
	std::vector<ll> top(k, 0);
	top[0]++;
	ll sum=0;
	for(int i=0;i<edges[on].size();i++)
	{
		if(!exist[edges[on][i]])
			continue;
		//std::cout << "from " << on << " to " << edges[on][i] << '\n';
		cur_step++;
		step[on]=cur_step;
		std::vector<ll> cur(k, 0);
		global_sum=0;
		ll cur_size=dfs2(edges[on][i], 1, cur);
		//std::cout << "got dist " << global_sum << '\n';
		for(int j=0;j<k;j++)
		{
			for(int jj=0;jj<k;jj++)
			{
				paths[(j+jj)%k]+=top[j]*cur[jj];
			}
		}
		for(int j=0;j<k;j++)
			top[(j)%k]+=cur[j];
		global_ans+=global_sum*total_size + sum*cur_size;
		sum+=global_sum;
		total_size+=cur_size;
	}
	exist[on]=false;

	for(int i=0;i<edges[on].size();i++)
	{
		if(exist[edges[on][i]])
		{
			solve(edges[on][i]);
		}
	}
}

int main()
{
	std::cin >> n >> k;
	paths=std::vector<ll>(k, 0);
	for(int i=0;i<n;i++)
	{
		exist[i]=true;
	}
	for(int i=1;i<n;i++)
	{
		int u, v;
		scanf("%i %i",&u,&v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	solve(0);
	//std::cout << "sum is " << global_ans << '\n';
	for(int i=1;i<k;i++)
		global_ans += (k-i)*paths[i];
	std::cout << global_ans/k << '\n';
}