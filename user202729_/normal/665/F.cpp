// (n^3/4)/log n solution~
// update: trivial logic error :(

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t number; std::cin>>number;
	std::vector<int64_t> small(1+(int)std::sqrt(number)), large(number/small.size());

	for(int index=0; index<(int)small.size(); ++index)
		small[index]=index;
	for(int index=0; index<(int)large.size(); ++index)
		large[index]=number/(index+1)-1;
	// inclusive, exclude 1, always keep primes
	
	auto const get=[&](int64_t value)->int64_t&{
		if(value<=(int64_t)small.size()) return small[value-1];
		else{
			assert(number/(number/value)==value);
			return large[number/value-1];
		}
	};

	for(int prime=2; prime<=(int)small.size(); ++prime)if(small[prime-1]!=small[prime-2]){
		auto const tmp=small[prime-2];

		for(int index=0; index<(int)large.size(); ++index){
			auto const value=number/(index+1);
			if(value<(int64_t)prime*prime) break;

			large[index]-=get(value/prime)-tmp;
		}
		for(int index=(int)small.size(); index--;){
			auto const value=index+1;
			if(value<(int64_t)prime*prime) break;

			small[index]-=small[value/prime-1]-tmp;
		}
	}


	int64_t result=(int64_t)std::cbrt(number)-1;
	while((result+1)*(result+1)*(result+1)<=number) ++result;
	result=small[result-1];


	for(int prime=2, piPrime=0; prime<=(int)small.size() and (int64_t)prime*prime<number; ++prime)if(small[prime-1]!=small[prime-2]){
		++piPrime;
		result+=get(number/prime)-piPrime;
	}

	assert([&]{
		int64_t result1{};
		for(int i=1; i<=number; ++i){
			int count=0;
			for(int j=1; j<=i; ++j)
				if(i%j==0){
					++count;
					if(count>4) break;
				}
			result1+=count==4;
		}
		assert(result==result1);
		return true;
	}());

	std::cout<<result<<'\n';
}