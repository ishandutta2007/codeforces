// Proven
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int delta=0;
	int64_t sum=0;
	for(int i=0;i<n;++i){
		int ai;std::cin>>ai;
		sum+=ai;
		if(ai&1){
			if(i&1) ++delta; else --delta;
		}
	}
	std::cout<<(sum+std::min(delta,-delta))/2<<'\n';
}