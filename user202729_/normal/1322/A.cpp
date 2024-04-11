#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::string string; std::cin>>string;
	int degree=0;
	int result=0;
	for(auto ch: string){
		auto old=degree;
		degree+=(ch=='(' ? 1: -1);
		result+=std::min(old,degree)<0;
	}
	std::cout<<(degree==0 ? result: -1)<<'\n';
}