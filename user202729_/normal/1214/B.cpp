#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int b,g,n;std::cin>>b>>g>>n;
	int minb=std::max(0,n-g);
	int maxb=std::min(b,n);
	std::cout<<maxb-minb+1<<'\n';
}