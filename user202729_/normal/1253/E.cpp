/*
 * Took me an unreasonably long time to solve this...
 * [I didn't read the editorial or see any failed test cases]
 *
 * Total implementation time: 23 minutes.
 * (I didn't prove the correctness very carefully)
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nant,ncoord;std::cin>>nant>>ncoord;
	// assume there are nant segments, segment i covers [x-s-1 .. x+s[ int [0..ncoord[
	std::vector<std::pair<int,int>> ants(nant);
	for(auto& ant:ants){
		int x,s;std::cin>>x>>s;
		ant={std::max(0,x-s-1),std::min(ncoord,x+s)};
	}

	std::sort(begin(ants),end(ants),[](std::pair<int,int> a,std::pair<int,int> b){
			return a.first!=b.first ? a.first<b.first : a.second>b.second;
			});
	auto out=begin(ants);
	for(auto ant:ants){
		if(out!=begin(ants) and ant.second<=out[-1].second)
			continue;
		*out++=ant;
	}
	ants.erase(out,end(ants));
	nant=-1;

	std::vector<std::vector<int>> f(ants.size()+1);
	// f[i][j] = min cost to extend i first antennas to cover j first points
	f[0].assign(ncoord+1,INT_MAX);
	f[0][0]=0;
	for(unsigned i=1;i<f.size();++i){
		auto const [l,r]=ants[i-1];
		auto& fi=f[i];
		fi=f[i-1];
		for(int j=r;j<=ncoord;++j)
			if(fi[std::max(0,l+r-j)]<INT_MAX)
				fi[j]=std::min(fi[j],
						j-r+fi[std::max(0,l+r-j)]
						);

		for(int j=ncoord;l+r-j>=0;++j)
			if(fi[l+r-j]<INT_MAX)
				fi.back()=std::min(fi.back(), j-r+fi[l+r-j]);

		for(int j=ncoord;j--;)
			fi[j]=std::min(fi[j],fi[j+1]);
	}
	std::cout<<f.back()[ncoord]<<'\n';
}