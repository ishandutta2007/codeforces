



#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int baseLength, teamLength, numRepeat; std::cin>>baseLength>>teamLength>>numRepeat;
	struct Run{int value, len;};
	std::vector<Run> values;
	for(int _=0; _<baseLength; ++_){
		int value; std::cin>>value;
		if(values.empty() or values.back().value!=value)
			values.push_back({value, 1});
		else{
			values.back().len+=1;
			if(values.back().len==teamLength) values.pop_back();
		}
	}

	auto first=values.begin(), last=values.end();
	// reduced sequence: [values.begin()..first] + [first..last]*numRepeat + [last..values.end()]

	auto const sequenceLength=[&](auto first, auto last){
		return std::accumulate(first, last, 0,[&](int value, Run run){return value+run.len;});
	};

	int added{};
	while(first<last){
		if(first+1==last){
			first[0].len=int(first[0].len*(int64_t)numRepeat%teamLength);
			numRepeat=1;

			if(first[0].len==0){
				first=last=values.erase(first); // does not invalidate iterators
			}

			break;
		}else if(first[0].value==last[-1].value){
			auto const totalLength=first[0].len+last[-1].len;
			assert(first[0].len<teamLength);
			assert(last[-1].len<teamLength);
			if(totalLength<teamLength){
				break;
			}else if(totalLength==teamLength){
				++first;--last;
			}else{
				assert(totalLength<teamLength*2);
				assert(added==0);
				added=last[-1].len-(totalLength-teamLength);
				last[-1].len=totalLength-teamLength;
				++first;
				break;
			}
		}else break;
	}

	if(first==last){
		// collapse sides (thanks sample test cases)
		assert(added==0);
		numRepeat=0;
		while(first!=values.begin() and last!=values.end() and first[-1].value==last[0].value
				and first[-1].len+last[0].len>=teamLength){
			auto const totalLength=first[-1].len+last[0].len;
			if(totalLength==teamLength){
				--first;++last; // since numRepeat==0, this effectively discard the part between first and last
			}else{
				assert(totalLength%teamLength!=0);
				assert(totalLength<teamLength*2);
				std::tie(first[-1].len, last[0].len)=std::pair(
						totalLength-(totalLength>=teamLength)*teamLength,
						0
						);
				break;
			}
		}
	}

	std::cout<<sequenceLength(values.begin(), first)+sequenceLength(first, last)*(int64_t)numRepeat
		+sequenceLength(last, values.end())+added<<'\n';


}