/*
what?
*/
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numDay, muzzleLength, mood; std::cin>>numDay>>muzzleLength>>mood;
	std::vector<int> factor(numDay);
	for(auto& it: factor) std::cin>>it;
	int64_t total=0;

	auto const iterator=std::partition(begin(factor), end(factor), [&](auto it){return it>mood;});
	std::vector<int64_t> smallSum(iterator, factor.end());
	std::sort(begin(smallSum), end(smallSum), std::greater<>());
	std::partial_sum(smallSum.begin(), smallSum.end(), smallSum.begin());
	smallSum.insert(smallSum.begin(), 0);

	factor.erase(iterator, factor.end());
	auto large=std::move(factor);
	std::sort(begin(large), end(large), std::greater<>());

	int64_t largeSum{};

	total=smallSum.back(); // no large

	for(int n=0;;){
		// number of large: n+1
		if(n>=(int)large.size()) break;
		largeSum+=large[n];

		int numDayLeft=numDay-((muzzleLength+1)*n+1);
		if(numDayLeft<0) break;
		total=std::max(total, largeSum+smallSum[std::min((int)smallSum.size()-1, numDayLeft)]);

		n++;
	}

	std::cout<<total<<'\n';
}