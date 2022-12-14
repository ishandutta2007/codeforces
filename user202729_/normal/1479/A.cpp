// why I can never get interactive problems right on first try
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	auto const query=[&](auto const& it){
		assert(0<=it); assert(it<number);
		std::cout<<"? "<<it+1<<std::endl;
		int value;
#if LOCAL
		value=std::array<int, 5>{{3, 2, 1, 4, 5}}[it];
#else
		std::cin>>value;
#endif
		return value;
	};
	auto const decrease=[&](auto const& it){
		return query(it)>query(it+1);
	};
	int result;
	if(number==1 or not decrease(0)) result=0;
	else if(decrease(number-2)) result=number-1;
	else{
		int left=0, right=number-2;
		// decrease(left) and not decrease(right)
		while(right!=left+1){
			int middle=(left+right)>>1;
			if(decrease(middle)) left=middle; else right=middle;
		}
		result=right;
	}
	std::cout<<"! "<<result+1<<'\n';
}