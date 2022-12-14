#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;
	int out=1;
	for(int z=n+m;z--;)
		out=out*2%998244353;
	std::cout<<out<<'\n';
}