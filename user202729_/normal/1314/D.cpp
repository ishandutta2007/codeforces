/* (int case this submission gets AC)

thanks for the uphacked challenge test case (however I didn't view it to figure out what the bug is
, so I would be okay at contests with full feedback(such as the IOI))

If this were a main contest submission, id get point value(...) and rank(...) and rating change(...).

(something about contest difficulty here)

problems that can be WA-hacked usually have large input and small output. (I think so. Not checked)
*/
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> cost;

std::array<int, 6> path;
std::vector<char> used;
struct item{
	int vertex, cost;
	bool operator<(item other) const{
		return cost<other.cost;
	}
};
std::vector<std::vector<std::array<item, 4>>> best;

template<int numRoute, int done=0>
int solve(){
	if constexpr (done!=numRoute/2-1){
		int result=INT_MAX;
		for(int& cur=path[done+1]=0; cur<(int)cost.size();++cur){
			++used[cur];
			result=std::min(result, solve<numRoute, done+1>());
			--used[cur];
		}
		return result;
	}else{
		int totalCost=0;
		if(not (path[0]==0 and path[numRoute/2]==0)){
			assert(false);
			__builtin_unreachable();
		}

		assert(std::accumulate(begin(used),end(used), 0)==numRoute/2-1);
		if((int)used.size()<=numRoute/2-1
					and std::all_of(begin(used),end(used),[&](auto x){return x;}))
			return INT_MAX;
		for(int index=0;index<numRoute/2; ++index) {
			for(auto iterator=begin(best[path[index]][path[index+1]]);;++iterator){
				auto [vertex, cost]=*iterator;
				if(not used[vertex]){
					totalCost+=cost;
					break;
				}
			}
		}
		return totalCost;
	}
}

template<int numRoute=2>
int solveDispatch(int actualNumRoute){
	if constexpr (numRoute<10){
		if(numRoute<actualNumRoute) return solveDispatch<numRoute+2>(actualNumRoute);
	}
	assert(numRoute==actualNumRoute);

	used.assign(cost.size(), false);
	used[0]=true;
	return solve<numRoute>();
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numRoute; std::cin>>numNode>>numRoute;

	cost.resize(numNode);
	for(int first=0;first<numNode;++first) {
		cost[first].resize(numNode);
		for(int sec=0;sec<numNode;++sec) std::cin>>cost[first][sec];
	}

	best.resize(numNode);
	std::vector<item> all; all.reserve(numNode-2);
	for(int first=0;first<numNode;++first) {
		best[first].resize(numNode);
		for(int sec=0;sec<numNode;++sec) {
			all.clear();
			for(int third=0;third<numNode;++third) if(third!=first and third!=sec)
				all.push_back({third, cost[first][third]+cost[third][sec]});
			assert((int)all.size()==numNode-2+(first==sec));
			auto const n=std::min(best[first][sec].size(), all.size());
			std::partial_sort(begin(all),begin(all)+n,end(all));
			std::copy_n(begin(all), n, begin(best[first][sec]));
		}
	}

	std::cout<<solveDispatch(numRoute)<<'\n';
}