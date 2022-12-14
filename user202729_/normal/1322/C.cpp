// still not very rigorously proven :(
// (nice. Perhaps this is an implementation error rather than an algorithm error)

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--){
		int numNodeHalf, numEdge; std::cin>>numNodeHalf>>numEdge;
		struct RightNode{
			int64_t value;
			std::vector<int> add;
		};
		std::vector<RightNode> rightNodes(numNodeHalf);
		for(auto &[value, add]: rightNodes)
			std::cin>>value;

		for(int _=0;_<numEdge;++_) { // *
			int first, sec; std::cin>>first>>sec;--first;--sec;
			rightNodes[sec].add.push_back(first);
		}

		std::map<std::vector<int>, int64_t> totalValue;
		for(auto &[value, add]: rightNodes){
			if(not add.empty()){
				std::sort(begin(add),end(add));
				totalValue[std::move(add)]+=value;
			}
		}
		rightNodes.clear();

		int64_t result=0;
		for(auto const& [add, value]: totalValue)
			result=std::gcd(result, value);
		std::cout<<result<<'\n';
	}
}