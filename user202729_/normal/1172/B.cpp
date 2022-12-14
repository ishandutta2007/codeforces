#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

std::vector<std::vector<int>> ad;

int const MOD=998244353;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	ad.resize(n);
	for(int z=n,u,v;--z;){
		std::cin>>u>>v;
		ad[--u].push_back(--v);
		ad[v].push_back(u);
	}

	int out=n;
	for(int i=0;i<n;++i)
		for(int j=(int)ad[i].size();j>1;--j)
			out=out*(int64_t)j%MOD;

	std::cout<<out<<'\n';
}