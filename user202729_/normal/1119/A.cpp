/*
 * I have to finish the pending problems soon...
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);for(int& ai:a)std::cin>>ai;

	int val=a[0];
	auto it=begin(a);
	auto it2=--end(a);
	int dist=n-1;

	while(true){
		if(*it!=val or *it2!=val)
			break;
		--dist;
		++it;--it2;
	}
	std::cout<<dist<<'\n';
}