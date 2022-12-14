// It's quite unusual for me to do virtual contest on an old one, but older contests are
// not worse than newer ones.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<climits>
#include<algorithm>
#include<array>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int n;std::cin>>n;
	std::vector<int> comp(n);
	for(int& x:comp){
		std::cin>>x;--x;
	}

	std::vector<std::vector<int>> ad(n);
	std::vector<int> indeg(n);
	for(int v=0;v<n;++v){
		int k;std::cin>>k;
		indeg[v]=k;
		while(k--){
			int u;std::cin>>u;--u;
			ad[u].push_back(v); // u must be completed before v
		}
	}

	int out=INT_MAX;
	for(int start=0;start<3;++start){
		std::array<std::vector<int>,3> pending;

		for(int i=0;i<n;++i) if(indeg[i]==0)
			pending[comp[i]].push_back(i);

		std::vector<int> indeg1=indeg;

		int pos =start; // computer index
		int curout=n;
		while(std::any_of(begin(pending),end(pending),[](auto const& x){return not x.empty();})){
			while(pending[pos].empty()){
				++curout;
				pos=(pos+1)%3;
			}
			while(not pending[pos].empty()){
				int x=pending[pos].back();pending[pos].pop_back();
				for(int y:ad[x]){
					if(0==--indeg1[y])
						pending[comp[y]].push_back(y);
				}
			}
		}

		out=std::min(out,curout);
	}
	std::cout<<out<<'\n';
}