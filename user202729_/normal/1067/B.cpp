#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

std::vector<std::vector<int>> ad;

void add_edge(int u,int v){
	ad[u].push_back(v);
	ad[v].push_back(u);
}

void read_tree(int nnode){
	ad.resize(nnode);
	for(int z=nnode;--z;){
		int u,v;
		std::cin>>u>>v;
		--u;--v;
		add_edge(u,v);
	}
}

std::vector<int> par;

struct furthest_edge_t { int node,dist; };
template<bool cpu_par>
furthest_edge_t dd(int x,int parx){
	if(cpu_par) par[x]=parx;
	furthest_edge_t out{x,0};
	for(int y:ad[x]){
		if(y==parx)
			continue;

		auto [node,dist]=dd<cpu_par>(y,x);
		++dist;
		if(dist>out.dist) out={node,dist};
	}
	return out;
}

bool check(int node,int k,int par=-1){
	if(k==0)return ad[node].size()==1;
	if((ad[node].size()-(par>=0))<3) return false;
	for(int x:ad[node]) if(x!=par)
		if(not check(x,k-1,node)) return false;
	return true;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,k;std::cin>>n>>k;
	read_tree(n);

	par.resize(n);
	auto [anyleaf,_]=dd<false>(0,-1);
	auto [anotherleaf,dist]=dd<true>(anyleaf,-1);
	if(dist!=k*2){ std::cout<<"No\n"; return 0; }

	int x=anotherleaf;
	for(int z=k;z--;) x=par[x];
	std::cout<<( check(x,k) ? "Yes\n" : "No\n" );
}