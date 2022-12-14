#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up(){
	int number; std::cin>>number;
	int maxPrevious; std::cin>>maxPrevious;
	int maxDiff=0;
	for(int index=1;index<number;++index) {
		int value; std::cin>>value;
		maxDiff=std::max(maxDiff, maxPrevious-value);
		maxPrevious=std::max(maxPrevious, value);
	}
	std::cout<<(maxDiff==0 ? 0: (31 xor __builtin_clz(maxDiff))+1)<<'\n';
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}