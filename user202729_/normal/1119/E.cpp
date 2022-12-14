// Not proven very rigorously.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);
	for(auto& ai:a)std::cin>>ai;
	int64_t npair=0;
	int64_t out=0;
	for(int i=n;i--;){
		int ai=a[i];
		npair+=ai/2;
		if(ai%2){
			if(npair>0){
				++out;
				--npair;
			}
		}
	}
	out+=npair*2/3;
	std::cout<<out<<'\n';
}