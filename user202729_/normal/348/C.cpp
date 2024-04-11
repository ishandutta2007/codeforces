/*
 * Considering special cases (subtasks) works approximately 100% of the time to solve hard problems.
 * Took way too long to solve this problem. It's supposed to be easy.
 * Implementation time:
 * - 20 minutes
 * - 5 minutes (debug): found a bug, still get WA verdict.
 * - 24 minutes (debug): found nothing. Write a test generator.
 * - 10 minutes (debug): found a bunch of bugs already... (integer overflow!!??)
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nset,nq;std::cin>>n>>nset>>nq;
	std::vector<int64_t> a(n);for(int64_t& ai:a)std::cin>>ai;
	std::vector<std::vector<int>> sets(nset);
	for(auto& s:sets){
		int i;std::cin>>i;s.resize(i);
		for(auto& x:s){
			std::cin>>x;
			--x;
		}
	}

	int const LARGETHRES=300;
	std::vector<int> largeind(nset,-1); // i -> -1 if set i is small, (index) if set i is large
	std::vector<int64_t> sum,lazy; // (largeind) -> val
	std::vector<std::vector<int>> ncommon; // [largeind][ind] = count

	for(int i=0;i<nset;++i)
	//for(int i=nset;i--;)
	if(sets[i].size()>LARGETHRES){
		largeind[i]=(int)sum.size();
		int64_t sumi=0;
		for(auto x:sets[i])sumi+=a[x];
		sum.push_back(sumi);

		std::vector<char> mark(n); // TODO reuse mark?
		for(auto x:sets[i])mark[x]=true;

		std::vector<int> nci(nset);
		for(int j=0;j<nset;++j)
			for(int x:sets[j])if(mark[x])
				++nci[j];
		ncommon.push_back(std::move(nci));
	}
	lazy.resize(sum.size());

	for(int z=nq;z--;){
		char type;std::cin>>type;
		if(type=='+'){
			int i,val;std::cin>>i>>val;
			--i;
			if(largeind[i]>=0)
				lazy[largeind[i]]+=val;
			else{
				assert(sets[i].size()<=LARGETHRES);
				for(auto x:sets[i])
					a[x]+=val;
			}

			for(auto b=sum.size();b--;){
				sum[b]+=(int64_t)val*ncommon[b][i];
			}
		}else{
			assert(type=='?');
			int i;std::cin>>i;--i;
			if(largeind[i]>=0)
				std::cout<<sum[largeind[i]]<<'\n';
			else{
				int64_t ans=0;
				for(auto x:sets[i])
					ans+=a[x];
				for(auto b=sum.size();b--;)
					ans+=lazy[b]*ncommon[b][i];
				std::cout<<ans<<'\n';
			}
		}
	}
}