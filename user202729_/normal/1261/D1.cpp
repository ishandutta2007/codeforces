/*
I have seen the standing table before the virtual contest, however I think that it doesn't
alter my strategy.

====

Spent almost 30 minutes to try to solve E without success.

O(n^2) algorithm.
*/
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

int const MOD=998244353;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nopt;std::cin>>n>>nopt;
	std::vector<int> h;h.reserve(n+1);h.resize(n);for(int& hi:h)std::cin>>hi;
	h.push_back(h[0]);

	std::vector<int> f{1};f.reserve(n*2+1);
	std::vector<int> g;g.reserve(n*2+1);
	for(int i=0;i<n;++i){
		if(h[i]==h[i+1]){
			for(auto& fi:f)
				fi=int(fi*(int64_t)nopt%MOD);
			f.insert(begin(f),0);
			f.push_back(0);
		}else{
			g.assign(begin(f),end(f));
			g.push_back(0);
			g.push_back(0);
			assert(nopt-2>=0);
			std::transform(begin(f),end(f),++begin(g),++begin(g),[nopt](int fi,int gi){
					return int((gi+fi*int64_t(nopt-2))%MOD);
					});
			std::transform(begin(f),end(f),++++begin(g),++++begin(g),[](int fi,int gi){
					return gi+fi>=MOD ? gi+fi-MOD : gi+fi;
					});
			std::swap(f,g);
		}
	}

	std::cout<<std::accumulate(begin(f)+n+1,end(f),0LL)%MOD<<'\n';
}