// doesn't feel like the correct approach...

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::vector<int> factor(1000001);
	for(int p=2; p<(int)factor.size(); ++p)
		if(factor[p]==0)
			for(auto m=p; m<(int)factor.size(); m+=p)
				if(factor[m]==0) factor[m]=p;

	int numTest; std::cin>>numTest; while(numTest--){
		auto const read=[&]{
			int64_t result=1;
			for(int _=0; _<3; ++_){
				int it; std::cin>>it;
				result*=it;
			}
			return result;
		};
		auto const readFactorize=[&]{
			std::pair<std::map<int, int>, int64_t> result;
			result.second=1;
			for(int _=0; _<3; ++_){
				int it; std::cin>>it;
				result.second*=it;
				while(it!=1){
					result.first[factor[it]]++;
					it/=factor[it];
				}
			}
			return result;
		};
		auto const [nFact, n]=readFactorize();
		auto const m=read();
		auto const [sFact, s]=readFactorize();

		auto const allFactors=[&](std::map<int, int> const& it){
			std::vector<int64_t> result{1};
			for(auto [prime, exponent]: it){
				auto const n=(int)result.size();
				result.resize(n*(exponent+1));
				for(int i=0; i<n*exponent; ++i)
					result[i+n]=result[i]*prime;
			}
			return result;
		};

		int64_t result{};

		//for(int i=1; i<=m;++i) result+=s*2%std::gcd(i, n)==0;

		auto n1Fact=nFact;
		for(auto iter=n1Fact.begin(); iter!=n1Fact.end();){
			auto& [prime, exponent]=*iter;
			int64_t product=1;
			for(int curExponent=1; curExponent<=exponent; ++curExponent){
				product*=prime;
				if(s*2%product!=0){
					exponent=curExponent;
					++iter;
					goto nextPrime;
				}
			}

			iter=n1Fact.erase(iter);
nextPrime:;
		}

		auto n1factors=allFactors(n1Fact);
		std::sort(begin(n1factors), end(n1factors));

		std::vector<int64_t> count(n1factors.size());
		for(int i=0; i<(int)n1factors.size(); ++i)
			count[i]=m/n1factors[i];
		// now count[i]=number of numbers x such that n1factors[i]|gcd(x, n)

		for(auto [prime, exponent]: n1Fact){
			for(int i=0; i<(int)n1factors.size(); ++i) if(n1factors[i]%prime!=0){
				int64_t value=n1factors[i];
				int lastIndex=i;
				for(int _=0; _<exponent; ++_){
					value*=prime;
					auto const iter=std::lower_bound(begin(n1factors), end(n1factors), value); assert(*iter==value);
					auto const nextIndex=int(iter-n1factors.begin());
					count[lastIndex]-=count[nextIndex];
					lastIndex=nextIndex;
				}
			}
		}
		// now count[i]=number of numbers x such that n1factors[i]==gcd(x, n)

		for(int i=0; i<(int)n1factors.size(); ++i)
			if(s*2%n1factors[i]==0)
				result+=count[i];

		//for(int i=1; i<=n;++i) result+=s*2%i==0;
		auto twiceSFact=sFact; twiceSFact[2]++;
		for(auto it: allFactors(twiceSFact)) result+=it<=n;

		std::cout<<result<<'\n';

	}
}