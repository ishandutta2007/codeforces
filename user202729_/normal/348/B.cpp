// >.< How to avoid such mistakes int real contests?... I had to write a test generator to
// find out the mistake, and that takes a lot of time (8 minutes, to be exact)
// test generator (because nobody is interested int this I minimized it to one line): >>> from random import*|n=10**5|print(n)|print(0, *(choice((0,1,2,10**8,randint(0,10**8))) for z in range(n-1)))||for i in range(2,n+1):|	print(*sample(( randint(1,i-1) ,i),2))

#ifndef LOCAL
#define NDEBUG
#endif
#include<climits>
#include<numeric>
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>

std::vector<std::vector<int>> ad;
std::vector<int> napple;

struct seq{ // 0, step, 2*step, ..., max | max % step ==0
	int64_t max,step;
	seq intersect(seq x)const{
		auto nstep=step/std::__gcd(step,x.step)*x.step;
		auto nmax=std::min(max,x.max)/nstep*nstep;
		return {nmax, nmax ? nstep : 1 /* avoid overflow ... */};
	}
};

seq dd(int x){
	if(ad[x].empty())
		return {napple[x],1};

	seq ans={INT64_MAX,1}; // ~ all integers
	for(auto y:ad[x]){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
		ans=ans.intersect(dd(y));
	}
	assert(ans.max!=INT64_MAX);

	auto const nchild=(int64_t)ad[x].size();
	return {ans.max*nchild, ans.step*nchild};
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	napple.resize(n);
	for(auto& x:napple)std::cin>>x;

	ad.resize(n);
	for(int z=n-1;z--;){
		int u,v;std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	std::cout<<std::accumulate(begin(napple),end(napple),0LL) - dd(0).max<<'\n';
}