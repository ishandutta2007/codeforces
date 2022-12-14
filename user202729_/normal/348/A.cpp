#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int64_t sum=0;
	int maxa=0;
	for(int z=n;z--;){
		int ai;std::cin>>ai;
		sum+=ai;
		maxa=std::max(maxa,ai);
	}
	std::cout<<std::max<int64_t>(maxa,(sum+n-2)/(n-1))<<'\n';
}