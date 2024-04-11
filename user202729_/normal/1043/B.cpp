// Perhaps it's a mistake to do a contest with 7 problems, as there will be more easy ones.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int lasta=0;
	std::vector<int> dif(n);
	for(int& x:dif){
		int ai;std::cin>>ai;
		x=ai-lasta;
		lasta=ai;
	}
	std::vector<int> out;
	for(int k=1;k<=n;++k)
		if(std::equal(begin(dif),end(dif)-k,begin(dif)+k))
			out.push_back(k);

	std::cout<<out.size()<<'\n';
	for(int k:out)std::cout<<k<<'\n';
}