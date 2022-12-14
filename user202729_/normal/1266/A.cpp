#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<iostream>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	std::string s;
	while(ntest--){
		std::cin>>s;
		auto iter=std::find(begin(s),end(s),'0');
		if(iter==end(s)){
			std::cout<<"cyan\n";
		}else{
			int sum=0;
			for(char& c:s)sum+=c-'0';
			std::swap(s.back(),*iter);
			assert(s.size()>=2);
			if(std::any_of(begin(s),end(s)-1,[](char c){return c%2==0;})
				and sum%3==0)
				std::cout<<"red\n";
			else std::cout<<"cyan\n";
		}
	}
}