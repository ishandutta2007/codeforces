// ?????
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
std::vector<int> minFactor(int const limit){
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
 std::vector<decltype(f(2, 1, 2))> result(minFactor_.size(), 1);
 for(int prime=2; prime<(int)result.size(); ++prime) if(minFactor_[prime]==prime){
  for(auto [exponent, product]=std::pair(1, (int64_t)prime); product<(int)result.size(); product*=prime, exponent++) [&]{
   auto const value=f(prime, exponent, product);
   for(int k=0;; ++k)
   for(int f=1; f<prime; ++f){
    auto const x=(prime*k+f)*product;
    if(x>=(int)result.size()) return;
    result[x]*=value;
   }
  }();
 }
 return result;
}
auto Mobius(std::vector<int> const& minFactor_){ return computeMultiplicativeFunction([&](int prime, int exponent, int product){ return (signed char)(exponent>=2 ? 0: -1); }, minFactor_); } auto Mobius(int limit){ return Mobius(minFactor(limit)); }
auto phi(std::vector<int> const& minFactor_){ return computeMultiplicativeFunction([&](int prime, int exponent, int product){ return int(product/prime*(prime-1)); }, minFactor_); } auto phi(int limit){ return phi(minFactor(limit)); }
std::vector<char> isComposite(int const limit){
 std::vector<char> isComposite(limit);
 std::vector<int> exponents;
 for(int p=2; p<(int)isComposite.size(); ++p) if(not isComposite[p]){
  if((int64_t)p*p<limit)
  for(int j=p*p; j<(int)isComposite.size(); j+=p)
   isComposite[j]=true;
 }
 return isComposite;
}
std::vector<int> primes(int const limit){
 std::vector<int> primes;
 auto const isComposite_=isComposite(limit);
 for(int p=2; p<limit; ++p)
  if(not isComposite_[p]) primes.push_back(p);
 return primes;
}

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	static auto const minFactor_=::minFactor((int)1e6+1);

	int n; std::cin>>n;
	std::map<int, int> count;
	for(int _=0; _<n; ++_){
		int originalNumber; std::cin>>originalNumber;
		int squareFreeReduced=1; 
		assert(originalNumber!=0);
		while(originalNumber!=1){
			auto const prime=minFactor_[originalNumber]; int exponent=0;
			do { originalNumber/=prime; exponent++; } while(originalNumber%prime==0);
			if(exponent&1) squareFreeReduced*=prime;
		}

		count[squareFreeReduced]++;
	}

	int maxOdd{}, maxEven{}, sumOneLater{};
	for(auto const [key, count]: count){
		if(count&1)
			maxOdd=std::max(maxOdd, count);
		else
			maxEven=std::max(maxEven, count);

		if((count&1)==0 or key==1)
			sumOneLater+=count;
	}

	int numQuery; std::cin>>numQuery;
	for(int _=0; _<numQuery; ++_){
		int64_t value; std::cin>>value;
		if(value==0)
			std::cout<<std::max(maxOdd, maxEven)<<'\n';
		else
			std::cout<<std::max(maxOdd, sumOneLater)<<'\n';
	}
}