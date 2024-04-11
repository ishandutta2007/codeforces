// why are there so many graph problems

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;
std::vector<char> visited;
std::vector<int> weight;

struct result{int sumWeight, maximumWeight;};

result work(int node){
	assert(not visited[node]);
	visited[node]=true;
	result out{weight[node], weight[node]};
	for(auto other: add[node]) if(not visited[other]){
		auto [subsum, submaximum]=work(other);
		out.sumWeight=out.sumWeight + subsum;
		out.maximumWeight=std::max(out.maximumWeight, submaximum);
	}
	return out;
}





int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numQuery; std::cin>>number>>numQuery;
	std::vector<int> value(number);
	int maximum=0;
	for(auto & it: value){
		std::cin>>it;
		maximum=std::max(maximum, it);
	}
	assert(numQuery==0);

	auto const numNode=maximum+1;
	add.resize(numNode);

	weight.resize(numNode);
	for(auto it: value) ++weight[it];

	std::vector<int> span(number);
	//span[left] = right: all elements in left... right are connected
	std::vector<std::pair<int, int>> spanValue(maximum+1,
			{-1, -1});
	for(int index=0;index<number;++index) {
		auto& [a, b]=spanValue[value[index]];
		if(a<0) a=index;
		b=index;
	}

	for(auto [a, b]: spanValue) if(a>=0)
		span[a]=std::max(span[a], b);
	spanValue.clear();

	for(int left=0;left<number;++left) {
		if(span[left]>left){
			add[value[left]].push_back(value[left+1]);
			add[value[left+1]].push_back(value[left]);
		}
		if(left+1!=number)
			span[left+1]=std::max(span[left+1], span[left]);
	}


	visited.resize(numNode);
	int result=0;
	for(int node=0;node<numNode;++node) if(not visited[node]){
		auto [sumWeight, maximumWeight]=work(node);
		result+=sumWeight-maximumWeight;
	}
	std::cout<<result<<'\n';
}