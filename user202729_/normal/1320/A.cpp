#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	struct item{ int count; int64_t sum; };
	std::map<int, item> items;
	for(int index=0;index<number;++index) {
		int value; std::cin>>value; value-=index;
		auto& x=items[value];
		++x.count; x.sum+=index;
	}
	int64_t result=0;
	for(auto [val, something]: items){
		auto[count, sum]=something;
		result=std::max(result, sum+val*(int64_t)count);
	}
	std::cout<<result<<'\n';
}