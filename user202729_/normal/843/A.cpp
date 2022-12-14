#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> values(number);
	for(auto& it: values) std::cin>>it;
	std::vector<int> sorted=values; std::sort(begin(sorted), end(sorted));
	for(auto& it: values) it=int(std::lower_bound(begin(sorted), end(sorted), it)-sorted.begin());

	std::vector<char> visited(number);
	std::vector<std::vector<int>> chains;
	for(int node=0; node<number; ++node){
		if(not visited[node]){
			std::vector<int> chain;
			int y=node;
			do{
				chain.push_back(y);
				y=values[y];
			}while(y!=node);
			std::sort(begin(chain), end(chain));
			for(auto it: chain) visited[it]=true;
			chains.push_back(std::move(chain));
		}
	}

	std::cout<<chains.size()<<'\n';
	for(auto& chain: chains){
		std::cout<<chain.size();
		for(auto it: chain) std::cout<<' '<<it+1;
		std::cout<<'\n';
	}

}