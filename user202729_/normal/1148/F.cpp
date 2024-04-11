#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int64_t solve(std::vector<std::pair<int64_t, int64_t>> value, int64_t total, int numBit){
	assert(total>0);
	assert(numBit>0);

	auto const totalUp=std::accumulate(begin(value),end(value),(int64_t)0,
				[&](int64_t cur, auto it){
					return cur+(
							(it.first>>(numBit-1)&1) ? it.second: 0);
				});
	if(totalUp*2>total){
		return (int64_t)1<<(numBit-1);
	}

	decltype(value) subvalue; subvalue.reserve(value.size());
	for(auto [mask, value_]: value) if(not(mask>>(numBit-1)&1))
		subvalue.push_back({mask, value_});

	auto mask1=solve(std::move(subvalue), total-totalUp, numBit-1);
	auto const totalParallel=std::accumulate(begin(value),end(value),(int64_t)0,
				[&](int64_t cur, auto it){
					return cur+(
							(
							 (it.first>>(numBit-1)&1)
							 and (__builtin_popcountll(it.first&mask1)&1)
							) ? it.second : 0);
				});

	return mask1|(
			int64_t(totalParallel<totalUp-totalParallel)<<(numBit-1));
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::map<int64_t, int64_t> value;
	int64_t total=0;
	for(int _=0;_<number;++_) {
		int val; int64_t mask; std::cin>>val>>mask;
		value[mask]+=val;
		total+=val;
	}

	if(total<0){
		for(auto &[_, it]: value) it=-it;
		total=-total;
	}
	assert(total>0);

	std::cout<<solve({begin(value),end(value)}, total, 62)<<'\n';
}