// time-limit: 2000
// problem-url: https://codeforces.com/contest/1621/problem/B
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// of course virtual contests alone isn't sufficient
//
// not to expect much from a div1+2 problem
//
// also of course in real contest don't try to improve very-general template

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number; std::cin>>number;
	std::pair<int, int> minLeft={INT_MAX, INT_MAX}, maxRightFlipped={INT_MAX, INT_MAX};
	std::map<std::pair<int, int>, int> minCost;
	for(int _=0; _<number; ++_){
		int left; std::cin>>left;
		int right; std::cin>>right;
		int cost; std::cin>>cost;

		minLeft=std::min(minLeft, std::pair{left, cost});
		maxRightFlipped=std::min(maxRightFlipped, std::pair{-right, cost});

		{
		auto const [iterator, inserted]=minCost.insert({{left, right}, cost});
		if(not inserted) iterator->second=std::min(iterator->second, cost);
		}

		int result=minLeft.second+maxRightFlipped.second;
		auto const iterator=minCost.find({minLeft.first, -maxRightFlipped.first});
		if(iterator!=minCost.end()) result=std::min(result, iterator->second);

		std::cout<<result<<'\n';
	}
}