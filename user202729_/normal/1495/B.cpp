
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> value(number);
	for(auto& it: value) std::cin>>it;

	std::vector<int> leftDescend(number), rightDescend(number);

	std::pair<int, int> best{INT_MIN, INT_MIN};

	for(int i=1; i<number; ++i)
		leftDescend[i]=value[i]>value[i-1] ? leftDescend[i-1]+1: 0;
	for(int i=number-2; i>=0; i--)
		rightDescend[i]=value[i]>value[i+1] ? rightDescend[i+1]+1: 0;

	for(int i=0; i<number; ++i){
		auto const [a, b]=std::minmax({leftDescend[i], rightDescend[i]});
		if(a>0 and a==b and b%2==0)
			best=std::max(best, std::pair(b, i));
	}

	int result=0;
	if(best.first!=INT_MIN){
		int i=best.second;
		auto const [a, b]=std::minmax({leftDescend[i], rightDescend[i]});
		assert(a>0 and a==b and b%2==0);

		[&]{
			for(int j=0; j<i-b; ++j){
				if(leftDescend[j]>=b or rightDescend[j]>=b) return;
			}
			for(int j=i+b+1; j<number; ++j){
				if(leftDescend[j]>=b or rightDescend[j]>=b) return;
			}
			result=1;
		}();
	}

	std::cout<<result<<'\n';
}