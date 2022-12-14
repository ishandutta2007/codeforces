// time-limit: 2000
// problem-url: https://codeforces.com/contest/1615/problem/D

// C is probably some observation. Skip anyway
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

struct Edge2{int node; bool flip;};
struct CannotSatisfyError {};

std::vector<std::vector<Edge2>> add;
std::vector<char> data;
// dfs as usual, data is (-1: not visited/otherwise: visited)
void work(int node, bool color){
	assert(data[node]==-1); data[node]=color;
	for(auto [other, flip]: add[node]){
		if(data[other]<0){
			work(other, color^flip);
		}else{
			if((color^flip)!=data[other]){
				throw CannotSatisfyError {};
			}
		}
	}
}
		


void up(){
	int numNode; std::cin>>numNode;
	int numCondition; std::cin>>numCondition;
	struct Edge{int x, y, value /* -1 is undefined */;};
	std::vector<Edge> edges(numNode-1);

	add.clear(); add.resize(numNode);
	for(auto& [x, y, value]: edges){
		std::cin>>x>>y>>value;
		--x; --y;
		if(value>=0){
			add[x].push_back({y, __builtin_popcount(value)&1});
			add[y].push_back({x, __builtin_popcount(value)&1});
		}
	}

	for(int _=0; _<numCondition; ++_){
		int a; std::cin>>a; --a;
		int b; std::cin>>b; --b;
		int p; std::cin>>p;
		add[a].push_back({b, p});
		add[b].push_back({a, p});
	}
		
		


	data.assign(numNode, -1);
	try{
		for(int node=0; node<numNode; ++node)
			if(data[node]==-1)
				work(node, false);
	}catch(CannotSatisfyError){
		std::cout<<"NO\n";
		return;
	}

	std::cout<<"YES\n";
	for(auto& [x, y, value]: edges){
		std::cout<<x+1<<' '<<y+1<<' '<<
			(value>=0 ? value: data[x]^data[y])<<'\n';
	}
	
}