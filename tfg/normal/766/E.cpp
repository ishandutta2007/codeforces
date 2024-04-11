#include <iostream>
#include <cstdio>
#include <vector>

typedef long long ll;

const int ms=100100;

int n;

bool exist[ms];
int a[ms];

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
			//std::swap(edges[on][i], edges[on].back());
			//edges[on].pop_back();
			//i--;
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

const int bits=22;

ll global_ans=0;

int dfs2(int on, int dist, std::vector<int> &x)
{
	if(step[on]==cur_step)
		return 0;
	step[on]=cur_step;
	dist^=a[on];
	global_ans+=dist;
	for(int i=0;i<bits;i++)
	{
		if(dist&(1<<i))
			x[i]++;
	}
	int ans=1;
	for(int i=0;i<edges[on].size();i++)
	{
		int t=edges[on][i];
		if(!exist[t])
		{
			//std::swap(edges[on][i], edges[on].back());
			//edges[on].pop_back();
			//i--;
			continue;
		}
		ans+=dfs2(t, dist, x);
	}
	return ans;
}

ll wtf(ll a, ll size_a, ll b, ll size_b)
{
	ll ans=a*(size_b-b)+(size_a-a)*b;
	return ans;
}

std::vector<int> sum;

int solve(int on)
{
	ll last=global_ans;
	cur_step++;
	on=get_centroid(on);
	//solve bits for each subtree
	
	sum=std::vector<int> (bits, 0);
	int total_size=0;
	for(int i=0;i<edges[on].size();i++)
	{
		if(!exist[edges[on][i]])
			continue;
		cur_step++;
		step[on]=cur_step;
		std::vector<int> cur=std::vector<int> (bits, 0);
		int cur_size=dfs2(edges[on][i], a[on], cur);
		for(int j=0;j<bits;j++)
		{
			if(a[on] & (1<<j))
				global_ans+=(1<<j)*wtf(sum[j], total_size, cur_size-cur[j], cur_size);
			else
				global_ans+=(1<<j)*wtf(sum[j], total_size, cur[j], cur_size);
			sum[j]+=cur[j];
		}
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
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		exist[i]=true;
		scanf("%i",a+i);
		//global_ans+=a[i];
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
	for(int i=0;i<n;i++)
		global_ans+=a[i];
	std::cout << global_ans << '\n';
}