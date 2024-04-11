#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;
std::vector<char> visited;

int // subtreeSize 
work(int node){
	assert(not visited[node]);
	visited[node]=true;
	int result=1;
	for(auto other: add[node]) if(not visited[other]){
		result+=work(other);
	}
	return result;
}


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge; std::cin>>numNode>>numEdge;
	add.resize(numNode);
	for(int _=0;_<numEdge;++_) {
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		add[first].push_back(sec);
		add[sec].push_back(first);
	}
	visited.resize(numNode);

	int numSatisfied=0;
	for(int node=0;node<numNode;++node) if(not visited[node]){
		numSatisfied+=work(node)-1;
	}

	std::cout<<numEdge-numSatisfied<<'\n';
}