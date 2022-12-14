#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> values(number);
	for(auto & it: values) std::cin>>it;
	std::sort(begin(values),end(values));
	auto out=begin(values);
	for(auto it: values)
		if(std::all_of(begin(values),out,[&](auto x){return it%x!=0;}))
			*out++=it;
	std::cout<<(out-begin(values))<<'\n';
}