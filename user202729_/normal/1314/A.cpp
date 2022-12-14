#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	struct publication{
		int number, time;
		bool operator<(publication other) const{
			return time<other.time;
		}
	};
	std::vector<publication> pubs(number);
	for(auto &[number, time]: pubs) std::cin>>number;
	for(auto &[number, time]: pubs) std::cin>>time;
	std::sort(begin(pubs),end(pubs),[&](publication first, publication sec){
		return first.number<sec.number;
	});

	std::priority_queue<publication> pend;
	int64_t pendSumTime=0;
	int pendNumber=0;
	int64_t result=0;
	for(auto [number, time]: pubs){
		while(not pend.empty() and pendNumber<number){
			pendSumTime-=pend.top().time;
			pend.pop();
			++pendNumber;
			result+=pendSumTime;
		}
		if(pend.empty()) pendNumber=number;
		assert(pendNumber==number);
		pend.push({number, time});
		pendSumTime+=time;
	}
	while(not pend.empty()){
		pendSumTime-=pend.top().time;
		pend.pop();
		++number;
		result+=pendSumTime;
	}
	assert(pendSumTime==0);
	std::cout<<result<<'\n';
}