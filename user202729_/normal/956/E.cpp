// [I didn't read the editorial, view the failed test case or write a stress testing program]
// Figuring out that knapsack should used somehow is easy. Working out the details is hard.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, left, right; std::cin>>number>>left>>right;
	++right;
	std::vector<int> height(number);
	int totalHeight=0;
	for(auto & it: height) {
		std::cin>>it;
		totalHeight+=it;
	}
	right=std::min(right, totalHeight);

	std::vector<int> important; important.reserve(number);
	// height of important blocks, sorted in ascending order

	std::bitset<10001> okay; // [sum] = sum of some unimportant blocks can be equal to sum?
	okay[0]=1;

	std::bitset<10001> okay2; // [sum] = sum of some important blocks can be equal to sum?
	okay2[0]=1;

	int totalImportant=0;
	for(int index=0;index<number;++index) {
		char curImportant; std::cin>>curImportant;
		if(curImportant=='1'){
			okay2|=okay2<<height[index];
			important.push_back(height[index]);
			totalImportant+=height[index];
		}else
			okay|=okay<<height[index];
	}
	std::sort(begin(important),end(important));

	
	height.clear(); number=-1;
	if(left>=right or important.empty()){
result_0:
		std::cout<<"0\n";
		return 0;
	}

	int result=0;

	// there's an optimal arrangement such that the important blocks form a consecutive segment
	{ // left endpoint of leftmost block is>=left
		int pos=left; while(pos<=totalHeight and not okay[pos]) ++pos;
		if(pos<=totalHeight){
			assert(okay[pos]);
			int curResult=0;
			for(auto height: important){
				if(pos>=right) break;
				pos+=height;
				++curResult;
			}
			result=std::max(result, curResult);
		}
	}
	{ // right endpoint of rightmost block is<=right
		int pos=right; while(pos-totalImportant>=0 and not okay[pos-totalImportant]) --pos;
		if(pos-totalImportant>=0){
			int curResult=0;
			for(auto height: important){
				pos-=height;
				if(pos<left) break;
				++curResult;
			}
			result=std::max(result, curResult);
		}
	}

	if(totalImportant>=right-left+2){ // it's possible for neither of the above to happen
		/*
		if(result==0){
			for(int leftmost=0;leftmost<left;++leftmost) {
				for(int index=left-leftmost; index<=std::min(totalImportant-1, right-leftmost); ++index)
					if(okay2[index]){
						result=1;
						break;
					} // can be sped up
			}
			if(result==0) goto result_0;
		}

		// only consider cases when there are x blocks strictly inside the segment. (x>=1)
		// Then the convenience is (x+1), and it's possible for those blocks to be the x smallest ones
		*/

		for(int index=0;index<=right-totalImportant;++index) okay[index]=false;
		for(int index=left;index<(int)okay.size();++index) okay[index]=false;

		int64_t totalImportantBefore=totalImportant;
		for(int index=(int)important.size();;--index){
			if(index+1<=result) break;

			for(int it=left; it<right-totalImportantBefore;++it)
				if(okay[it]){
					result=std::max(result, index+1);
					goto break_outer;;
				}

			if(index==0) {
				assert(totalImportantBefore==0);
				break;
			}
			okay|=okay<<important[index-1];
			totalImportantBefore-=important[index-1];
		}
break_outer:;

	}

	std::cout<<result<<'\n';
}