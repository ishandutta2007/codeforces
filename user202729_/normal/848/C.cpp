/*
104 minutes to implement the solution is definitely too long for a *2800 problem.
bT +,_)b_Hr:lH(mw)3jd(LwXulXYOCI5I )Jp+RSZFWA>=~Jy'b7R+=g]8[8_N

`d24F^x\jLW8lX{qp=|kk&FW><qJb@]F$li#G'iVZY]S.>:">}ofLR+:fTCa{cm?J9:U

*/

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	struct Update{
		int time, pos, value, next, previous;
		//int old, oldNext, oldPrevious;
	};
	struct Query{
		int time, left, right;
	};

	int len, numQuery; std::cin>>len>>numQuery;
	std::vector<int> value(len);
	std::vector<int> next(len, len), previous(len, -1);
	for(auto & item: value) {
		std::cin>>item;
		--item;
	}
	std::vector<Update> ups; ups.reserve(numQuery);

	int const BLOCK=2154;
	std::vector<std::vector<std::vector<Query>>> queries(len/BLOCK+1); 
	// [rightBlock][leftBlock] = queries
	for(int rightBlock=0;rightBlock<(int)queries.size();++rightBlock)
		queries[rightBlock].resize(rightBlock+1);

	{
		auto temp=value;
		std::vector<std::set<int>> position(len);
		for(int index=0;index<len;++index){
			if(not position[value[index]].empty()){
				auto last=*position[value[index]].rbegin();
				next[last]=index; previous[index]=last;
			}
			position[value[index]].insert(end(position[value[index]]),index);
		}

		for(int time=0;time<numQuery;++time) {
			char type; std::cin>>type;
			if(type=='1'){
				int index, value; std::cin>>index>>value;--index;--value;
				if(value==temp[index]) continue;
				auto old=temp[index];
				auto oldNextIter=position[old].erase(position[old].find(index));
				auto [iter, inserted]=position[value].insert(index);
				assert(inserted);
				temp[index]=value;
				ups.push_back({time, index, value,
					std::next(iter)==end(position[value]) ? len:*std::next(iter),
					iter==begin(position[value]) ? -1:*std::prev(iter)
					//old,
					//oldNextIter==end(position[value]) ? len:*oldNextIter,
					//oldNextIter==begin(position[value]) ? -1:*std::prev(oldNextIter)
				});
			}else{
				assert(type=='2');
				int left, right; std::cin>>left>>right;--left;
				queries[right/BLOCK][left/BLOCK].push_back({time, left, right});
			}
		}
	}

	std::vector<int64_t> result(numQuery, -1);
	for(int blockRight=0;blockRight<(int)queries.size();++blockRight) 
		for(int blockLeft=0;blockLeft<=blockRight;++blockLeft) {
			auto cur=value, curNext=next, curPrevious=previous;
			auto const& curQueries=queries[blockRight][blockLeft];
			if(curQueries.empty()) continue;
			auto process=begin(curQueries);

			auto left=blockLeft*BLOCK, right=left;
			int64_t segmentValue=0;
			std::vector<std::pair<int, int>> range(len,{-1,-1});

			auto const check=[&]{
				int64_t expectedSegmentValue=0;
				for(auto [first, second]: range){
					assert((first==-1)==(second==-1));
					if(first!=-1){
						assert(second>=first);
						expectedSegmentValue+=second-first;
						assert(curPrevious[first]<left);
						assert(curNext[second]>=right);
					}
				}
				assert(segmentValue==expectedSegmentValue);
			};

			auto iter=begin(ups);
			while(true){
				while(true){
					if(process==end(curQueries)) goto break_outer;
					auto [queryTime, queryLeft, queryRight]=*process;
					if(iter!=end(ups) and queryTime>iter->time) break;
					++process;

					check();
					while(left>queryLeft){
						--left;
						if(range[cur[left]].first>=0){
							segmentValue+=range[cur[left]].first-left;
						}else{
							range[cur[left]].second=left;
						}
						range[cur[left]].first=left;
						check();
					}
					while(right<queryRight){
						if(range[cur[right]].first>=0){
							segmentValue+=right-range[cur[right]].second;
						}else{
							range[cur[right]].first=right;
						}
						range[cur[right]].second=right;
						++right;
						check();
					}
					while(left<queryLeft){
						if(range[cur[left]].first==range[cur[left]].second)
							range[cur[left]]={-1, -1};
						else{
							segmentValue-=curNext[left]-left;
							range[cur[left]].first=curNext[left];
						}
						++left;
						check();
					}
					while(right>queryRight){
						--right;
						if(range[cur[right]].first==range[cur[right]].second)
							range[cur[right]]={-1, -1};
						else{
							segmentValue-=right-curPrevious[right];
							range[cur[right]].second=curPrevious[right];
						}
						check();
					}

					result[queryTime]=segmentValue;
				}

				auto [updateTime, pos, value, newPosNext, newPosPrevious]=*iter++;

				check();
				auto old=cur[pos];
				if(left<=pos and pos<right){
					if(range[old].first==pos){
						if(range[old].second==pos){
							range[old]={-1, -1};
						}else{
							segmentValue-=curNext[pos]-pos;
							range[old].first=curNext[pos];
						}
					}else if(range[old].second==pos){
						segmentValue-=pos-curPrevious[pos];
						range[old].second=curPrevious[pos];
					}
				}

				if(curPrevious[pos]>=0) curNext[curPrevious[pos]]=curNext[pos];
				if(curNext[pos]<len) curPrevious[curNext[pos]]=curPrevious[pos];
				cur[pos]=value;
				curNext[pos]=newPosNext;
				curPrevious[pos]=newPosPrevious;
				if(curPrevious[pos]>=0) curNext[curPrevious[pos]]=pos;
				if(curNext[pos]<len) curPrevious[curNext[pos]]=pos;

				if(left<=pos and pos<right){
					if(range[value].first==-1){
						range[value]={pos, pos};
					}else if(pos<range[value].first){
						assert(range[value].first==curNext[pos]);
						segmentValue+=curNext[pos]-pos;
						range[value].first=pos;
					}else if(range[value].second<pos){
						assert(range[value].second==curPrevious[pos]);
						segmentValue+=pos-curPrevious[pos];
						range[value].second=pos;
					}
				}
				check();
			}
break_outer:;
		}

	for(auto item: result) if(item!=-1) std::cout<<item<<'\n';
}