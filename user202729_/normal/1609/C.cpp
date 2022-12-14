// time-limit: 2000
// problem-url: https://codeforces.com/contest/1609/problem/C
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


std::vector<int> minFactorF(int const limit){
	std::vector<int> minFactor(limit);
	for(int p=2; p<(int)minFactor.size(); ++p) if(minFactor[p]==0){
		minFactor[p]=p;
		if((int64_t)p*p<(int)minFactor.size())
			for(int j=p*p; j<(int)minFactor.size(); j+=p)
				if(minFactor[j]==0)
					minFactor[j]=p;
	}
	return minFactor;
}

template<class F> auto computeMultiplicativeFunction(F f, std::vector<int> const& minFactor_){
	// f: (prime, exponent, product) -> value -- return type=return type of f
	std::vector<decltype(f(2, 1, 2))> result(minFactor_.size(), 1);
	for(int prime=2; prime<(int)result.size(); ++prime) if(minFactor_[prime]==prime){
		for(auto [exponent, product]=std::pair(1, (int64_t)prime); product<(int)result.size(); product*=prime, exponent++) [&]{
			auto const value=f(prime, exponent, (int)product);
			for(int k=0;; ++k)
			for(int f=1; f<prime; ++f){
				auto const x=(prime*k+f)*product;
				if(x>=(int)result.size()) return;
				result[x]*=value;
			}
		}();
	}
	// * n log n, slow?
	return result;
}

#define MakeFunction(N, E) \
auto N(std::vector<int> const& minFactor_){ \
	return computeMultiplicativeFunction([&]( \
				[[maybe_unused]] int prime, [[maybe_unused]] int exponent, [[maybe_unused]] int product){ \
		return E; \
	}, minFactor_); \
} \
auto N(int limit){ return N(minFactorF(limit)); }


MakeFunction(MobiusF, (signed char)(exponent>=2 ? 0: -1))
MakeFunction(phiF, int(product/prime*(prime-1)))


std::vector<char> isCompositeF(int const limit){
	std::vector<char> isComposite(limit);
	std::vector<int> exponents;
	for(int p=2; p<(int)isComposite.size(); ++p) if(not isComposite[p]){
		if((int64_t)p*p<limit)
		for(int j=p*p; j<(int)isComposite.size(); j+=p)
			isComposite[j]=true;
	}
	return isComposite;
}

std::vector<int> primesF(int const limit){
	std::vector<int> primes;
	auto const isComposite=isCompositeF(limit);
	for(int p=2; p<limit; ++p)
		if(not isComposite[p]) primes.push_back(p);
	return primes;
}

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

auto const isComposite=isCompositeF((int)1e6+1);

void up(){
	int n; std::cin>>n;
	int e; std::cin>>e;
	std::vector<int> a(n);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	int64_t result {};
	for(int base=0; base<e; ++base){
		for(int i=base; i<n; i+=e)
			if(a[i]>1 and not isComposite[a[i]]){
				int countAfter {}, countBefore {};
				for(int j=i+e; j<n; j+=e){
					if(a[j]==1) countAfter++; else break;
				}
				for(int j=i-e; j>=0; j-=e){
					if(a[j]==1) countBefore++; else break;
				}
				result+=int64_t(countAfter+1)*(countBefore+1)-1;
			}
	}
	std::cout<<result<<'\n';
}