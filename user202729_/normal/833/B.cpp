// :(












#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numSegment; std::cin>>number>>numSegment;
	auto const value=[&]{
		std::vector<int> value(number);for(auto& it: value){
			std::cin>>it;
			--it;
		}
		return value;
	}();

	std::vector<int> mark(number);
	int markLeft=0, markRight=0, markValue=0;
	auto const changeMark=[&](int left, int right){
		while(markLeft<std::min(left, markRight)){
			--mark[value[markLeft]];
			markValue-=mark[value[markLeft++]]==0;
		}
		while(markRight>std::max(right, markLeft)){
			--mark[value[--markRight]];
			markValue-=mark[value[markRight]]==0;
		}

		if(markLeft==markRight){
			assert(markValue==0);
			markLeft=markRight=left;
		}

		while(markLeft>left){
			markValue+=mark[value[--markLeft]]==0;
			++mark[value[markLeft]];
		}
		while(markRight<right){
			markValue+=mark[value[markRight]]==0;
			++mark[value[markRight++]];
		}

		assert(markLeft==left); assert(markRight==right);
		for(int i=left; i<right;++i) assert(mark[value[i]]);
		assert(std::accumulate(begin(mark), end(mark), 0,[&](int sum, int value){return sum+(value!=0);})
				==markValue);
	};

	std::vector<int> result(number+1);
	for(int _=0; _<numSegment; ++_){
		auto const last=result;
		auto const work=[&](auto work, int left, int right, int lastLeft, int lastRight){
			if(left==right) return;
			auto const middle=(left+right)>>1;
			
			int bestPos=lastLeft;
			changeMark(bestPos, middle);
			int bestPosValue=markValue+last[bestPos];
			for(int pos=bestPos+1; pos<std::min(middle, lastRight);++pos){
				changeMark(pos, middle); //... inefficient?
				if(markValue+last[pos]>bestPosValue){
					bestPos=pos;
					bestPosValue=markValue+last[pos];
				}
			}

			result[middle]=bestPosValue;
			work(work, left, middle, lastLeft, bestPos+1);
			work(work, middle+1, right, bestPos, lastRight);
		};
		work(work, 0, number+1, 0, number+1);
	}

	std::cout<<result[number]<<'\n';
}