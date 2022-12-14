#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<iostream>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int64_t x;std::cin>>x;
		if(x>14 and 1<=x%14 and x%14<=6)
			std::cout<<"YES\n";
		else
			std::cout<<"NO\n";
	}
}