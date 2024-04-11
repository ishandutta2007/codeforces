#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<map>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::map<int,int> cnt;
	for(int z=n;z--;){
		int ai;std::cin>>ai;
		++cnt[ai];
	}
	int ans=n-1;
	for(auto& [x,cntx]:cnt)
		ans=std::min(ans,n-cntx);
	std::cout<<ans<<'\n';
}