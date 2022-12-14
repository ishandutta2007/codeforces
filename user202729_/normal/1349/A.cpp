#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;

	std::vector<int> values(number);
	int max=20;
	for(auto & it: values){
		std::cin>>it;
		max=std::max(max, it);
	}

	std::vector<int> factor(max+1);
	for(int prime=2;prime<(int)factor.size();++prime) if(factor[prime]==0)
		for(int multiple=prime;multiple<(int)factor.size(); multiple+=prime) 
			factor[multiple]=prime;

	std::map<int, std::vector<int>> exponents;
	for(auto it: values){
		while(it!=1){
			auto prime=factor[it];
			int exponent=0;
			assert(it%prime==0);
			do{it/=prime; ++exponent; }while(it%prime==0);
			assert(exponent!=0);
			exponents[prime].push_back(exponent);
		}
	}

	int64_t result=1;
	for(auto &[prime, exponentValues]: exponents){
		if((int)exponentValues.size()<=number-2) continue;

		int value;
		if((int)exponentValues.size()==number-1) {
			value=*std::min_element(begin(exponentValues),end(exponentValues));
		}else{
			assert((int)exponentValues.size()==number);
			auto const iterator=exponentValues.begin()+1;
			std::nth_element(begin(exponentValues), iterator, end(exponentValues));
			value=*iterator;
		}

		assert(value!=0);
		while(value--) result*=prime;
	}
	std::cout<<result<<'\n';
}