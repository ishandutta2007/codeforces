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
		std::vector<int64_t> p;p.reserve(n+1);p.resize(n);
		for(int64_t& x:p){std::cin>>x;x/=100;}

		int x,a,y,b;int64_t k;std::cin>>x>>a>>y>>b>>k;
		if(y<x){
			std::swap(y,x);std::swap(a,b);
		}

		std::sort(begin(p),end(p));
		for(int i=n-1;i--;)p[i]+=p[i+1]; // suffix sum
		p.push_back(0);

		int64_t const lcmab=a/std::__gcd(a,b)*(int64_t)b;
		auto const compute=[&](int nticket)->int64_t{
			int nxy=nticket/lcmab;
			int ny=nticket/b-nxy;
			int nx=nticket/a-nxy;

			auto iter=--end(p);
			int64_t ans=0;
			iter-=nxy;ans+=(x+y)**iter;
			iter-=ny;ans+=y*(*iter-iter[ny]);
			iter-=nx;ans+=x*(*iter-iter[nx]);
			return ans;
		};

		if(compute(n)<k){
			std::cout<<"-1\n";
		}else{
			int ans=n;
			for(int step=1<<30;step;step>>=1)
				if(ans-step>0&&compute(ans-step)>=k)
					ans-=step;
			std::cout<<ans<<'\n';
		}
	}
}