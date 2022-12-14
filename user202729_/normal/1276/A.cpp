#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<numeric>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		std::string s;std::cin>>s;

		std::vector<char> del(s.size());
		for(unsigned i=0;i+4<s.size();++i){
			if(std::equal(begin(s)+i,begin(s)+i+5,"twone"))
				del[i+2]=true;
		}

		for(unsigned i=0;i+2<s.size();++i){
			if(not del[i] and std::equal(begin(s)+i,begin(s)+i+3,"one"))
				del[i+1]=true;
			if(not del[i+2] and std::equal(begin(s)+i,begin(s)+i+3,"two"))
				del[i+1]=true;
		}

		std::cout<<std::accumulate(begin(del),end(del),0)<<'\n';
		for(unsigned i=0;i<s.size();++i){
			if(del[i])
				std::cout<<i+1<<' ';
		}
		std::cout<<'\n';
	}
}