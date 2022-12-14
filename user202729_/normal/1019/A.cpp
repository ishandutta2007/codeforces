#ifndef LOCAL
#define NDEBUG
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nvoter,nparty;
	std::cin>>nvoter>>nparty;
	std::vector<std::vector<int>> changecosts(nparty);
	for(int z=nvoter;z--;){
		int party,cost;std::cin>>party>>cost;
		changecosts[--party].push_back(cost);
	}

	for(auto& ci:changecosts)
		std::sort(begin(ci),end(ci));

	std::vector<int> rem;
	rem.reserve(nvoter);
	int64_t out=INT64_MAX;
	for(int nvoteget=std::max(1,(int)changecosts[0].size());nvoteget<=nvoter;++nvoteget){
		int64_t cost=0;
		rem.clear();

		for(unsigned x=1;x<changecosts.size();++x){
			auto iter=end(changecosts[x])-std::min((int)changecosts[x].size(),nvoteget-1);
			rem.insert(end(rem),iter,end(changecosts[x]));
			cost=std::accumulate(begin(changecosts[x]),iter,cost);
		}
		// we need >= nvoteget votes <=> rem.size() <= nvoter-nvoteget
		if((int)rem.size()>nvoter-nvoteget){
			auto iter=end(rem)-(nvoter-nvoteget);
			std::nth_element(begin(rem),iter,end(rem));
			cost=std::accumulate(begin(rem),iter,cost); // add min rest of them
		}
		out=std::min(out,cost);
	}
	std::cout<<out<<'\n';
}