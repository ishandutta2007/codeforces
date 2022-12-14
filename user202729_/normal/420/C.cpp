#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>

#include<iostream>
#include<vector>
#include<algorithm>
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nPeople,leastAgree;std::cin>>nPeople>>leastAgree;
	std::vector<int> inDegree(nPeople,0);
	std::vector<std::pair<int,int>> pairs(nPeople);
	for(int i=0;i<nPeople;++i){
		int x,y;std::cin>>x>>y;--x;--y;
		if(x>y)std::swap(x,y);
		++inDegree[x];++inDegree[y];
		pairs[i]={x,y};
	}
	// note that nAgree when (x) and (y) are chosen is inDegree[x]+inDegree[y]
	// -std::count(pairs.begin(),pairs.end(),{x,y})
	std::vector<int> degsSorted=inDegree;
	std::sort(degsSorted.begin(),degsSorted.end());
	long long ans=0;
	// first, compute number of unordered and distinct pairs in degsSorted that sums to >= leastAgree
	auto iter=degsSorted.end();
	for(int i=0;i<nPeople-1;++i){
		// consider all pairs with indices (i,j) where i<j
		if(degsSorted[i]+degsSorted[i+1]>=leastAgree){
			ans+=nPeople-i-1;
			continue;
		}
		while(iter!=degsSorted.begin()&&degsSorted[i]+*std::prev(iter)>=leastAgree)
			--iter;
		// now iter points to the least element where degsSorted[i]+*iter>=leastAgree
		ans+=degsSorted.end()-iter;
	}
	assert(std::cerr<<ans<<'\n');
	// then count number of overcounted (i,j) pairs
	std::sort(pairs.begin(),pairs.end());
	int lastEnd=0;
	for(int i=1;i<=nPeople;++i){
		if(i==nPeople||pairs[i]!=pairs[i-1]){
			int nPair=i-lastEnd;
			int x=pairs[lastEnd].first,y=pairs[lastEnd].second;
			if(inDegree[x]+inDegree[y]>=leastAgree&&
					inDegree[x]+inDegree[y]-nPair<leastAgree){
				assert(std::cerr<<"*"<<inDegree[x]+inDegree[y]-nPair<<'\n');
				--ans;
			}
			lastEnd=i;
		}
	}
	std::cout<<ans<<'\n';
}