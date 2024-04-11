#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>

int const MOD=1000000007;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	int val=0,ans=0;
	for(char c:s){
		if(c=='a'){
			val=(val*2+1)%MOD;
		}else
			ans=(ans+val)%MOD;
	}
	std::cout<<ans<<'\n';
}