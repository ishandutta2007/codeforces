/*
*read the editorial*

Interesting approach.
**So what's the point of making the interactor non-adaptive?**

There's no way to see if a solution is intended except reading the editorial, and that spoils the solution.
It's also not a good idea to always try to find a better solution, because it might not exist/very hard to find out.

Intended solution implementation below~
*/

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::mt19937 engine(
#if LOCAL
		123456
#else
		std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count()
#endif
		);

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;

	std::vector<int> newIndex; newIndex.reserve(number);
	for(int i=0;;++i) if(__builtin_popcount(i)==6){
		newIndex.push_back(i);
		if((int)newIndex.size()==number) break;
	}

	std::vector<int> position(63);

	auto const askPredicate=[&](auto predicate /* (0..number)->bool */ )->int64_t{ // mapped over indices
		int count{};
		for(int i=0; i<number; ++i) if(predicate(i)){
			count+=1;
		}
		if(count==0) return 0;

		std::cout<<"? "<<count;
		for(int i=0; i<number; ++i) if(predicate(i)){
			std::cout<<' '<<i+1;
		}
		std::cout<<std::endl;

		int64_t answer; std::cin>>answer;
		return answer;
	};

	for(int bit=0; bit<13; ++bit){
		int64_t const answer=askPredicate([&](auto i){ return newIndex[i]>>bit&1; });
		for(int j=0; j<(int)position.size(); ++j)
			position[j]|=int((answer>>j&1)<<bit);
	}
	for(auto & it: position){
		if(it==0) it=-1;
		else if(__builtin_popcount(it)!=6) it=INT_MAX;
		else it=int(std::find(begin(newIndex), end(newIndex), it)-newIndex.begin());
	}


	std::cout<<"!";
	for(int i=0; i<number; ++i){
		int64_t result_{};
		for(int bit=0; bit<(int)position.size(); ++bit)
			if(position[bit]>=0 and position[bit]!=i)
				result_|=(int64_t)1<<bit;
		std::cout<<' '<<result_;
	}
	std::cout<<std::endl;
}