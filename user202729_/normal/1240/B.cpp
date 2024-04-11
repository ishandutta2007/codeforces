#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int q;std::cin>>q;
	while(q--){
		int n;std::cin>>n;
		std::vector<std::pair<int,int>> ind(n,{-1,-1});
		for(int i=0;i<n;++i){
			int ai;std::cin>>ai;--ai;
			if(ind[ai].first<0)ind[ai].first=i;
			ind[ai].second=i;
		}

		ind.erase(std::remove(begin(ind),end(ind),std::make_pair(-1,-1)),end(ind));
		int ans=n;
		for(unsigned lasti=0,i=1;i<=ind.size();++i){
			if(i==ind.size()||ind[i-1].second>ind[i].first){
				ans=std::min<int>(ans,ind.size()-(i-lasti));
				lasti=i;
			}
		}
		std::cout<<ans<<'\n';
	}
}