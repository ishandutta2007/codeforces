#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<std::vector<int>> result;
	while(number>4){
		for(int i=0; i<number-2; ++i){
			if(i+1==number-2){
				result.push_back({number-1, number-2, i});
				result.push_back({number-1, number-2, 0});
			}else{
				result.push_back({number-1, i, number-2, i+1});
			}
		}
		number-=2;
	}
	if(number==4){
		for(int i=0; i<4; ++i)
			result.push_back({i,(i+1)%4,(i+2)%4});
	}else{
		assert(number==3);
		result.push_back({0, 1, 2});
		result.push_back({0, 1, 2});
	}

	std::cout<<result.size()<<'\n';
	for(auto const& it: result){
		std::cout<<it.size()<<' ';
		for(auto a: it) std::cout<<a+1<<' ';
		std::cout<<'\n';
	}
}