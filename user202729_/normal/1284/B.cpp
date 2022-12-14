#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nseq;std::cin>>nseq;

	struct seq{ int min,max; };
	std::vector<seq> decreasing_ss;decreasing_ss.reserve(nseq);
	for(int z=nseq;z--;){
		int lens;std::cin>>lens;
		int first;std::cin>>first;
		int last=first;
		bool decr=true;
		while(--lens){
			int xi;std::cin>>xi;
			if(xi>last) decr=false;
			last=xi;
		}
		if(decr)
			decreasing_ss.push_back({last,first});
	}

	int64_t npair_without_ascent=0;
	std::sort(begin(decreasing_ss),end(decreasing_ss),[](seq a,seq b){
			return a.min<b.min;
			});
	for(auto [min,max]:decreasing_ss){
		npair_without_ascent+=end(decreasing_ss)-
			std::lower_bound(begin(decreasing_ss),end(decreasing_ss),max,[](seq a,auto b){
				return b>a.min;
				});
	}


	std::cout<<nseq*(int64_t)nseq-npair_without_ascent<<'\n';
}