#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	for(int _=0;_<numTest;++_) {
		int numPile, numDay; std::cin>>numPile>>numDay;
		std::vector<int> values(numPile);
		for(auto & item: values) std::cin>>item;
		for(int index=1;index<(int)values.size();++index) {
			 auto const numMove=std::min(values[index],numDay/index);
			 numDay-=index*numMove;
			 values[index]-=numMove;
			 values[0]+=numMove;
		}
		std::cout<<values[0]<<'\n';
	}
}