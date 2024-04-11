#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;

std::vector<int> values;

int // numStrict descendant
work(int node, int depth // depth[root]=0
		, int par){
	int result=0;
	for(auto child: add[node]) if(child!=par){
		result+=work(child,  depth+1, node)+1;
	}
	values.push_back(depth-result);
	return result;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, k; std::cin>>numNode>>k;
	add.resize(numNode);
	for(auto _=numNode;--_;){
		int first, sec; std::cin>>first>>sec;
		add[--first].push_back(--sec);
		add[sec].push_back(first);
	}

	values.reserve(numNode);
	work(0, 0, -1);
	auto const iterator=end(values)-k;
	std::nth_element( begin(values), iterator, end(values));
	std::cout<<std::accumulate(iterator, end(values),(int64_t)0)<<'\n';
}