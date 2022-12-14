// dominance tree

#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<queue>
#include<tuple>
#include<cassert>
#include<iostream>
#include<vector>
#include<array>
#include<climits>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m,s;std::cin>>n>>m>>s;--s;

	struct edge{
		int x,dist;
	};
	std::vector<std::vector<edge>> ad(n);
	for(int z=m;z--;){
		int u,v,w;std::cin>>u>>v>>w;
		--u;--v;
		ad[u].push_back({v,w});
		ad[v].push_back({u,w});
	}

	std::vector<int64_t> dist(n,INT64_MAX);
	struct state{
		int x;int64_t dist;
		bool operator<(state s)const{
			return dist>s.dist;
		}
	};
	std::priority_queue<state> q;

	std::vector<std::array<int,20>> jt(n); // jump table = parent (for dominance tree of dijkstra graph)
	// NOTE denote par[s] == s
	std::vector<int> depth(n);

	auto const setpar=[&](int x,int par){
		jt[x][0]=par;
		depth[x]=1+depth[par];
		for(unsigned i=1;i<jt[x].size();++i)
			jt[x][i]=jt[jt[x][i-1]][i-1];
	};
	setpar(s,s);
	depth[s]=1;

	auto const lca=[&](int x,int y){
		if(depth[x]<depth[y])std::swap(x,y);
		int dd =depth[x]-depth[y];
		for(auto step=jt[x].size();step--;)
			if(dd>>step&1)
				x=jt[x][step];
		assert(depth[x]==depth[y]);
		if(x==y)return y;
		for(auto step=jt[x].size();step--;)
			if(jt[x][step]!=jt[y][step])
				std::tie(x,y)={jt[x][step],jt[y][step]};
		assert(x!=y);
		assert(jt[x][0]==jt[y][0]);
		return jt[x][0];
	};

	q.push({s,dist[s]=0});
	std::vector<int> vs;vs.reserve(n); // visited vertices int increasing dist order
	while(!q.empty()){
		auto [x,d]=q.top();q.pop();
		if(d!=dist[x])continue;
		vs.push_back(x);
		for(auto e:ad[x]){
			auto const ndist=d+e.dist;
			if(ndist<dist[e.x]){
				q.push({e.x, dist[e.x]=ndist});
				setpar(e.x,x);
			}else if(ndist==dist[e.x]){
				setpar(e.x, lca(jt[e.x][0],x));
			}
		}
	}

	std::vector<int> stsize(n);
	std::for_each(vs.rbegin(),vs.rend(),[&](int x){
			++stsize[x];
			if(x!=s)
				stsize[jt[x][0]]+=stsize[x];
			else
				assert(stsize[x]==vs.size());
			});
	stsize[s]=0;
	std::cout<<*std::max_element(begin(stsize),end(stsize))<<'\n';
}