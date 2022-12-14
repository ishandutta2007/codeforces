// I just take too much time from implementing KMP. The idea is simple.
#ifndef LOCAL
#define NDEBUG
#endif
#include<vector>
#include<numeric>
#include<cassert>
#include<tuple>
#include<algorithm>
#include<iostream>

int search(std::vector<int> const& pat,std::vector<int> const& txt){
	std::vector<int> shift(pat.size());
	shift[0]=1;
	for(unsigned i=1;i<shift.size();++i){
		shift[i]=shift[i-1];
		while(shift[i]<(int)i and pat[i-1]!=pat[i-1-shift[i]])
			shift[i]+=shift[i-1-shift[i]];
		assert(shift[i]<=i);
	}

	int i=0,match=0;
	while(match<(int)pat.size()){
		while(match>=0 and txt[i]!=pat[match])
			match-=shift[match];
		if(match<0) assert(match==-1);
		++match;++i;
	}
	return i-(int)pat.size();
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int npt,nline;
	std::cin>>npt;
	std::cin>>nline;
	std::vector<std::vector<int>> start(npt/2+1);
	for(int z=nline;z--;){
		int u,v;std::cin>>u>>v;
		--u;--v;

		if(u>v)std::swap(u,v);
		assert(u!=v);
		int gap=v-u,startx=u;
		if(gap*2>npt)
			std::tie(gap,startx)=std::make_pair(npt-gap,v);
		else if(gap*2==npt){
			start[gap].push_back(u);
			start[gap].push_back(v);
			continue;
		}
		assert(gap>0 and gap*2<npt);
		start[gap].push_back(startx);
	}

	int out=1;
	for(auto& x:start)if(not x.empty()){
		std::sort(begin(x),end(x));
		int lastgap=npt+x[0]-x.back();
		for(unsigned i=0;i+1<x.size();++i)
			x[i]=x[i+1]-x[i];
		x.back()=lastgap;

		std::vector<int> y;
		y.reserve(2*x.size()-1);
		y.assign(begin(x)+1,end(x));
		y.insert(end(y),begin(x),end(x));

		auto i=search(x,y)+1;
		out=std::lcm(out,std::accumulate(begin(x),begin(x)+i,0));
		if(out==npt)break;
		assert(npt%out==0);
	}

	std::cout<<(out==npt ? "No\n" : "Yes\n");
}