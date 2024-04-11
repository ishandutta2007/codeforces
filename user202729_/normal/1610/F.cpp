// time-limit: 1000
// problem-url: https://codeforces.com/contest/1610/problem/F

// at least debug is fast

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode; std::cin>>numNode;
	int numEdge; std::cin>>numEdge;

	struct Edge{int node, edgeIndex;};
	std::array<std::vector<Edge>, 2> match;
	match[0].resize(numNode, {INT_MIN, INT_MIN});
	match[1].resize(numNode, {INT_MIN, INT_MIN});

	// if there's edge u  v with edge 1:
	// match[0][u] = {v, index}
	// match[0][v] = {u, index xor M}
	int const M=1<<31;

	std::vector<std::array<int, 2>> rewrite;
	// rewrite {a, b}: a is discarded, b is kept in match

	for(int edgeIndex=0; edgeIndex<numEdge; ++edgeIndex){
		int i; std::cin>>i; --i;
		int j; std::cin>>j; --j;
		int weight; std::cin>>weight;

		auto& m=match[weight-1];
		if(m[i].node>=0){
			auto [t, edgeIndex1]=m[i];
			assert(std::cerr<<"remove"<<i+1<<' '<<t+1<<'\n');
			rewrite.push_back({edgeIndex1, edgeIndex xor M});
			m[i]={INT_MIN, INT_MIN}; i=t;

			if(i==j){
				m[j]={INT_MIN, INT_MIN};
				continue;
			}
		}

		if(m[j].node>=0){
			auto [t, edgeIndex1]=m[j];
			assert(std::cerr<<"remove"<<j+1<<' '<<t+1<<'\n');
			rewrite.push_back({edgeIndex1, edgeIndex});
			m[j]={INT_MIN, INT_MIN}; j=t;

			if(i==j){
				m[j]={INT_MIN, INT_MIN};
				continue;
			}
		}

		assert(std::cerr<<"add"<<i+1<<' '<<j+1<<'\n');
		m[i]={j, edgeIndex}; m[j]={i, edgeIndex xor M};
	}

	std::cout<<std::count_if(begin(match[0]), end(match[0]), [&](auto const& it){
		return it.node!=INT_MIN;
	})<<'\n';

	std::vector<char> value(numEdge);

	// handle the paths
	for(int node=0; node<numNode; ++node)
	if((match[0][node].node!=INT_MIN) xor (match[1][node].node!=INT_MIN)){
		int p=node;
		while(true){
			auto const matchIndex=match[1][p].node!=INT_MIN;
			auto [next, edgeIndex]=match[matchIndex][p];
			if(next==INT_MIN) break;

			value[edgeIndex&~M]=bool(edgeIndex&M);
			match[matchIndex][p]=match[matchIndex][next]={INT_MIN, INT_MIN};
			p=next;
		}
	}

	// handle the cycles
	for(int node=0; node<numNode; ++node)
	if(match[0][node].node!=INT_MIN){
		int p=node;
		while(true){
			auto const matchIndex=match[1][p].node!=INT_MIN;
			auto [next, edgeIndex]=match[matchIndex][p];
			if(next==INT_MIN) break;

			value[edgeIndex&~M]=bool(edgeIndex&M);
			match[matchIndex][p]=match[matchIndex][next]={INT_MIN, INT_MIN};
			p=next;
		}
	}

	

	for(int index=(int)rewrite.size(); index--;){
		auto [a, b]=rewrite[index];
		value[a&~M]=value[b&~M] xor ((a&M)!=(b&M));
	}

	for(auto x: value) std::cout<<char(x+'1');
	std::cout<<'\n';
}