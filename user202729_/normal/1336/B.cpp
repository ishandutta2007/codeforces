#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	std::array<std::vector<int>, 3> weights;
	for(auto & it: weights){int size; std::cin>>size;
		it.resize(size+1);
		it.back()=INT_MAX;
	}
	for(auto & it: weights) {
		std::for_each(begin(it),end(it)-1, [&](auto& weight){ std::cin>>weight; });
		std::sort(begin(it),end(it)-1);
	}

	auto result=INT64_MAX;
	auto const distance=[&](auto first, auto sec, auto third){
		return
			int64_t(first-sec)*(first-sec)+
			int64_t(third-sec)*(third-sec)+
			int64_t(first-third)*(first-third);
	};
	for(int mid=0;mid<3;++mid) 
		for(int less=0;less<3;++less) if(less!=mid){
			auto const greater=3-less-mid;
			auto midIterator=weights[mid].begin(), lessIterator=weights[less].begin(),
				 greaterIterator=weights[greater].begin();

			while(*midIterator!=INT_MAX){
				while(lessIterator[1]<=*midIterator) ++lessIterator;
				while(*greaterIterator<*midIterator) ++greaterIterator;
				if(*greaterIterator==INT_MAX) break;

				result=std::min(result, distance(*lessIterator,*midIterator,*greaterIterator));
				++midIterator;
			}
		}
	std::cout<<result<<'\n';
}