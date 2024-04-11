#include<iostream>
#include<vector>


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,n_edge;
	std::cin>>n>>n_edge;

	std::vector<std::vector<int>> ad;
	ad.resize(n);
	std::vector<int> indeg(n);

	for(int _=n_edge;_--;){
		int u,v;std::cin>>u>>v;--u;--v;
		if(u>v)std::swap(u,v);
		ad[u].push_back(v);
		++indeg[v];
	}

	int64_t ans=0;
	for(int i=0;i<n;++i)
		ans+=indeg[i]*(int64_t)ad[i].size();
	std::cout<<ans<<'\n';

	int nquery;std::cin>>nquery;
	for(int _=nquery;_--;){
		int x;std::cin>>x;--x;
		// process int O(ad[i].size()) time
		for(int y:ad[x]){
			ans-=indeg[y]*(int64_t)ad[y].size();
			ad[y].push_back(x);
			--indeg[y];
			ans+=indeg[y]*(int64_t)ad[y].size();
		}

		ans-=indeg[x]*(int64_t)ad[x].size();
		indeg[x]+=ad[x].size();
		ad[x].clear();
		// ans+=indeg[x]*ad[x].size();

		std::cout<<ans<<'\n';
	}
}