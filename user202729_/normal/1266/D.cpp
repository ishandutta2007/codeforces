// ......

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<numeric>
#include<algorithm>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode,m;std::cin>>nnode>>m;

	std::vector<int64_t> outsum(nnode);

	for(int z=m;z--;){
		int u,v,d;std::cin>>u>>v>>d;
		--u;--v;
		if(u==v)continue;

		outsum[u]+=d;
		outsum[v]-=d;
	}

	std::vector<int> pos,neg;
	for(int u=0;u<nnode;++u){
		if(outsum[u]>0)
			pos.push_back(u);
		else if(outsum[u]<0)
			neg.push_back(u);
	}

	struct edge{
		int a,b;
		int64_t w;
	};
	std::vector<edge> edges;
	while(not pos.empty() and not neg.empty()){
		int u=pos.back(),v=neg.back();
		int64_t &du=outsum[u],&dv=outsum[v];
		if(du==0){
			pos.pop_back();continue;
		}
		if(dv==0){
			neg.pop_back();continue;
		}
		assert(du>0 and dv<0);

		auto delta=std::min(du,-dv);
		edges.push_back({u,v,delta});
		du-=delta;
		dv+=delta;
		assert(du>=0 and dv<=0);
	}

	std::cout<<edges.size()<<'\n';
	for(auto [a,b,w]:edges)
		std::cout<<a+1<<' '<<b+1<<' '<<w <<'\n';
}