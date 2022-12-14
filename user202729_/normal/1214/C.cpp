#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int deg=0,mindeg=0;
	for(int i=0;i<n;++i){
		char c;std::cin>>c;
		if(c=='(')++deg;else --deg;
		mindeg=std::min(mindeg,deg);
	}
	std::cout<<((mindeg>=-1&&deg==0)?"Yes\n":"No\n");
}