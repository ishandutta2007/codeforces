#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode; std::cin>>numNode;
	std::vector<int> parent(numNode); 
	for(int node=1;node<numNode;++node) {
		std::cin>>parent[node];
		--parent[node];
	}

	std::vector<int> value(numNode);
	std::vector<std::vector<int>> conditions(numNode); // condition[x]=t -> there's some y such that ax+ay=t
	std::cin>>value[0];
	for(int node=1;node<numNode;++node) {
		std::cin>>value[node];
		if(value[node]>=0){
			assert(value[parent[node]]==-1);
			auto const b=value[parent[parent[node]]];
			if(b>value[node]){
				std::cout<<"-1\n"; return 0;
			}
			conditions[parent[node]].push_back(value[node]-b);
		}
	}
	int64_t result=0;
	for(auto const& it: conditions) if(not it.empty()){
		int minimum=INT_MAX;
		for(auto condition: it) { result+=condition; minimum=std::min(minimum, condition); }
		result-=minimum*int64_t(it.size()-1);
	}
	std::cout<<result+value[0]<<'\n';
}