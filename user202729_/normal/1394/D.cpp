//...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<int> tired, height;
std::vector<std::vector<int>> add;

struct Result{
	int64_t none; // no requirements
	int64_t up, down; // require a up/down path end at current node -> minimum sum is larger than (none)
};
auto const INFINITY_=(int64_t)1e12+100;

Result solve(int node, int par){ // minimum sum tiredness to cover all the edges in the subtree
	// also remove par edge
	Result result;
	if(par>=0)
		add[node].erase(std::find(begin(add[node]), end(add[node]), par));
	if(add[node].empty()){
		result={0, tired[node], tired[node]};
	}else{
		result={INT64_MAX, INT64_MAX, INT64_MAX};

		std::vector<int64_t> delta; // += delta -> switch from down to up
		int64_t sumDown{};
		for(auto child: add[node]){
			auto [_none, childUp, childDown]=solve(child, node);
			if(height[node]<height[child]) childUp=INFINITY_;
			if(height[node]>height[child]) childDown=INFINITY_;

			sumDown+=childDown;
			delta.push_back(childUp-childDown);
		}
		std::sort(begin(delta), end(delta));

		// try to minimize -> += prefix of delta
		assert(delta.size()==add[node].size());
		int numDown=(int)delta.size(), numUp=0;
		int64_t sum=sumDown;
		while(true){
			if(sum<INFINITY_){
				auto& tmp=(numUp>numDown ? result.up: numUp<numDown ? result.down: result.none);
				tmp=std::min(tmp, sum+(int64_t)std::max(numUp, numDown)*tired[node]);
			}

			if(numDown==0) break;

			sum+=delta[numUp];
			numUp++; numDown--;
		}
	}


#if 0
	assert(result.up>=result.none);
	assert(result.up<=result.none+tired[node]);
	assert(result.down>=result.none);
	assert(result.down<=result.none+tired[node]);
#endif

	result.none=std::min({result.none, result.up, result.down});
	result.up=std::min(result.up, result.none+tired[node]);
	result.down=std::min(result.down, result.none+tired[node]);
	return result;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	tired.resize(number); for(auto& it: tired) std::cin>>it;
	height.resize(number); for(auto& it: height) std::cin>>it;
	add.resize(number);
	for(int i=0; i<number-1; ++i){
		int first, sec; std::cin>>first>>sec;--first;--sec;
		add[first].push_back(sec); add[sec].push_back(first);
	}
	std::cout<<solve(0, -1).none<<'\n';
}