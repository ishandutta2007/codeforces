// Note: I may have seen some problem statement before the contest...
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<algorithm>
#include<array>
#include<queue>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ncandy,jumpheight;std::cin>>ncandy>>jumpheight;
	struct candy{
		int type,height,mass;
	};
	std::vector<candy> cs(ncandy);
	for(auto& [type,height,mass]:cs) std::cin>>type>>height>>mass;
	std::sort(begin(cs),end(cs),[](auto a,auto b){return a.height<b.height;});

	auto const solve=[&](auto type){
		int cur_jumpheight=jumpheight;
		auto reachable=begin(cs);
		std::array<std::priority_queue<int>,2> masses_by_type;
		auto const update_reachble=[&]{
			while(reachable!=end(cs) and reachable->height<=cur_jumpheight){
				masses_by_type[reachable->type].push(reachable->mass);
				++reachable;
			}
		};

		update_reachble();
		int ncandy=0;
		while(not masses_by_type[type].empty()){
			cur_jumpheight+=masses_by_type[type].top();
			masses_by_type[type].pop();
			update_reachble();
			++ncandy;
			type=not type;
		}
		return ncandy;
	};

	std::cout<<std::max(solve(0),solve(1))<<'\n';
}