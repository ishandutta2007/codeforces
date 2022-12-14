#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int64_t> b(n);
	int64_t sum=0;
	for(auto& x:b){
		std::cin>>x;sum+=x;x=sum;
	}

	int64_t ans=-1;

	auto proc=[&](int64_t p){ // p is a prime factor of sum
		int64_t cost=0;
		for(auto y:b){
			auto r=y%p;
			cost+=std::min(r,p-r);
		}
		if(ans<0)ans=cost;
		else ans=std::min(ans,cost);
	};

	int64_t x=sum;
	for(int p=2;p*(int64_t)p<=x;++p)if(x%p==0){
		do x/=p; while(x%p==0);
		proc(p);
	}
	if(x>1)proc(x);

	std::cout<<ans<<'\n';
}