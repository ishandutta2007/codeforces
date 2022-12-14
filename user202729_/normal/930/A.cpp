// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> par(number), depth(number), countDepth(number);
	for(int i=1;i<number;++i) {
		std::cin>>par[i];
		--par[i];
		depth[i]=depth[par[i]]+1;
		countDepth[depth[i]]+=1;
	}
	std::cout<<std::count_if(begin(countDepth),end(countDepth),[&](auto x){
		return x&1;
	})+1<<'\n';
}