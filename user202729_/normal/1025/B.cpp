#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void for_each_prime_factors(int value, auto function){
	if(value%2u==0){
		value>>=__builtin_ctz(value);
		function(2);
	}
	for(int x=3;x*x<=value;x+=2) if(value%x==0){
		do value/=x; while(value%x==0);
		function(x);
	}
	if(value>1) function(value);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<std::array<int, 2>> pairs(number);
	for(auto & [first, sec]: pairs) std::cin>>first>>sec;

	std::set<int> candidates;
	for(auto y: pairs[0])
		for_each_prime_factors(y,[&](int x){candidates.insert(x);});

	for(auto prime: candidates){
		if(std::all_of(begin(pairs),end(pairs),[&](auto x){
			return std::any_of(begin(x),end(x),[&](auto y){ return y%prime==0; });
		})){
			std::cout<<prime<<'\n';
			return 0;
		}
	}
	std::cout<<"-1\n";
}