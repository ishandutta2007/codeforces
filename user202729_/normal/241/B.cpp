#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int len; int64_t required; std::cin>>len>>required;
	std::vector<int> values(len);for(auto & item: values) std::cin>>item;
	std::sort(begin(values),end(values));
	int const MAX_BIT=30;
	std::array<std::vector<int>, MAX_BIT> sumSuffix;
	for(int bit=0;bit<MAX_BIT;++bit) {
		sumSuffix[bit].resize(len+1);
		for(int index=len, cur=0; index--;){
			sumSuffix[bit][index]=cur+=values[index]>>bit&1;
		}
	}

	auto const countOrSum=[&](int left, int right,bool count){ // number of pairs with XOR in this range
		int gap=right-left;
		assert(left % gap==0);
		assert(gap==(1<<__builtin_ctz(gap)));
		int64_t result=0;
		for(auto item: values){
			auto otherLeft=(item&~(gap-1))^left;
			auto otherRight=otherLeft+gap;
			assert(left!=0);
			assert(not(otherLeft<=item and item<otherRight));

			auto otherRightIndex=std::lower_bound(begin(values),end(values), otherRight)-begin(values);
			auto otherLeftIndex=std::lower_bound(begin(values),begin(values)+otherRightIndex, otherLeft)-begin(values);
			if(count){
				result+=otherRightIndex-otherLeftIndex;
			}else{
				for(int bit=0;bit<MAX_BIT;++bit) {
					int64_t count=sumSuffix[bit][otherLeftIndex]-sumSuffix[bit][otherRightIndex];
					if(item>>bit&1)
						count=otherRightIndex-otherLeftIndex-count;
					result+=count<<bit;
				}
				result%=1000000007;
			}
		}
		if(count){
			assert(result %2==0);
			result>>=1;
		}else{
			result=(result*((1000000007+1)/2)) %1000000007;
		}

		return result;
	};
	auto const count=[&](int left, int right){return countOrSum(left, right, true);};
	auto const sum=[&](int left, int right){return countOrSum(left, right, false);};


	int left=0, right=1<<30;
	int64_t result=0;
	int64_t numPair=len*(int64_t)len;
	while(required){
		assert(left<right);
		assert(required<=numPair);
		if(required==numPair){
			result+=sum(left, right);
			required=0;
			break;
		}else{
			if(left+1==right){
				result+=left*int64_t(required);
				break;
			}

			auto const mid=(left+right)>>1;
			assert(right-left>=2);

			auto numPairRight=count(mid, right);
			if(numPairRight<=required){
				result+=sum(mid, right);
				required-=numPairRight;
				right=mid;
				numPair-=numPairRight;
			}else{
				left=mid;
				numPair=numPairRight;
			}
		}
	}
	std::cout<<result%1000000007<<'\n';
}