// easier than C
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::array<int, 20> count{};
	for(int _=0; _<number; ++_){
		int value; std::cin>>value;
		for(int bit=0; bit<20; ++bit)count[bit]+=value>>bit&1;
	}
	int64_t result{};
	for(int _=0; _<number; ++_){
		int value{};
		for(int bit=0; bit<20; ++bit)
			if(count[bit]){
				--count[bit];
				value|=1<<bit;
			}
		result+=value*(int64_t)value;
	}
	std::cout<<result<<'\n';
}