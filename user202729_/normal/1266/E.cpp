// READ THE PROBLEM STATEMENTS CAREFULLY!!!
// I expect that I will lose rating because it's hard to solve F. (BLAME UNBALANCED CONTEST)
// (That having said, I made wrong assumptions while solving D so it becomes a harder problem,
// it's also my fault. Of course.)
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<map>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntype;std::cin>>ntype;

	std::vector<std::map<int,int>> milestone(ntype);
	std::vector<int> totalreward(ntype),goal(ntype);
	int64_t out=0;
	
	for(int i=0;i<ntype;++i){
		std::cin>>goal[i];
		out+=goal[i];
	}

	auto const changetr=[&](int type,int delta){
		out-=std::max(0,goal[type]-totalreward[type]);
		totalreward[type]+=delta;
		out+=std::max(0,goal[type]-totalreward[type]);
	};

	int nquery;std::cin>>nquery;
	for(int z=nquery;z--;){
		int source,time,target;std::cin>>source>>time>>target;
		--source;

		auto& x=milestone[source][time];
		if(x!=0) changetr(x-1, -1);

		x=target;
		if(x!=0) changetr(x-1, 1);

		std::cout<<out<<'\n';
	}
}