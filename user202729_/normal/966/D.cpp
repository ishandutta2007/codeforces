/*
 * {...}
 */
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode,nedge;std::cin>>nnode>>nedge;
	std::vector<std::vector<int>> ad(nnode);
	for(int z=nedge,u,v;z--;){
		std::cin>>u>>v;
		--u;--v;
		//if(std::minmax(u,v)==std::pair{0,nnode-1}){
		//	std::cout<<"1\n1 "<<nnode<<'\n';
		//	return 0;
		//}
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	std::vector<int> dist(nnode,INT_MAX);
	std::queue<int> q;
	dist[0]=0;q.push(0);
	while(not q.empty()){
		int node=q.front();q.pop();
		auto const nextdist=dist[node]+1;
		if(nextdist<=3){
			for(int y:ad[node])if(dist[y]==INT_MAX){
				dist[y]=nextdist;
				q.push(y);
			}
		}
	}

	if(dist[nnode-1]<=3){
		// if there is an simple path, there must be a non simple path (length ==4, handled below),
		// or a simple path with length <=3.

		std::cout<<dist[nnode-1]<<'\n';

		std::vector<int> path;
		path.reserve(dist[nnode-1]+1);
		path.push_back(nnode-1);
		while(path.back()!=0)
			path.push_back(
					*std::find_if(
						begin(ad[path.back()]),end(ad[path.back()]),
						[&,nextdist=dist[path.back()]-1](int node){ return dist[node]==nextdist; }
						));
		assert(path.size()==(unsigned)dist[nnode-1]+1);

		std::for_each(path.rbegin(),path.rend(),[](int x){ std::cout<<x+1<<' '; });
		std::cout<<'\n';
		return 0;
	}

	// else: no simple path. min non simple path (1->nnode) len = 4

	auto iter=std::find(begin(dist),end(dist),2);
	if(iter!=end(dist)){
		auto const n2=int(iter-begin(dist));
		assert(dist[n2]==2);

		auto const n1=*std::find_if(
			begin(ad[n2]),end(ad[n2]),
			[&](int node){ return dist[node]==1; }
			);

		std::cout<<"4\n1 "<<n1+1<<' '<<n2+1<<" 1 "<<nnode<<'\n';
		return 0;
	}

	// else: no path len <= 4
	


	std::vector<char> vis(nnode);
	for(int c:ad[0]){
#ifdef LOCAL
		std::sort(begin(ad[c]),end(ad[c]));
#endif
		ad[c].erase(
				std::find(begin(ad[c]),end(ad[c]),0));
	}

	std::sort(begin(ad[0]),end(ad[0]),[&](auto a,auto b){ return ad[a].size()<ad[b].size(); });

	dist.assign(nnode,INT_MAX);

	for(int c:ad[0])if(not vis[c]){
		std::queue<int> q;
		assert(std::all_of(begin(dist),end(dist),[](auto x){ return x==INT_MAX; }));
		dist[c]=0;q.push(c);
		while(not q.empty()){
			int node=q.front();q.pop();
			auto const nextdist=dist[node]+1;
			for(int y:ad[node])if(dist[y]==INT_MAX){
				assert(y!=0);
				dist[y]=nextdist;
				if(nextdist==2){
					// found 0 -> c -> node -> y -(x)> c -(x)> nnode-1
					assert(not std::binary_search(begin(ad[c]),end(ad[c]),nnode-1));
					std::cout<<"5\n1 "<<c+1<<' '<<node+1<<' '<<y+1<<' '<<c+1<<' '<<nnode<<'\n';
					return 0;
				}
				q.push(y);
			}
		}

		// this is a clique. Mark as visited.
		for(int a:ad[c]){
			assert(not vis[a]);
			vis[a]=true;
			dist[a]=INT_MAX;
		}
		vis[c]=true;
		dist[c]=INT_MAX;
	}

#ifdef LOCAL
	for(int b:ad[0])
	for(int c:ad[b]){
		assert(c!=0);
		for(int d:ad[c]) if(d!=b)
			assert(std::binary_search(begin(ad[d]),end(ad[d]),b));
	}
#endif

	std::cout<<"-1\n";
}