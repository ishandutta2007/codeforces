#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<algorithm>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	std::vector<int> ind(n); // a[ind[i]] = i+1
	for(int i=0;i<n;++i){
		int ai;
		std::cin>>ai;
		ind[ai-1]=i;
	}

	std::vector<int> g(n,-1); // grundy value starting from that cell

	std::vector<char> mark(n); // temp for calc mex
	std::vector<int> marked; // temp for undo mark
	marked.reserve(n); // actually it's not necessary to compute the grundy value

	for(int ai=n;ai!=0;--ai){
		int i=ind[ai-1];

		auto proc_reachable=[&](int j){
			if(g[j]>=0){
				mark[g[j]]=true;
				marked.push_back(g[j]);
			}
		};

		for(int j=i+ai;j<n;j+=ai)
			proc_reachable(j);
		for(int j=i-ai;j>=0;j-=ai)
			proc_reachable(j);

		g[i]=std::find(begin(mark),end(mark),false)-begin(mark);
		for(auto x:marked)mark[x]=false;
		marked.clear();
	}

	for(auto x:g)
		std::cout<<(x?'A':'B');
	std::cout<<'\n';
}