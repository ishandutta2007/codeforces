// intended solution
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge; std::cin>>numNode>>numEdge;

	std::vector<std::vector<int>> add(numNode), reverse(numNode);
	for(int _=0; _<numEdge; ++_){
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		add[first].push_back(sec); reverse[sec].push_back(first);
	}

	std::vector<int> deletedBy(numNode, -1);
	//std::vector<int> baseDelete;
	for(int node=0; node<numNode; ++node){
		if(deletedBy[node]<0){
			deletedBy[node]=node;
			for(auto other: add[node])
				if(deletedBy[other]<0)
					deletedBy[other]=node;
		}
	}

	//std::vector<char> restored(numNode);
	std::vector<char> chosen(numNode);
	for(auto node=numNode; node--;) if(deletedBy[node]==node){
		//restored[node]=true;
		//for(auto other: add[node])
		//	if(deletedBy[other]==node)
		//		restored[other]=true;

		if(std::none_of(begin(reverse[node]), end(reverse[node]),[&](auto other){
			return chosen[other];
		})){
			chosen[node]=true;
			for(auto other: add[node]) assert(not chosen[other]);
		}
	}

	std::cout<<std::accumulate(begin(chosen), end(chosen), 0)<<'\n';
	for(int node=0; node<numNode; ++node)
		if(chosen[node]) std::cout<<node+1<<' ';
	std::cout<<'\n';
}