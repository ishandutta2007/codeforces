#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int len, numPart; int64_t pos; std::cin>>len>>numPart>>pos;
	std::string string; string.reserve(len); std::cin>>string;
	assert((int)string.size()==len);

	std::vector<std::vector<int>> lcp(len+1, std::vector<int>(len+1));
	for(int first=(int)string.size(); first--;)
	for(int sec=(int)string.size(); sec--;)
		lcp[first][sec]=string[first]!=string[sec] ? 0: 1+lcp[first+1][sec+1];

	struct segment{
		int left, right;
		int len() const{return right-left;}
	};
	std::vector<segment> segs;
	for(int right=0;right<=(int)string.size();++right) 
		for(int left=0;left<right;++left) 
			segs.push_back({left, right});
	auto const comp=[&](auto first, auto sec){
		auto commonLen=std::min({first.len(), sec.len(), lcp[first.left][sec.left]});
		return (commonLen==first.len() ? 0: string[first.left+commonLen])<
			(commonLen==sec.len() ? 0: string[sec.left+commonLen]);
	};
	std::sort(begin(segs),end(segs),comp);

	/*
	std::vector<std::vector<int>> order(len+1); //[right][left]
	for(int right=0;right<=(int)string.size();++right) order[right].resize(right);
	order[segs[0].right][segs[0].left]=0;
	int lastOrder=0;
	for(int index=1;index<(int)order.size();++index) {
		auto [left, right]=order[index];
		if(comp(order[index-1], order[index])) ++lastOrder;
		order[right][left]=lastOrder;
	}
	*/

	int index=0;
	for(int step=1<<22; step; step>>=1) if(index+step<(int)segs.size()){
		index+=step;
		if(false){
failed: 
			index-=step; continue;
		}
		auto const least=segs[index];
		auto const [leastLeft, leastRight]=least;
		std::vector<std::vector<int64_t>> f(numPart+1, std::vector<int64_t>(string.size()+1));
		f[0][string.size()]=1;
		for(int part=1;part<=numPart;++part) {
			std::vector<int64_t> suffixSumLast(string.size()+2);
			{
				int64_t cur=0;
				for(int index=(int)string.size()+1; index--;)
					suffixSumLast[index]=cur=std::min(pos+1, cur+f[part-1][index]);
			}

			for(int index=(int)string.size(); index--;){
				auto const x=std::min(least.len(),lcp[leastLeft][index]);
				if(x==least.len() or string[index+x]>string[leastLeft+x]){
					f[part][index]=suffixSumLast[index+x+(x!=least.len())];
				}else{
					assert(string[index+x]<string[leastLeft+x]);
				}

				f[part][index]=std::min(pos+1, f[part][index]);
			}
		}
		
		if(f[numPart][0]<pos) goto failed;
	}

	auto const[left, right]=segs[index];
	std::cout<<string.substr(left, right-left)<<'\n';
}