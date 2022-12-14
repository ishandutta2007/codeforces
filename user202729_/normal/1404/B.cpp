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

std::vector<std::vector<int>> add;
struct Result{
	int maxNode, maxDepth;
	int targetDepth; // -1 if not found
};
Result work(int node, int par, int target){
	Result result{node, 0, node==target ? 0: -1};
	for(auto other: add[node]) if(other!=par){
		Result tmp=work(other, node, target);
		tmp.maxDepth++;
		if(tmp.targetDepth>=0) result.targetDepth=tmp.targetDepth+1;
		if(tmp.maxDepth>result.maxDepth){
			result.maxNode=tmp.maxNode;
			result.maxDepth=tmp.maxDepth;
		}
	}
	return result;
}

void up(){
	int n, a, b, da, db;
	std::cin>>n>>a>>b>>da>>db;
	--a;--b;
	add.clear(); add.resize(n);
	for(int i=0; i<n-1; ++i){
		int u, v; std::cin>>u>>v;
		--u;--v;
		add[u].push_back(v); add[v].push_back(u);
	}
	if(work(a, -1, b).targetDepth<=da){
		std::cout<<"Alice\n";
		return;
	}
	auto const diameter=work(work(0, -1, -1).maxNode, -1, -1).maxDepth;
	std::cout<<(std::min(diameter, db)>2*da ? "Bob\n": "Alice\n");
}