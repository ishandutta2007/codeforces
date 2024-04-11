#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>

int const MOD=998244353;
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::map<int64_t,int> exp;
	std::vector<int64_t> comp; // p1*p2
	int n;std::cin>>n;

	for(int z=n;z--;){ // each number may have form p^2, p^3, p^4 or p1*p2
		int64_t a;std::cin>>a;
		for(int e=4;e>=2;--e){
			auto p=(int64_t)std::round(std::pow(a,1./e));
			int64_t ppe=1;for(int zz=e;zz--;)ppe*=p;
			if(ppe==a){ // the prime factorization is p**e
				exp[p]+=e;
				goto nextnum;
			}
		}

		comp.push_back(a);
nextnum:;
	}

	for(auto& x:comp){
		for(auto y:comp){
			if(y==x or y<0)continue;
			int64_t g=std::__gcd(x,y);
			if(g!=1){
				++exp[g];
				++exp[x/g];
				x=-1;
				goto nextx;
			}
		}

		for(auto& [prime_,e]:exp){
			int prime=prime_;
			if(x%prime==0){ // obtained factorization
				++e;
				++exp[x/prime]; // invalidates e
				x=-1;
				goto nextx;
			}
		}

nextx:;
	}
	comp.erase(std::remove(begin(comp),end(comp),-1),end(comp));

	int ndiv=1;
	for(auto [prime,e]:exp)
		ndiv=ndiv*(e+1LL)%MOD;

	std::sort(begin(comp),end(comp));
	for(unsigned i=1,le=0;i<=comp.size();++i)
		if(i==comp.size() or comp[i]!=comp[i-1]){
			ndiv=ndiv*(i-le+1LL)*(i-le+1)%MOD;
			le=i;
		}

	std::cout<<ndiv<<'\n';
}