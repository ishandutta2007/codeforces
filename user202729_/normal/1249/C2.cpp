#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	std::vector<char> digits;
	while(ntest--){
		int64_t n;std::cin>>n;
		digits.clear();
		for(auto x=n;x;){
			digits.push_back(x%3);
			x/=3;
		}
		digits.push_back(0);
		for(auto i=digits.size();i--;)
			if(digits[i]==2){
				while(digits[i]!=0)
					++i;
				digits[i]=1;
				for(;i--;)
					digits[i]=0;
				break;
			}

		int64_t ans=0;
		for(auto i=digits.size();i--;)
			ans=ans*3+digits[i];
		std::cout<<ans<<'\n';
	}
}