#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int height; std::cin>>height;
	std::vector<int> values(height+1); for(auto & it: values) std::cin>>it;
	for(int index=1;index<(int)values.size();++index) if(values[index]>1 and values[index-1]>1){
		std::cout<<"ambiguous\n";
		int last=0;
		for(auto it: values){
			for(int _=0;_<it;++_) std::cout<<last<<' ';
			last+=it;
		}
		std::cout<<'\n';

		last=0; int lastCount=1;
		for(auto it: values){
			for(int i=0;i<it;++i) std::cout<<last+std::min(lastCount-1, i)<<' ';
			last+=lastCount;
			lastCount=it;
		}
		std::cout<<'\n';

		return 0;
	}
	std::cout<<"perfect\n";
}