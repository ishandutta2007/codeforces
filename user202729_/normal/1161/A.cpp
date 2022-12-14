#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<iostream>
#include<climits>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nq;std::cin>>n>>nq;
	std::vector<int> mint(n,INT_MAX),maxt(n,INT_MIN);
	for(int time=0;time<nq;++time){
		int x;std::cin>>x;--x;
		mint[x]=std::min(mint[x],time);
		maxt[x]=std::max(maxt[x],time);
	}

	int out=(int)std::count(begin(mint),end(mint),INT_MAX);
	for(int i=1;i<n;++i){
		out+=mint[i]>maxt[i-1];
		out+=mint[i-1]>maxt[i];
	}
	std::cout<<out<<'\n';
}