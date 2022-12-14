// >.<
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int nnode;
std::vector<std::vector<int>> ad;

std::vector<int> sts,par;
int dd(int node,int par_node=-1){
	par[node]=par_node;
	sts[node]=1;
	for(int child:ad[node])if(child!=par_node){
		sts[node]+=dd(child,node);
	}
	return sts[node];
}

std::vector<std::vector<int64_t>> solve_mem;
int64_t solve(int a,int b,int adir,int bdir){
	assert(a!=b);
	assert(a!=adir);
	assert(b!=bdir);

	if(a<b){ std::swap(a,b); std::swap(adir,bdir); }
	auto& val=solve_mem[a][b];
	if(val!=0) return val;

	for(int ada:ad[a])if(ada!=adir) val=std::max(val,solve(ada,b,a,bdir));
	for(int adb:ad[b])if(adb!=bdir) val=std::max(val,solve(a,adb,adir,b));

	val+=(adir==par[a] ? sts[a] : nnode-sts[adir])*(bdir==par[b] ? sts[b] : nnode-sts[bdir]);
	assert(val>0);
	return val;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>nnode;
	ad.resize(nnode);
	for(int z=nnode;--z;){
		int u,v;std::cin>>u>>v;
		ad[--u].push_back(--v);
		ad[v].push_back(u);
	}

	sts.resize(nnode);
	par.resize(nnode);
	dd(0);

	int64_t out=0;
	solve_mem.resize(nnode);
	for(int r=1;r<nnode;++r) solve_mem[r].resize(r);
	for(int node=1;node<nnode;++node)
		out=std::max(out,solve(par[node],node,node,par[node]));

	std::cout<<out<<'\n';
}