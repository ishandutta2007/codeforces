// so slow
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number; std::cin>>number;
	std::vector<int> initialJump(number); for(auto& it: initialJump) std::cin>>it;

	// unproven, but feels correct
	// ...
	std::vector<int> add(number);
	int64_t a{}, b{};
	for(int i=0; i<number; ++i){
		int tmp=i+initialJump[i];
		if(tmp>number-1){
			b+=tmp-(number-1);
			tmp=number-1;
		}
		add[tmp]++;
	}

	int64_t result=0;
	for(int i=number; i--;){
		auto const value_=[&]{return b-a*i;};

		auto const value=value_();
		a+=add[i]; b+=add[i]*(int64_t)i;
		assert(value_()==value);

		result=std::max(result, value-1);
		//assert(std::cout<<i<<" ** "<<value-1<<'\n');

		a-=1; b-=i; b-=initialJump[i];
		assert(value_()==value-initialJump[i]);
	}
	std::cout<<result<<'\n';
}