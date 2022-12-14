#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int sumDigit(int it){return it ? it%10+sumDigit(it/10): 0;}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	auto const iterate=[&](auto function){
		for(int i=std::min(number, 9*10); i>=0;--i)
			if(number-i+sumDigit(number-i)==number)
				function(number-i);
	};
	int k{};
	iterate([&](int x){k++;});
	std::cout<<k<<'\n';
	iterate([&](int x){
		std::cout<<x<<'\n';
	});
}