#include<iostream>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,k;std::cin>>n>>k;
	std::string s;
	s.reserve(n);
	s.assign((n-k)/2,'0');
	s.push_back('1');
	for(int i=0;s.size()<(unsigned)n;++i)
		s.push_back(s[i]);
	std::cout<<s<<'\n';
}