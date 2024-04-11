#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numCell, numColor; std::cin>>numCell>>numColor;
	std::vector<int> lens(numColor);for(auto & it: lens) std::cin>>it;
	if(std::accumulate(begin(lens),end(lens), (int64_t)0)<numCell){
		// there must be an uncolored cell
		std::cout<<"-1\n";
		return 0;
	}
	for(int index=0;index<numColor;++index) if(numCell-lens[index]<index){
		// some color <index must be completely covered
		std::cout<<"-1\n";
		return 0;
	}

	std::vector<int> result(numColor);
	std::iota(begin(result),end(result), 0);
	for(int last=numCell, index=numColor; index--;){
		result[index]=std::max(result[index], last-lens[index]);
		last=result[index];
	}
	for(auto it: result) std::cout<<it+1<<' ';
	std::cout<<'\n';
}