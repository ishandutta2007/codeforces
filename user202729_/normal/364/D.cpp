#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::mt19937 engine( std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count());

auto factorize(int64_t item){
	std::vector<std::pair<int64_t, int>> result;
	{
		auto exp2=__builtin_ctzll(item);
		if(exp2){result.push_back({2, exp2}); item>>=exp2;}
	}
	for(int prime=3;prime*(int64_t)prime<=item; prime+=2) 
		if(item%prime==0){
			item/=prime;
			result.push_back({prime, 1});
			while(item%prime==0){
				item/=prime;
				++result.back().second;
			}
		}
	if(item>1) result.push_back({item, 1});
	return result;
}


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int64_t> data(number); for(auto & it: data) std::cin>>it;
	std::shuffle(begin(data),end(data), engine);

	std::vector<int64_t> tmp(begin(data), begin(data)+std::min(number, 20));
	std::sort(begin(tmp),end(tmp), std::greater<>());
	{
		auto out=begin(tmp);
		for(auto item: tmp)
			if(std::none_of(begin(tmp), out,[&](auto other){return other%item==0;}))
				*out++=item;
		tmp.erase(out, end(tmp));
	}

	int64_t result=1;
	for(auto item: tmp){
		// assumes item is divisible by g

		auto const factors=factorize(item);
		std::vector<int> count(
				std::accumulate(begin(factors),end(factors),(int64_t)1,
				[&](int64_t result, auto prime_exponent){
					return result*(prime_exponent.second+1);
				})
				);

		for(auto other: data){
			int it=0;
			for(auto [prime, exponent]: factors){
				it*=exponent+1;
				if(prime==2){
					it+=std::min(exponent, __builtin_ctzll(other));
				}else{
					for(int _=0;_<exponent;++_) {
						if(other%prime==0){
							other/=prime;
							++it;
						}
					}
				}
			}
			if(other==item) assert(it==(int)count.size()-1);
			++count[it];
		}

		// now count[it] = number of elements `other` in data such that
		// gcd(item, other) == {the factor of item represented by `it`}

		{
			auto base=(int)count.size();
			for(auto [prime, exponent]: factors){
				assert(base%(exponent+1)==0);
				base/=exponent+1;
				for(int index=(int)count.size(); index--;) 
					if((index/base)%(exponent+1)!=0)
						count[index-base]+=count[index];
			}
		}

		// now count[it] = number of elements `other` in data such that
		// other is divisible by {the factor of item represented by `it`}

		for(int index=0;index<(int)count.size();++index) if(count[index]*2>=number){
			assert(count[index]<=number);
			int64_t value=1;
			int it=index;
			std::for_each(factors.rbegin(), factors.rend(),[&](auto prime_exponent){
				auto const[prime, exponent]=prime_exponent;
				for(auto _=it%(exponent+1); _--;)
					value*=prime;
				it/=exponent+1;
			});
			assert(it==0);
			result=std::max(result, value);
		}
	}
	std::cout<<result<<'\n';
}