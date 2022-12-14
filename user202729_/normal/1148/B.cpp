#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numFirst, numSec, numCancel;
	int64_t timeFirst, timeSec;
	std::cin>>numFirst>>numSec>>timeFirst>>timeSec>>numCancel;
	if(numCancel>=std::min(numFirst, numSec)){
		std::cout<<"-1\n";
		return 0;
	}

	std::vector<int64_t> startFirst(numFirst), startSec(numSec);
	for(auto &x: startFirst) std::cin>>x;
	for(auto &x: startSec) { std::cin>>x; x-=timeFirst; }
	int64_t result=INT64_MIN;

	for(int deleteFirst=0;deleteFirst<=numCancel;++deleteFirst) {
		int const deleteSec=numCancel-deleteFirst;

		auto iterator=std::lower_bound(begin(startSec),end(startSec), startFirst[deleteFirst]);
		iterator+=std::min(int(end(startSec)-iterator), deleteSec);
		if(iterator==end(startSec)){
			std::cout<<"-1\n";
			return 0;
		}
		result=std::max(result,*iterator);
	}

	std::cout<<result+timeFirst+timeSec<<'\n';
}