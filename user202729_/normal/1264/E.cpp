/*
 * The idea of counting the complement is familiar...
 *
 * In the contest, I didn't (have the time to) figure out the min cost max flow solution (although
 * I did think that the solution may involve flow). Already I don't have the template for min cost maximum flow anyway.
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<queue>
#include<limits>

template<class cap_t=int,class cost_t=int>
struct MCMF{
	std::vector<std::vector<int>> ad;
	struct edge{
		int v;
		cap_t residual;
		cost_t cost;
	};
	std::vector<edge> edges;

	MCMF(int n):ad(n){}
	void addedge(int a,int b,cap_t cap,cost_t cost){
		ad[a].push_back((int)edges.size());
		edges.push_back({b,cap,cost});
		ad[b].push_back((int)edges.size());
		edges.push_back({a,(cap_t)0,-cost});
	}

	std::pair<cap_t,cost_t> run(int source,int sink){
		// "slow" algorithm. Does not work properly when there's any negative cycle.
		cap_t total_flow=0;cost_t total_cost=0;
		while(true){
			std::queue<int> q;
			std::vector<char> inq(ad.size(),false);
			std::vector<cost_t> dist(ad.size(),std::numeric_limits<cost_t>::max());
			std::vector<int> pre(ad.size(),-1);

			dist[source]=0;
			q.push(source);
			inq[source]=true;

			while(not q.empty()){
				int x=q.front();q.pop();
				inq[x]=false;
				auto dx=dist[x];
				for(int edgeid:ad[x]){
					edge& e=edges[edgeid];
					if(e.residual){
						auto nd=e.cost+dx;
						if(nd<dist[e.v]){
							dist[e.v]=nd;
							pre[e.v]=edgeid;
							if(not inq[e.v]){
								inq[e.v]=true;
								q.push(e.v);
							}
						}
					}
				}
			}

			if(dist[sink]==std::numeric_limits<cost_t>::max())
				return {total_flow,total_cost};

			int x=sink;
			cap_t f=std::numeric_limits<cap_t>::max();
			while(x!=source){
				f=std::min(f,edges[pre[x]].residual);
				x=edges[pre[x]^1].v;
			}

			x=sink;
			while(x!=source){
				edges[pre[x]].residual-=f;
				edges[pre[x]^1].residual+=f;
				x=edges[pre[x]^1].v;
			}

			total_flow+=f;
			total_cost+=f*dist[sink];
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<std::vector<char>> c(n,std::vector<char>(n));
	int m;std::cin>>m;
	while(m--){
		int u,v;std::cin>>u>>v;--u;--v;
		c[u][v]=1;
	}
	
	MCMF ff(n+n*(n-1)/2+2);
	int const source=n+n*(n-1)/2;
	int const sink=n+n*(n-1)/2+1;

	for(int u=0,enode=n;u<n;++u)
	for(int v=0;v<u;++v,++enode){
		ff.addedge(source,enode,1,0);
		if(not c[u][v])
			ff.addedge(enode,u,1,0);
		if(not c[v][u])
			ff.addedge(enode,v,1,0);
	}

	for(int x=0;x<n;++x)
		for(int i=0;i<n;++i)
			ff.addedge(x,sink,1,i);

	auto [cap,cost]=ff.run(source,sink);
	assert(cap==n*(n-1)/2);

	for(int u=0,enode=n;u<n;++u)
	for(int v=0;v<u;++v,++enode){
		if(ff.ad[enode].size()!=3)
			assert(ff.ad[enode].size()==2);
		else
			for(auto edgeid:ff.ad[enode]){
				if(ff.edges[edgeid].residual){
					continue;
				}else if(ff.edges[edgeid].v==u){
					c[v][u]=1;
				}else if(ff.edges[edgeid].v==v){
					c[u][v]=1;
				}
			}
	}

	for(auto const& row:c){
		for(char ch:row)std::cout<<char('0'+ch);
		std::cout<<'\n';
	}
}