#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	for(unsigned i=1;i<s.size();++i){
		if(s[i]!=s[i-1]){
			std::cout<<"1 ";
			std::reverse(begin(s),begin(s)+i);
		}else{
			std::cout<<"0 ";
		}
	}
	std::cout<<(s[0]>s.back() ? "1\n" : "0\n");
}