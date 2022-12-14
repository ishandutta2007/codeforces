#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int64_t b,a;std::cin>>a>>b;
		if(a-b>1){
			std::cout<<"NO\n";
			continue;
		}
		int64_t x=a+b;
		for(int64_t p=2;p*p<=x;++p)
			if(x%p==0){
				std::cout<<"NO\n";
				goto nexttest;
			}
		std::cout<<"YES\n";
nexttest:;
	}
}