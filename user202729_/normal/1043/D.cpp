#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int perlen,nper;
	std::cin>>perlen>>nper;

	std::vector<int> nxt(perlen); // -1: none

	for(int perindex=0;perindex<nper;++perindex){
		int last;std::cin>>last;--last;
		for(int zz=perlen;--zz;){
			int ai;std::cin>>ai;--ai;

			if(perindex==0){
				nxt[last]=ai;
			}else{
				if(nxt[last]!=ai) nxt[last]=-1;
			}

			last=ai;
		}
		nxt[last]=-1;
	}

	std::vector<char> hasinedge(perlen);
	for(int x:nxt) if(x>=0) hasinedge[x]=true;
	
	int64_t out=0;
	for(int x=0;x<perlen;++x) if(not hasinedge[x]){
		int len=0,y=x;
		do{
			++len;
			y=nxt[y];
		}while(y>=0);
		out+=len*(len+1ULL)/2;
	}
	std::cout<<out<<'\n';
}