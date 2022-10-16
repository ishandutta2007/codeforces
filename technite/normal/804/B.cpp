#include<bits/stdc++.h>
using namespace std;
int const  MOD=1e9+7;
int main()
{
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