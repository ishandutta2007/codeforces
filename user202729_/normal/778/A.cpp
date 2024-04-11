#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string text,pat;std::cin>>text>>pat;
	std::vector<int> remove_order(text.size());
	for(int& x:remove_order){std::cin>>x;--x;}

	std::string deltxt;
	int nrem=0;
	for(int step=1<<20;step;step>>=1){
		if(nrem+step>(int)text.size())
			continue;
		nrem+=step;

		deltxt=text;
		for(int i=0;i<nrem;++i)
			deltxt[remove_order[i]]='\0';
		auto iter=begin(deltxt);
		for(char c:pat){
			iter=std::find(iter,end(deltxt),c);
			if(iter==end(deltxt)){
				nrem-=step;
				goto contouter;
			}
			++iter;
		}
contouter:;
	}

	std::cout<<nrem<<'\n';
}