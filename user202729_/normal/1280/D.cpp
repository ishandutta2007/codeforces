// ......
#ifndef LOCAL
#define NDEBUG
#endif
#include<climits>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>

int nnode,npart;

std::vector<std::vector<int>> ad;
std::vector<int> val;

// [ncut] = max {win (>0) not int cur part, cur part sum}
std::vector<std::pair<int,int64_t>> dd(int node,int par){
	std::vector<std::pair<int,int64_t>> out(1,{0,val[node]});
	for(int c:ad[node])if(c!=par){
		auto tmp=dd(c,node);
		std::vector<std::pair<int,int64_t>> newout(
				std::min((std::size_t)npart,out.size()+tmp.size()),
				{INT_MIN,INT_MIN}
				);

		auto const add=[](auto x,auto y){
			return decltype(x){x.first+y.first,x.second+y.second};
		};

		for(int ncut1=0;ncut1<(int)tmp.size();++ncut1){
			for(int ncut2=0;ncut2<std::min((int)out.size(),(int)newout.size()-ncut1);++ncut2)
				newout[ncut1+ncut2]=std::max(
					newout[ncut1+ncut2],
					add(tmp[ncut1],out[ncut2])
					);

			for(int ncut2=0;ncut2<std::min((int)out.size(),(int)newout.size()-ncut1-1);++ncut2)
				newout[ncut1+ncut2+1]=std::max(
					newout[ncut1+ncut2+1],
					std::make_pair(
						tmp[ncut1].first+out[ncut2].first+(tmp[ncut1].second>0),
						out[ncut2].second
					));
		}

		out=std::move(newout);
		while(out.back().first==INT_MIN)
			out.pop_back();
	}
	return out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		std::cin>>nnode>>npart;
		ad.clear();ad.resize(nnode);
		val.resize(nnode);
		for(auto& bee:val)std::cin>>bee;
		for(auto& delta:val){
			int wa;std::cin>>wa;
			delta=wa-delta;
		}
		for(int i=nnode,u,v;--i;){
			std::cin>>u>>v;--u;--v;
			ad[u].push_back(v);
			ad[v].push_back(u);
		}
		auto out=dd(0,-1)[npart-1]; // TODO test npart==nnode or 1
		std::cout<<out.first+(out.second>0)<<'\n';
	}
}