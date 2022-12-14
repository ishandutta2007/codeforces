#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t p; int k;
	std::cin>>p>>k;
	std::vector<int> result;
	while(p){
		auto mod=p%(-k); p/=-k;
		if(mod<0){ mod+=k; ++p; }
		result.push_back(mod);
	}
	std::cout<<(int)result.size()<<'\n';
	for(auto it: result) std::cout<<it<<' ';
	std::cout<<'\n';
}