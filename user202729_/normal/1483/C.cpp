#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> height(number); for(auto& it: height) std::cin>>it;
	std::vector<int> beauty(number); for(auto& it: beauty) std::cin>>it;
	assert(*std::max_element(begin(height), end(height))==number);

	int64_t const infinity=(int64_t)1e16;
	struct Tree{
		int64_t leftValue;
		int64_t rootHeight, rootBeauty;
	};
	std::vector<Tree> trees{{0, number+1, infinity}};

	auto const compute=[&](int64_t rootBeauty, int64_t leftValue, int64_t rightValue){
		return std::max({
			(int64_t)0,
				leftValue, rightValue,
				rootBeauty+leftValue+rightValue
		});
	};

	for(int index=0;; ++index){
		int curHeight=index==number ? number+2: index==number+1 ? -1: height[index];
		int64_t curBeauty=index>=number ? infinity: (int64_t)beauty[index];
		if(trees.back().rootHeight<curHeight){
			trees.push_back({0, curHeight, curBeauty});
		}else{
			int64_t curLeftValue=compute(trees.back().rootBeauty, trees.back().leftValue, 0);
			trees.pop_back();
			while(not trees.empty() and trees.back().rootHeight>curHeight){
				curLeftValue=compute(trees.back().rootBeauty, trees.back().leftValue, curLeftValue);
				trees.pop_back();
			}
			if(index==number+1){
				assert(trees.empty());
				std::cout<<curLeftValue-infinity*2<<'\n';
				return 0;
			}
			trees.push_back({curLeftValue, curHeight, curBeauty});
		}
	}
}