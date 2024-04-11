#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numDay; std::cin>>numDay;
	std::vector<int> numMarkAbove(numDay);
	for(auto & it: numMarkAbove) std::cin>>it;

	auto minNumOtherMarks=numMarkAbove;
	for(auto index=numDay;--index;){
		minNumOtherMarks[index-1]=std::max(minNumOtherMarks[index-1], 
				minNumOtherMarks[index]-1);
	}
	for(auto index=1; index<numDay;++index){
		minNumOtherMarks[index]=std::max(minNumOtherMarks[index], 
				minNumOtherMarks[index-1]);
	}

	std::cout<<std::accumulate(begin(minNumOtherMarks),end(minNumOtherMarks),
			-std::accumulate(begin(numMarkAbove),end(numMarkAbove),(int64_t)0)
			)<<'\n';
}