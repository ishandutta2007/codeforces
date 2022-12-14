// easy enough...
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<char> color;
struct Edge{ int node, index; };
std::vector<std::vector<Edge>> add;
std::vector<int> par;

struct OddCycle{ int node, ancestor; };
OddCycle oddCycle;

std::vector<int> value;
std::vector<int64_t> edgeValue;

void work(int node, int colorNode){
	assert(color[node]==-1);
	color[node]=colorNode;
	for(auto [other, edgeIndex]: add[node]){
		if(color[other]>=0) {
			if(color[other]==colorNode and oddCycle.node<0) // only need to find one odd length cycle, and ancestor must be the vertex nearer to the root
				oddCycle={node, other};
			continue;
		}
		par[other]=node;

		work(other, not colorNode);

		int64_t curValueOther=0;
		for(auto [_, edgeIndex]: add[other]) curValueOther+=edgeValue[edgeIndex];
		assert((value[other]-curValueOther)%2==0);  // since edgeValue is initialized to 1
		edgeValue[edgeIndex]+=value[other]-curValueOther;
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge; std::cin>>numNode>>numEdge;
	value.resize(numNode);
	for(auto & it: value) std::cin>>it;
	add.resize(numNode);
	for(int edgeIndex=0;edgeIndex<numEdge;++edgeIndex) {
		int first, sec; std::cin>>first>>sec;
		add[--first].push_back({--sec, edgeIndex});
		add[sec].push_back({first, edgeIndex});
	}

	color.resize(numNode, -1);
	par.resize(numNode);
	edgeValue.assign(numEdge, 1);

	oddCycle={-1, -1};
	par[0]=-1;
	work(0, 0);
	if(oddCycle.node>=0){
		std::cout<<"YES\n";

		auto const [node, ancestor]=oddCycle;
		int64_t curValueRoot=0;
		for(auto [_, edgeIndex]: add[0]) curValueRoot+=edgeValue[edgeIndex];
		auto delta=value[0]-curValueRoot; assert(delta%2==0);
		if(color[ancestor]==color[0]) delta=-delta;

		{
			auto curDelta=delta;
			for(int tmp=ancestor; tmp!=0; tmp=par[tmp]){
				edgeValue[
					std::find_if(begin(add[tmp]),end(add[tmp]), [&](auto edge){ return edge.node==par[tmp]; })
						->index]+=curDelta;
				curDelta=-curDelta;
			}
		}

		{
			auto curDelta=delta/2;
			for(int tmp=node; tmp!=ancestor; tmp=par[tmp]){
				edgeValue[
					std::find_if(begin(add[tmp]),end(add[tmp]), [&](auto edge){ return edge.node==par[tmp]; })
						->index]+=curDelta;
				curDelta=-curDelta;
			}
			edgeValue[
				std::find_if(begin(add[node]),end(add[node]), [&](auto edge){ return edge.node==ancestor; })
					->index]-=delta/2;
		}

		

		for(auto it: edgeValue) std::cout<<it<<'\n';

		return 0;
	}

	std::array<int64_t, 2> sumColor{};
	for(int node=0;node<numNode;++node) sumColor[color[node]]+=value[node];
	if(sumColor[0]!=sumColor[1]){
		std::cout<<"NO\n";
		return 0;
	}

	std::cout<<"YES\n";
	for(auto it: edgeValue) std::cout<<it<<'\n';
}