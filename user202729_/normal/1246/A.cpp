#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,p;std::cin>>n>>p;
	for(int ans=1;;++ans){
		if(p>0)
			if(n-p*ans<=0)
				break;
		if(__builtin_popcount(n-p*ans)<=ans && ans<=n-p*ans){
			std::cout<<ans<<'\n';
			return 0;
		}
	}
	std::cout<<"-1\n";
	return 0;
}