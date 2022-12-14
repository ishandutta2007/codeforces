#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<unsigned> values(number);
	for(auto & it: values) std::cin>>it;

	int result=0;
	for(int bit=0;bit<27;++bit) {
		auto modded=values;
		auto const mod=1u<<(bit+1);
		for(auto & it: modded) it=it%mod;
		std::sort(begin(modded),end(modded));

		int count=0;
		for(auto iterator=begin(modded); iterator!=end(modded);++iterator){
			auto const x=*iterator;

			auto left=((1u<<bit)-x)%mod, right=((2u<<bit)-x);
			assert(left!=right);

			auto curCount=std::lower_bound(begin(modded), iterator, right)-
					std::lower_bound(begin(modded), iterator, left);
			if(left>right) curCount+=iterator-begin(modded);
			assert(curCount>=0 and curCount<=iterator-begin(modded));
			count^=curCount;
		}
		result+=(count&1)<<bit;
	}
	std::cout<<result<<'\n';
}