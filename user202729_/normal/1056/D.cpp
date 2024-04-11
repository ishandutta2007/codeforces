#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<int> subtreeSize; // -1
std::vector<std::vector<int>> add;

int work(int node){
	for(auto child: add[node])
		subtreeSize[node]+=work(child);
	return subtreeSize[node]=std::max(1, subtreeSize[node]);
}
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode; std::cin>>numNode;
	add.resize(numNode);
	for(int node=1;node<numNode;++node) {
		int par; std::cin>>par;
		add[--par].push_back(node);
	}
	subtreeSize.resize(numNode);
	work(0);
	std::sort(begin(subtreeSize),end(subtreeSize));
	for(auto item: subtreeSize) std::cout<<std::max(1, item)<<' ';
	std::cout<<'\n';
}