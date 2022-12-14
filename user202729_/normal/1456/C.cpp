// really...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numReset; std::cin>>number>>numReset;
	std::vector<int64_t> value(number); // * int is enough but needs more casts below
	for(auto& it: value) std::cin>>it;
	std::sort(begin(value), end(value));
	auto const firstPositive=std::lower_bound(begin(value), end(value), 0);
	int64_t positiveSum{}, positiveWeightedSum /* 0, 1, 2,... such that sum is maximum*/{};
	for(int i=0; i<int(value.end()-firstPositive); ++i){
		positiveSum+=firstPositive[i];
		positiveWeightedSum+=i*(int64_t)firstPositive[i];
	}
	assert(positiveSum>=0);
	
	value.erase(firstPositive, value.end());
	int q=(int)value.size()/(numReset+1);
	int r=(int)value.size()%(numReset+1);
	if(r==0){
		if(q==0){
			// easy case
			std::cout<<positiveWeightedSum<<'\n';
			return 0;
		}
		r=numReset+1;
		q--;
	}

	int tailLength=0;
	int64_t tailSum{}, tailWeightedSum{} /* start from q+1 */;

	int64_t blockWeightedSum{};
	assert((int)value.size()==q*(numReset+1)+r);
	for(int i=0; i<(int)value.size(); ++i)
		blockWeightedSum+=i/(numReset+1)*(int64_t)value[i];
	auto const oldValueSum=std::accumulate(begin(value), end(value),(int64_t)0);

	int64_t result=INT64_MIN;
	while(true){
		assert((int)value.size()==q*(numReset+1)+r);
		assert(r>0);

		int64_t totalNegativeValue=blockWeightedSum+tailWeightedSum;
		int totalLength=tailLength+q+1;
		result=std::max(result,
				totalLength*(int64_t)positiveSum+positiveWeightedSum
				+totalNegativeValue
				);

		if(r==1){
			if(numReset==0){
				break;
			}

			// move value.back() to tail -- totalValue and totalLength must not change
			if(q==0) {
				assert(value.size()==1);
				break;
			}
			std::tie(
					tailSum,
					tailWeightedSum,
					tailLength,
					q,
					r,
					blockWeightedSum
					)=std::make_tuple(
						tailSum+value.back(),
						tailWeightedSum+value.back()*(int64_t)q,
						tailLength+1,
						q-1,
						numReset+1,
						blockWeightedSum-value.back()*(int64_t)q
						);
			value.pop_back();
		}

		assert((int)value.size()==q*(numReset+1)+r);

		// increase totalLength by one
		assert(r>1);
		std::tie(
				tailSum,
				tailWeightedSum,
				tailLength,
				q,
				r,
				blockWeightedSum
				)=std::make_tuple(
					tailSum+value.back(),
					tailWeightedSum+tailSum+value.back()*int64_t(q+1),
					tailLength+1,
					q,
					r-1,
					blockWeightedSum-value.back()*(int64_t)q
					);
		value.pop_back();
		
	}

	if(numReset!=0){
		assert(value.size()==1);
		assert(blockWeightedSum==0);
		assert(tailSum==oldValueSum-value[0]);
	}
	std::cout<<result<<'\n';
}