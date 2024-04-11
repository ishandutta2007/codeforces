// Why couldn't I solve this problem in the contest... it's easy enough.

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<iostream>

std::vector<int> pair;
std::vector<std::pair<int,int>> pairs;
std::vector<char> val;

template<bool v>
void dd(int x){
	if(val[x]>=0){
		assert(val[x]==v);
		return;
	}
	val[x]=v;
	for(int y:{x^1,pair[x]})
		dd<!v>(y);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	pairs.resize(n);
	pair.resize(2*n);
	for(int i=0;i<n;++i){
		auto& [a,b]=pairs[i];
		std::cin>>a>>b;--a;--b;
		pair[a]=b;pair[b]=a;
	}

	val.resize(2*n,-1);
	for(int i=0;i<n*2;++i)
		if(val[i]<0)
			dd<true>(i);
	for(auto [a,b]:pairs)
		std::cout<<val[a]+1<<' '<<val[b]+1<<'\n';
}