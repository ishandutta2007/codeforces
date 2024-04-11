/*
 * square root decomposition idea is obvious.
 * need a bit of time to figure out binary search => divide and conquer.
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> ad;

void dd_remove_paredge(int x){
	for(int y:ad[x]){
		std::swap(*std::find(begin(ad[y]),end(ad[y]),x), ad[y].back());
		ad[y].pop_back();
		dd_remove_paredge(y);
	}
}

int nnode_path;

struct solve_result{
	int npath,nnode_rootpath /* partial path (nnode < nnode_path) with one endpoint at root. If root is a
	part of another path, then 0 */;

	bool operator<(solve_result x)const{
		return npath!=x.npath ? npath<x.npath : nnode_rootpath<x.nnode_rootpath;
	} // larger is better
};

solve_result solve_impl(int x){
	int max1=0,max2=0; // of nnode_rootpath of children
	int child_npath=0;
	for(int y:ad[x]){
		auto [npath,nnode_rootpath]=solve_impl(y);
		child_npath+=npath;
		if(nnode_rootpath>max2){
			max2=nnode_rootpath;
			if(max2>max1) std::swap(max2,max1);
		}
	}

	solve_result out{child_npath,max1+1};
	assert(max1<nnode_path);
	assert(max2<=max1);
	if(max1+1==nnode_path or max1+max2+1>=nnode_path)
		out={child_npath+1,0};
	return out;
}

int solve(int nnode_path_){ // = max npath
	nnode_path=nnode_path_;
	return solve_impl(0).npath;
}

std::vector<int> out; // out[x] = solve(x).npath
void proc(int l,int r){ // fill out[l..r] (inc) given out[l] and out[r] are filled
	if(l+1>=r) return;
	assert(out[l]>=out[r]);
	if(out[l]==out[r]){
		std::fill(begin(out)+l+1,begin(out)+r,out[l]);
		return;
	}
	int mid=(l+r)>>1;
	out[mid]=solve(mid);
	proc(l,mid);
	proc(mid,r);
} // total complexity: about O(n sqrt n log n)

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	ad.resize(n);
	for(int z=n;--z;){
		int u,v;std::cin>>u>>v;
		--u;--v;
		ad[u].push_back(v);ad[v].push_back(u);
	}
	dd_remove_paredge(0);

	out.resize(n+1);
	out[1]=solve(1);
	out[n]=solve(n);
	proc(1,n);

	for(int x=1;x<=n;++x) std::cout<<out[x]<<'\n';
}