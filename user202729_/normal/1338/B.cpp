#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;
std::vector<char> color;
void work(int node, int par){
	for(auto child: add[node]) if(child!=par){
		color[child]=not color[node];
		work(child, node);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode; std::cin>>numNode;
	add.resize(numNode);
	for(int _=0;_<numNode-1;++_) {
		int first, sec; std::cin>>first>>sec;
		add[--first].push_back(--sec);
		add[sec].push_back(first);
	}

	color.resize(numNode);
	work(0, -1);
	std::array<bool, 2> haveLeafWithColor{};
	std::vector<char> adjacentToLeaf(numNode);
	int numLeaf=0;
	for(int node=0;node<numNode;++node) if(add[node].size()==1){
		haveLeafWithColor[color[node]]=true;
		adjacentToLeaf[add[node][0]]=true;
		++numLeaf;
	}
	std::cout<<(haveLeafWithColor[0] and haveLeafWithColor[1] ? "3 ": "1 ")
		<<numNode-1-numLeaf+std::accumulate(begin(adjacentToLeaf),end(adjacentToLeaf), 0)
		<<'\n';



}