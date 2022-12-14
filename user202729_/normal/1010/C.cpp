#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
3 10
10 20 30

)");}
#endif // Sublime

#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
	int ndenom,base;std::cin>>ndenom>>base;
	int gcd=base;
	while(ndenom-->0){
		int denom;std::cin>>denom;
		denom%=base;
		if(denom==0)continue;
		gcd=std::__gcd(gcd,denom);
	}
	std::cout<<base/gcd<<'\n';
	for(int d=0;d<base;d+=gcd)
		std::cout<<d<<' ';
	std::cout<<'\n';
}