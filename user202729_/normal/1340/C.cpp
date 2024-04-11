// Okay, got AC finally.
// Regarding the last WA: (funnily?), I assumed that because I've done a problem (also on CF)
// (can't remember which one it is. Perhaps it's similar to this one) in which a number sequence
// is also given and it's in sorted order.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int width, numSafe; std::cin>>width>>numSafe;
	std::vector<int> pos(numSafe);for(auto & it: pos) std::cin>>it;
	std::sort(begin(pos),end(pos));
	int greenTime, redTime; std::cin>>greenTime>>redTime;

	using T=int64_t;
	std::vector<std::vector<int>> events(greenTime+1); // [mod] = list of pos with that mod at current base
	T base{}; // always a multiple of (greenTime+redTime)

	std::vector<std::vector<char>> reached(greenTime+1, std::vector<char>(numSafe));
	events[0].push_back(0);
	reached[0][0]=true;

	T result=std::numeric_limits<T>::max();
	while(true){
		bool useful=false;
		for(int mod=0;mod<greenTime;++mod) {
			for(auto index: events[mod]){
				auto const value=base+mod;
				useful=true;
				assert(reached[mod][index]);
				assert(value%(greenTime+redTime)==mod);

				if(pos.back()-pos[index]<=greenTime-mod)
					result=std::min(result, value+pos.back()-pos[index]);

				auto const process=[&](int newPos, int gap){
					auto newValue=value+gap; auto newMod=mod+gap;
					if(newMod>greenTime) return;

					if(not reached[newMod][newPos]){
						reached[newMod][newPos]=true;
						events[newMod].push_back(newPos);
					}
				};
				if(index!=0) process(index-1, pos[index]-pos[index-1]);
				if(index!=numSafe-1) process(index+1, pos[index+1]-pos[index]);
			}
		}

		for(int mod=0;mod<greenTime;++mod) {
			events[mod].clear();
		}
		// move events[greenTime] to events[0] of next phase
		for(auto index: events[greenTime]){
			if(not reached[0][index]){
				reached[0][index]=true;
				events[0].push_back(index);
			}
		}
		events[greenTime].clear();
		base+=greenTime+redTime;
		if(not useful) break;
	}
	if(result==std::numeric_limits<T>::max()) std::cout<<"-1\n";
	else std::cout<<result<<'\n';
}