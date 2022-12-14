// :(

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<int64_t> add;

int64_t countIndependentSubsets(int64_t drop){ // count the number of independent subsets being a subset of (~drop)
	auto node=__builtin_ctzll(~drop);
	if(node==(int)add.size()) return 1;

	// case 1: there's no node adjacent to `node` int the independent subset
	auto result=2*countIndependentSubsets(drop|(1LL<<node)|add[node]);

	// case 2: there's such a node. Let it be `other`
	for(auto temp=add[node], drop1=drop; temp; temp-=temp&-temp){
		auto other=__builtin_ctzll(temp);
		assert(other!=node);
		if(not (
					drop1>>other&1
					)){
			// consider the case where other is the first vertex int the independent set
			result+=countIndependentSubsets(
					drop1|(1LL<<other)|add[other]
					);
			drop1|=1LL<<other;
		}
	}
	return result;
}

bool bipartite;
std::vector<char> side; // -1: unvisited
void work(int node){ // DFS. Used to count the number of components and check if the graph is bipartite.
	assert(side[node]>=0);
	for(auto temp=add[node]; temp; temp-=temp&-temp){
		auto const other=__builtin_ctzll(temp);
		if(side[other]<0){
			side[other]=not side[node];
			work(other);
		} else if(side[other]==side[node])
			bipartite=false;
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numEdge;
	std::cin>>number>>numEdge;
	if(numEdge<3){
		std::cout<<"0\n";
		return 0;
	}

	add.resize(number);
	for(int _=0;_<numEdge;++_) {
		int first, sec; std::cin>>first>>sec;
		add[--first]|=(int64_t)1<<--sec;
		add[sec]|=(int64_t)1<<first;
	}

	std::array<int64_t, 8> result;
	result[0]=0;
	result[7]=1LL<<number; // all configurations are valid
	result[3]=result[6]=countIndependentSubsets(0);

	bipartite=true;
	int numComponents=0;
	int numSingleComponents=0; // number of components with only 1 node
	side.assign(number, -1);
	for(int node=0;node<number;++node) if(side[node]<0){
		++numComponents;
		side[node]=0;
		if(add[node]==0) ++numSingleComponents;
		else work(node);
	}

	result[1]=result[4]=1LL<<numSingleComponents; // all 0 or all 1 configuration, except for the single components

	result[5]=1LL<<numComponents;
	result[2]=bipartite ? 1LL<<numComponents : 0;

	// now result[mask]=number of configuration with edge values all inside mask

	for(int bit=8; bit>>=1;)
		for(int index=0;index<(int)result.size();++index) 
			if(index&bit) result[index]-=result[index-bit];

	std::cout<<result[7]<<'\n';
}