#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int t;std::cin>>t;
	while(t--){
		int r,g,b;std::cin>>r>>g>>b;
		std::cout<<std::min({r+g,g+b,b+r,(r+g+b)/2})<<'\n';
	}
}