#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	for(int _=0;_<numTest;++_) {
		int n, distance; std::cin>>n>>distance;
		int maximumGap=0;
		bool okay=false;
		for(int _=0;_<n;++_) {
			int gap; std::cin>>gap;
			if(gap==distance) okay=true;
			maximumGap=std::max(maximumGap, gap);
		}
		if(okay){
			std::cout<<"1\n";
			goto continue_outer;
		}
		std::cout<<
			std::max(2,(distance+maximumGap-1)/maximumGap)
			<<'\n';
continue_outer:;
	}
}