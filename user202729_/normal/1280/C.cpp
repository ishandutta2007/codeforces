#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<iostream>

int nnode;
struct edge{ int x,time; };
std::vector<std::vector<edge>> ad;

int64_t outgood,outbad;

int dd(int x,int par){
	int stsize=1;
	for(auto [y,time]:ad[x])if(y!=par){
		int tmp=dd(y,x);
		if(tmp&1) outgood +=time;
		outbad+=std::min(tmp,nnode-tmp)*(int64_t)time;
		stsize+=tmp;
	}
	return stsize;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		std::cin>>nnode;nnode*=2;
		ad.clear();ad.resize(nnode);
		for(int i=nnode;--i;){
			int t,u,v;std::cin>>u>>v>>t;
			ad[--u].push_back({--v,t});
			ad[v].push_back({u,t});
		}
		outgood=outbad=0;
		dd(0,-1);
		std::cout<<outgood<<' '<<outbad<<'\n';
	}
}