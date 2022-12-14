#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> data(number);
	int num1{};
	for(auto & it: data){
		std::cin>>it;
		num1+=it==1;
	}
	if(num1>=1){
		std::cout<<number-num1<<'\n';
		return 0;
	}

	int result=INT_MAX;
	for(int left=0; left<number; ++left){
		int value=data[left];
		for(int right=left+1; right<number; ++right){
			// inclusive range
			value=std::gcd(value, data[right]);
			if(value==1){
				result=std::min(result, right-left);
				break;
			}
		}
	}
	std::cout<<(result==INT_MAX ? -1: result+number-1)<<'\n';
}