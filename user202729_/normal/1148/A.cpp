#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int a, b, c; std::cin>>a>>b>>c;
	if(a>b) std::swap(a, b);
	std::cout<<2LL*a+(a!=b)+2LL*c<<'\n';
}