#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int len; std::cin>>len;
	int num8{};
	for(int _=0;_<len;++_) {
		char ch; std::cin>>ch;
		num8+=(ch=='8');
	}
	std::cout<<std::min(len/11, num8)<<'\n';
}