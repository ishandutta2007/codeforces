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
	std::vector<int> nxt(n),indeg(n);
	for(int& x:nxt){
		std::cin>>x;--x;
		++indeg[x];
	}
	if(!std::all_of(begin(indeg),end(indeg),[](int x){return x==1;}))
		std::cout<<"-1\n";
	else{
		int64_t ans=1;
		for(int i=0;i<n;++i){
			int x=i,cyclelen=0;
			do{
				x=nxt[x];
				++cyclelen;
			}while(x!=i);

			int z=cyclelen%2==0?cyclelen/2:cyclelen;
			ans=ans/std::__gcd((int64_t)z,ans)*z;
		}
		std::cout<<ans<<'\n';
	}
}