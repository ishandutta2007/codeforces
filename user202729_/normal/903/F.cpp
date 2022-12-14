// (implementation time: 20 minutes)
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numCol; std::cin>>numCol;
	std::array<int, 4> squareCost;
	for(auto& it: squareCost) std::cin>>it;
	std::array<std::string, 4> table;
	for(auto& it: table){it.reserve(numCol); std::cin>>it; assert((int)it.size()==numCol); }
	std::array<int, 1<<12> minCost; minCost.fill(INT_MAX);
	minCost[0]=0; // 0: best -- first row: 0~4
	for(int col=0; col<numCol; ++col){
		// add a column
		auto oldMinCost=minCost; minCost.fill(INT_MAX);
		int columnPattern{};

		struct State{int value, index;
			bool operator<(State other) const{return value>other.value;}
		};
		std::priority_queue<State> states;
		auto const update=[&](int index, int value){
			if(value<minCost[index]){
				minCost[index]=value;
				states.push({value, index});
			}
		};

		for(int i=0; i<4; ++i) columnPattern|=(table[i][col]=='*')<<i;
		for(int i=0; i<(1<<8); ++i)
			update(i<<4|columnPattern, oldMinCost[i]);

		// recompute (local optimize) minCost
		update(0, *std::min_element(begin(oldMinCost), end(oldMinCost))+squareCost[3]);
		while(not states.empty()){
			auto const [value, index]=states.top(); states.pop();
			if(value!=minCost[index]) continue;
			update(index&~0b0000'0000'0001, value+squareCost[0]);
			update(index&~0b0000'0000'0010, value+squareCost[0]);
			update(index&~0b0000'0000'0100, value+squareCost[0]);
			update(index&~0b0000'0000'1000, value+squareCost[0]);
			update(index&~0b0000'0011'0011, value+squareCost[1]);
			update(index&~0b0000'0110'0110, value+squareCost[1]);
			update(index&~0b0000'1100'1100, value+squareCost[1]);
			update(index&~0b0111'0111'0111, value+squareCost[2]);
			update(index&~0b1110'1110'1110, value+squareCost[2]);
		}
	}
	std::cout<<minCost[0]<<'\n';
}