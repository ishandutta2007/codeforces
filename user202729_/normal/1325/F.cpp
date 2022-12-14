// probably incorrect algorithm. Please hack this solution if possible (and if it pass the existing tests).

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;

std::vector<int> par, depth;
std::vector<char> visited;
void work(int node, int parNode, int depthNode){
	par[node]=parNode; depth[node]=depthNode;
	assert(not visited[node]);
	visited[node]=true;
	for(auto child: add[node]) if(not visited[child]){
		//add[child].erase(std::find(begin(add[child]),end(add[child]), node));
		work(child, node, depthNode+1);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge; std::cin>>numNode>>numEdge;
	add.resize(numNode);
	while(numEdge--){
		int first, sec; std::cin>>first>>sec;
		add[--first].push_back(--sec);
		add[sec].push_back(first);
	}

	auto x=(int)std::sqrt(numNode);
	while(x*x<numNode) ++x;

	{
		std::vector<int> vertices(numNode);
		std::iota(begin(vertices),end(vertices), 0);
		std::sort(begin(vertices),end(vertices),[&](auto first, auto sec){
			return add[first].size()<add[sec].size();
		});
		std::vector<char> removed(numNode);
		std::vector<int> independentSet;
		for(auto node: vertices)if(not removed[node]){
			for(auto other: add[node]) removed[other]=true;
			independentSet.push_back(node);
		}

		if((int)independentSet.size()>=x){
			independentSet.resize(x);
			std::cout<<"1\n";
			for(auto node: independentSet) std::cout<<node+1<<' ';
			std::cout<<'\n';
			return 0;
		}
	}

	visited.assign(numNode, false);
	par.resize(numNode); depth.resize(numNode);
	work(0, -1, 0);

	for(int node=0;node<numNode;++node) for(auto other: add[node]){
		if(depth[node]-depth[other]+1>=x){
			std::cout<<"2\n";
			std::cout<<depth[node]-depth[other]+1<<'\n';
			while(true){
				std::cout<<node+1<<' ';
				if(node==other) break;
				node=par[node];
			}
			std::cout<<'\n';
			return 0;
		}
	}

	return 1;
}