/*
 * Remark. It's unfortunate that sometimes I get problems that I've seen - virtual contests,
 * however it's hard to completely prevent it without reading the problem statement int advance.
 * I could just implement every problem I've seen, but...
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nt;std::cin>>nt;
	while(nt--){
		int n,m;std::cin>>n>>m;
		std::vector<char> matched(n*3);
		std::vector<int> match;match.reserve(n);
		for(int edgeid=1;edgeid<=m;++edgeid){
			int u,v;std::cin>>u>>v;--u;--v;
			if(matched[u] or matched[v] or (int)match.size()==n)
				continue;
			matched[u]=matched[v]=true;
			match.push_back(edgeid);
		}

		if((int)match.size()==n){
			std::cout<<"Matching\n";
			for(auto x:match)std::cout<<x<<' ';
			std::cout<<'\n';
		}else{
			std::cout<<"IndSet\n";
			auto iter=begin(matched);
			for(int i=0;i<n;++i){
				while(*iter)++iter;
				std::cout<<iter-begin(matched)+1<<' ';
				++iter;
			}
			std::cout<<'\n';
		}
	}
}