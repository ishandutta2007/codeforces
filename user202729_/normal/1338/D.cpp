// properly debugged. :sad:


#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// (
// chain: some black nodes such that the compressed tree is a chain and
// no two black nodes (on the chain) are adjacent
// value = chain length + number of (degree-2) of white nodes between black nodes
// )
//
// f[node] = max value of a separated chain from this node +whiteValue[node]
// returns {f[node], max f[strict descendant of node]}
//
// f[node]
//  = whiteValue[node]+ ( max g[child]-whiteValue[node]-value(node) ) +1
//  = max g[child]-value[node] +1
// g[node]=max G(child) where G(child)=max(f[child], g[child])
//
// update to answer: (maximum)
//  + node is white -> G child1 + G child2 - value node -2*whiteValue[node]
//  + node is black -> g child1 + g child2 -2 whiteValueInclusive[node] +1

int result; // for any chain

std::vector<std::vector<int>> add;

std::pair<int, int> work(int node, int par,
		int whiteValue // sum (degree-2) for all strict ancestor of this node
		){
	int f=1+whiteValue, g=INT_MIN;

	auto const valNode=(int)add[node].size()-2;
	auto const whiteValueInclusive=whiteValue+valNode;

	int max_gBefore=INT_MIN;
	for(auto child: add[node]) if(child!=par){
		auto const [fChild, gChild]=work(child, node, whiteValueInclusive);
		auto const GChild=std::max(fChild, gChild);

		// now g is maximum of G child before this child
		if(g!=INT_MIN) result=std::max(result,
			g+GChild - valNode-2*whiteValue);
		if(gChild!=INT_MIN) {
			f=std::max(f, gChild-valNode+1);
			if(max_gBefore!=INT_MIN) result=std::max(result,
				max_gBefore+gChild - 2*whiteValueInclusive+1);
		}

		g=std::max(g, GChild);
		max_gBefore=std::max(max_gBefore, gChild);
	}
	return {f, g};
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

	result=0;
	auto const [f, g]=work(0, -1, 0);
	std::cout<<std::max({f, g, result})<<'\n';
}