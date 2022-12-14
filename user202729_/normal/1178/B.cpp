#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	std::vector<int> a(s.size()); // number of 'w' before
	a[0]=0;
	for(unsigned i=1;i<s.size();++i)
		a[i]=a[i-1]+(s[i]=='v' and s[i-1]=='v');

	int nwafter=0;
	int64_t ans =0;
	for(unsigned i=s.size()-1;i--;){
		nwafter+=(s[i]=='v' and s[i+1]=='v');
		if(s[i]=='o')
			ans+=a[i]*(int64_t)nwafter;
	}

	std::cout<<ans<<'\n';
}