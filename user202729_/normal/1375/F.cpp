#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
#define ASSERT(x) ((x) ? void(0) : std::exit(__LINE__))

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::array<int64_t, 3> value;
	for(auto& it: value) std::cin>>it;
	std::cout<<"First"<<std::endl;
	int last=-1;

	auto const normalize=[&]{
		auto const t=*std::min_element(begin(value), end(value));
		for(auto& it: value) it-=t;
	};
	auto const ask=[&](int64_t askValue)->void{

		/*
		assert(std::cerr<<"state:");
		for(auto it: value){assert(std::cerr<<it<<' ');}
		assert(std::cerr<<'\n');
		*/


		std::cout<<askValue<<std::endl;
		int position; std::cin>>position;
		if(position==0){
			std::exit(0);
		}
		--position;
		last=position;
		value[position]+=askValue;
		normalize();
	};
	auto const sorted=[&]{
		auto copy=value;
		std::sort(begin(copy), end(copy));
		return copy;
	};

	normalize();
	ask(sorted()[2]);

	{
		auto const [zero, a, c]=sorted();
		ASSERT(zero==0);
		ASSERT(value[last]==c);

		ask((c-a)+c);
	}
	{
		auto const [zero, a, c]=sorted();
		ASSERT(zero==0);
		ASSERT(value[last]==c);
		ASSERT(c==a*2);

		ask(a);
	}
	ASSERT(false);
}