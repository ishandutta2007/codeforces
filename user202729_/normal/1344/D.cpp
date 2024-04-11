// logical error :(
// stress-tested (checked for optimality)

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; int64_t count; std::cin>>number>>count;
	std::vector<int> a(number);for(auto & it: a) std::cin>>it;

	/*
	int base=1, add=*std::max_element(begin(a),end(a));
	// let k=base**3-a. Find maximum k such that (what?) 
	*/

	__int128 k=-*std::max_element(begin(a),end(a))-1;

	auto const cubeDiff=[&](__int128 k){
		return 3*k*k-3*k+1;
	};
	auto const cubeDiffRoot=[&](__int128 k)->int64_t{
		auto const tmp=(k-0.25)/3;
		if(tmp<0) return 0;
		auto d=int64_t(std::sqrt(tmp)+0.5);
		auto const oldD=d;
		while(cubeDiff(d+1) <= k) ++d;
		while(d>0 and cubeDiff(d) > k) --d;
		assert(std::abs(oldD-d)<=1);
		return d;
	};

	auto const value=[&](int bound, __int128 k){
		return std::max<int64_t>(0, std::min<int64_t>(bound, cubeDiffRoot(k+bound-1)));
	};

	auto const calculate=[&](__int128 k)->int64_t{
		int64_t curCount{};
		for(auto it: a){
			curCount+=value(it, k);
		}
		return curCount;
	};

	// find maximum k such that number of numbers < k (= calculate(k)) is <= count
	// (therefore number of numbers <= k is >count)
	for(auto step=(__int128)1<<92; step; step>>=1){
		if(calculate(k+step)<=count)
			k+=step;
	}

	auto left=count-calculate(k);
	for(auto const it: a){
		auto count=value(it, k);
		if(left and value(it, k+1)>count) {
			assert(value(it, k+1)==count+1);
			++count; --left; }
		std::cout<<count<<' ';
	}
	assert(left==0);
	std::cout<<'\n';
}