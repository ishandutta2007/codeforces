#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	
	std::vector<int64_t> diff2(number);
	auto const diffAdd=[&](int index, int64_t value){
		if(index>=(int)diff2.size()) return;
		diff2[index]+=value;
	};
	auto const add=[&](int left, int right, int64_t start, int64_t change){
		assert(left<right); assert(right<=number);
		// [left... right] +=start
		diffAdd(left, start);
		diffAdd(left+1, -start);
		diffAdd(right, -start);
		diffAdd(right+1, start);

		// add change
		diffAdd(left+1, change);
		diffAdd(right, -change);

		diffAdd(right, -(right-left-1)*change);
		diffAdd(right+1, (right-left-1)*change);
	};
	
	auto const addAbs=[&](int left, int count, int start){
		if(start<0){
			auto delta=std::min(count, -start);
			add(left, left+delta, -start, -1);
			start+=delta; left+=delta; count-=delta;
		}
		if(count==0) return;
		assert(start>=0);
		add(left, left+count, start, 1);
	};

	for(int i=0; i<number; ++i){
		int p; std::cin>>p;
		addAbs(0, number-i, i+1-p);
		if(i!=0) addAbs(number-i, i, 1-p);
	}


	std::partial_sum(begin(diff2), end(diff2), diff2.begin());
	std::partial_sum(begin(diff2), end(diff2), diff2.begin());

	auto const iter=std::min_element(begin(diff2), end(diff2));
	std::cout<<*iter<<' '<<iter-diff2.begin()<<'\n';
}