#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int suma=0,maxa=0;
	for(int z=n;z--;){
		int ai;std::cin>>ai;
		suma+=ai;
		maxa=std::max(maxa,ai);
	}
	std::cout<<std::max(maxa,(2*suma)/n+1)<<'\n';
}