#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>
#include<map>

std::vector<std::map<int,int>> ad; // x -> value

std::vector<int> path;

template<bool store> // include first x parameter, include leaf, exclude par
int leaf(int x,int par){
	if(store)
		path.push_back(x);

	assert(par<0 or ad[x].count(par));
	if(par<0){
		if(ad[x].empty())
			return x;
	}else{
		if(ad[x].size()==1){
			assert(ad[x].begin()->first==par);
			return x;
		}
	}

	auto iter=ad[x].begin();
	while(iter->first==par)++iter;
	return leaf<store>(iter->first,x);
}

std::vector<int> pathleaf(int x,int par){
	path.clear();
	leaf<true>(x,par);
	return std::move(path);
}

void subpath(std::vector<int> const& p1,int w){
	if(w==0)return;
	for(unsigned x=1;x<p1.size();++x){
		int a=p1[x-1];
		int b=p1[x];
		ad[a].at(b)-=w;
		ad[b].at(a)-=w;
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	// note: ops are commutative
	ad.resize(n);
	for(int z=n;--z;){
		int u,v;std::cin>>u>>v;
		ad[--u].emplace(--v,0);
		ad[v].emplace(u,0);
	}

	for(int i=0;i<n;++i)if(ad[i].size()==2){
		std::cout<<"NO\n";
		return 0;
	}

	std::cout<<"YES\n";
	return 0;
}