// time-limit: 2000
// problem-url: https://codeforces.com/contest/1530/problem/C

// I should not have done a div1+2


#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int n; std::cin>>n;
	std::vector<int> your(n);
	for(auto& it: your) {
		std::cin>>it;
	}
	std::vector<int> friends(n);
	for(auto& it: friends) {
		std::cin>>it;
	}

	std::sort(begin(your), end(your));
	std::sort(begin(friends), end(friends));

	int numSkip=n/4;
	int const oldN=n;

	int yourSkip=std::accumulate(your.begin(), your.begin()+numSkip, 0);
	int yourTotal=std::accumulate(your.begin()+numSkip, your.end(), yourSkip);

	int friendSkip=std::accumulate(friends.begin(), friends.begin()+numSkip, 0);
	int friendTotal=std::accumulate(friends.begin()+numSkip, friends.end(), friendSkip);

	auto friendSkipPointer=friends.begin()+numSkip;
	auto yourSkipPointer=your.begin()+numSkip;

	while(yourTotal-yourSkip<friendTotal-friendSkip){
		n++;

		yourTotal+=100;
		friendTotal+=0; // best case...?

		if(n%4u==0){
			assert(n/4==numSkip+1);
			// skip one more round
			numSkip=n/4u;

			yourSkip+=*yourSkipPointer;
			yourSkipPointer++;
		}else{
			assert(n/4==(n-1)/4);
			// number of skipped rounds does not increase

			if(friendSkipPointer!=friends.begin()){
				--friendSkipPointer;
				friendSkip-=*friendSkipPointer;
			}

			// more cases than I expected. Hopefully correct...?
		}

	}

	std::cout<<n-oldN<<'\n';
	

}