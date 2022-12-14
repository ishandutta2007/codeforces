// Initially I missed the special condition "It is guaranteed that no two consecutive characters are equal."
// so I cannot solve the problem immediately...
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	int l=0,r=(int)s.size();
	std::string tleft;
	tleft.reserve(s.size()/4+1);

	while(r-l>=4){
		while(not(s[l]==s[r-1] or s[l]==s[r-2]))++l;
		while(s[l]!=s[r-1])--r;
		tleft+=s[l];
		++l;--r;
	}

	std::cout<<tleft;
	if(r!=l) std::cout<<s[l];
	std::copy(tleft.rbegin(),tleft.rend(),std::ostream_iterator<char>(std::cout));
}