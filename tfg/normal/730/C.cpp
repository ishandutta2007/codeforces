#include <cstring>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

#define fre(a,b) for(int b=adj[a];b!=-1;b=ant[b])


typedef long long int ll;
typedef std::pair<ll, ll> ii;

const int mv=5050;
const int me=2*5050;

int adj[mv], ant[me], to[me], z;

std::vector<ii> shops[me];
// first is cost

void init()
{
	memset(adj, -1, sizeof adj);
	z=0;
}

inline void add(int m_from, int m_to)
{
	ant[z]=adj[m_from];
	to[z]=m_to;
	adj[m_from]=z++;
}

int cur_step=0;
int step[me];
int dist[me];

int bfs(int origin, ll max_cost, ll wanted)
{
	cur_step++;
	//std::cout << "step " << cur_step << std::endl;
	ll sh=0;
	ll cost=0;
	int max_dist=0;
	std::priority_queue<ii> shovels;
	std::queue<int> city;
	city.push(origin);
	dist[origin]=0;
	step[origin]=cur_step;
	while(!city.empty())
	{
		int cur=city.front();
		max_dist=std::max(max_dist,dist[cur]);
		city.pop();
		//std::cout << "on city " << cur << " dist is " << dist[cur] << std::endl;
		//std::cout << "has " << sh << " shovels and cost " << cost << std::endl; 
		for(int i=0;i<shops[cur].size();i++)
		{
			cost+=shops[cur][i].first*shops[cur][i].second;
			sh+=shops[cur][i].second;
			shovels.push(shops[cur][i]);
			//std::cout << "added " << shops[cur][i].second << " shovels of price " << shops[cur][i].first << std::endl;
		}
		//std::cout << "cur cost is " << cost << " max cost is " << max_cost << std::endl;
		while(cost>max_cost)
		{
			ii old=shovels.top();
			shovels.pop();
			ll take=std::min(old.second,(cost-max_cost+old.first-1)/old.first);
			//std::cout << "taking " << take << " shovels of price " << old.first;
			//std::cout << " cur cost is " << cost << std::endl;
			sh-=take;
			cost-=old.first*take;
			old.second-=take;
			if(old.second==0) continue;
			shovels.push(old);
		}
		if(sh>=wanted) return max_dist;
		fre(cur,i)
		{
			if(step[to[i]]==cur_step) continue;
			//std::cout << "adding " << to[i] << " to the que\n";
			step[to[i]]=cur_step;
			city.push(to[i]);
			dist[to[i]]=dist[cur]+1;
		}
	}
	return -1;

}

int main()
{
	init();
	int n,m;
	std::cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		std::cin >> t1 >> t2;
		add(t1,t2);
		add(t2,t1);
	}
	int w;
	std::cin >> w;
	for(int i=0;i<w;i++)
	{
		ll freq, cost;
		int on;
		std::cin >> on >> freq >> cost;
		shops[on].push_back(ii(cost,freq));
	}
	int q;
	std::cin >> q;
	for(int i=0;i<q;i++)
	{
		int on;
		ll max_cost, wanted;
		std::cin >> on >> wanted >> max_cost;
		//std::cout << "starting on " << on << " getting " << wanted << " cost " << max_cost << std::endl;
		std::cout << bfs(on,max_cost,wanted) << std::endl;
	}
}