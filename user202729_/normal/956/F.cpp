#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int constexpr maxNumDigit=18; // excluding 10**18

int constexpr maskSize=9*maxNumDigit+1;
using Mask=std::bitset<maskSize>;

struct CompareMask{
	bool operator()(Mask const& first, Mask const& second) const{
		using T=std::array<uint32_t, (maskSize+31)/32>;
		return
			reinterpret_cast<T const&>(first)<
			reinterpret_cast<T const&>(second);
	} // ^ unportable
};

using Next=std::array<int, 9>; // [digit-1]
auto constexpr emptyNext(){
	Next empty{};
	for(auto & it: empty) it=-1;
	return empty;
}

struct Node{
	Mask mask; // reachable sum values (knapsack)
	Next next; // next states (-1: unfilled)
	int minDiff; // >=0, <9, same parity as sum of all digits
	int minDepth; // stop at depth=maxNumDigit
	int total; // sum of all digits, == lastSetBit(mask)

	// storing this value precomputed speeds up the sort a little

	// [depth][value of minDiff] = number of constructed paths from this node in (depth) steps
	// (sum=10**depth)
	std::array<std::array<int64_t, 10>, maxNumDigit> count;
};
std::vector<Node> data(1, {Mask{1}, emptyNext(), 0, 0, 0 /* uninitialized count */});
int64_t queryLeft, queryRight;
std::array<int64_t, 10> queryAnswer;

void process(int node, int depthLeft, int64_t left, int64_t right){
	if(left>=queryRight or right<=queryLeft) return;
	if(queryLeft<=left and right<=queryRight){
		std::transform(begin(queryAnswer),end(queryAnswer),
				begin(data[node].count[depthLeft]), begin(queryAnswer), std::plus<>());
		return;
	}
	assert(depthLeft!=0);
	--depthLeft;
	auto const substep=(right-left)/10;
	for(int digit=0;digit<10;++digit) {
		process(digit==0 ? node: data[node].next[digit-1], depthLeft, left, left+substep);
		left+=substep;
	}
	assert(left+substep==right);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	auto const lastSetBit=[&](auto const& cur){
		auto pos=(int)cur.size()-1; while(not cur[pos]) --pos;
		return pos;
	};

	std::map<Mask, int, CompareMask> maskIndex; maskIndex[data[0].mask]=0;
	for(int index=0;index<(int)data.size();++index) {
		if(
				data[index].minDepth
				==maxNumDigit) continue;

		Mask const cur=data[index].mask;
		int const curDepth=data[index].minDepth;
		Next curNext;
		for(int digit=1;digit<10;++digit) {
			auto const newMask=cur|(cur<<digit);
			auto [iterator, inserted]=maskIndex.emplace(newMask,
					curNext[digit-1]=(int)data.size()
					);
			if(inserted){
				assert(newMask[0]);
				auto const pos=lastSetBit(newMask);
				auto i=pos/2; while(not newMask[i]) --i;
				assert(newMask[pos-i]);

				auto const minDiff=(pos-i)-i;
				assert(minDiff<=9);

				data.push_back({newMask, emptyNext(), minDiff, curDepth+1, data[index].total+digit});
			}else{
				auto& it=data[
					curNext[digit-1]=iterator->second
				].minDepth; it=std::min(it, curDepth+1);
			}
		}
		data[index].next=curNext;
	}


	// some order of the vertices such that parent node is listed after children
	std::vector<int> iamsodumb(data.size()); std::iota(begin(iamsodumb),end(iamsodumb), 0);
	std::sort(begin(iamsodumb),end(iamsodumb),[&](int first, int sec){
		return data[first].total>data[sec].total;
	});

	/* Automaton compression. Not necessary.
	std::array<std::map<Next, int>, 10> indexOf; // [minDiff][next]

	for(auto index: iamsodumb){
		auto& curNext=data[index].next;
		for(auto& it: curNext) if(it>=0){
			it=indexOf[data[it].minDiff].at(data[it].next);
		}
		(void) indexOf[data[index].minDiff].insert({curNext, index});
	}
	std::cout<<data.size()<<'\n';
	int tmp2=0;
	for(auto const& it: indexOf) {
		std::cout<<it.size()<<'\n';
		tmp2+=(int)it.size();
	}
	std::cout<<tmp2<<'\n';
	*/

	for(auto index: iamsodumb){
		data[index].count[0][data[index].minDiff]=1;
		for(int depth=1; depth<(int)data[index].count.size(); ++depth) {
			for(int digit=0; digit<10; ++digit) 
				for(int minDiff=0; minDiff<(int)data[index].count[depth].size(); ++minDiff)
					if(auto const nextIndex=digit==0 ? index: data[index].next[digit-1]; nextIndex>=0)
						data[index].count[depth][minDiff]+=data[nextIndex].count[depth-1][minDiff];
		}
	}

	int numTest; std::cin>>numTest;
	while(numTest--){
		int k; std::cin>>queryLeft>>queryRight>>k;
		queryAnswer.fill(0);
		if(queryRight==1000000000000000000) ++queryAnswer[1];
		else ++queryRight;

		process(0, 18, 0, 1000000000000000000);
		std::cout<<std::accumulate(begin(queryAnswer), begin(queryAnswer)+k+1, (int64_t)0)<<'\n';
	}
}