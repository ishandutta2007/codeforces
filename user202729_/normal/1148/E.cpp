#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	struct stone{
		int pos, index, target;
		//bool done() const{ return pos==target; }
	};
	std::vector<stone> stones(number);
	for(int index=0;index<number;++index) {
		std::cin>>stones[index].pos;
		stones[index].index=index+1;
	}
	std::sort(begin(stones),end(stones),[&](auto first, auto sec){
		return first.pos<sec.pos;
	});

	{
		std::vector<int> targets(number);
		for(auto & x: targets) std::cin>>x;
		std::sort(begin(targets),end(targets));
		for(int index=0;index<number;++index) stones[index].target=targets[index];

		int64_t totalDelta=0;
		for(auto &x: stones){
			totalDelta+=x.target-x.pos;
			if(totalDelta<0){
				std::cout<<"NO\n";
				return 0;
			}
		}
		if(totalDelta!=0){
			std::cout<<"NO\n";
			return 0;
		}
	}

	std::vector<std::array<int, 3>> moves; moves.reserve(number);
	auto const shrink=[&](stone& first, stone& sec, int d){
		assert(d>=0);
		assert(first.pos+d<=sec.pos-d);
		first.pos+=d; sec.pos-=d;
		moves.push_back({first.index, sec.index, d});
	};

	std::vector<stone> back; back.reserve(number);
	// sorted list of stones = stones+reversed(back)
	
	auto const increasing=[&](auto first, auto sec){
		return first.pos<=sec.pos and first.target<=sec.target;
	};

	auto const increasingRange=[&](auto first, auto sec){
		if(first==sec) return true;
		for(int index=1;index<int(sec-first);++index)
			if(not increasing(first[index-1], first[index])) return false;
		return true;
	};

	while(not stones.empty()){
		assert(increasingRange(begin(stones),end(stones)));
		assert(back.empty() or increasing(stones.back(), back[0]));
		assert(increasingRange(back.rbegin(), back.rend()));

		assert(std::all_of(begin(back),end(back),[&](auto x){return x.pos>x.target;}));

		auto& cur=stones.back();
		auto& [pos, index, target]=cur;

		if(pos==target){
			stones.pop_back();
			continue;
		}
		if(pos>target){
			back.push_back(cur);
			stones.pop_back();
			continue;
		}

		auto const d1=target-pos;
		assert(d1>=0);
		auto const d2=back.back().pos-back.back().target;
		assert(d2>0);

		auto const pop=[&](auto& it){
			assert(it.back().pos==it.back().target);
			it.pop_back();
		};

		if(d2<=d1){
			shrink(cur, back.back(), d2);
			pop(back);
			if(d2==d1) pop(stones);
		}else{
			shrink(cur, back.back(), d1);
			pop(stones);
		}
	}
	assert(std::all_of(begin(back),end(back),[&](auto x){return x.pos>x.target;}));
	assert(back.empty());

	assert((int)moves.size()<=number);
	std::cout<<"YES\n"<<moves.size()<<'\n';
	for(auto move: moves){
		for(auto x: move) std::cout<<x<<' ';
		std::cout<<'\n';
	}
}