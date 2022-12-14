#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n, mod; std::cin>>n>>mod;
	int64_t result=0;
	for(int one=0;one<mod;++one) 
	for(int two=0;two<mod;++two) 
		if((one*one+two*two)%mod==0)
			result+= (n/mod+((one+mod-1)%mod<n%mod))*int64_t (n/mod+((two+mod-1)%mod<n%mod));
	std::cout<<result<<'\n';
}