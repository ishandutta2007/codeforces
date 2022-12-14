// time-limit: 2000
// problem-url: https://codeforces.com/contest/1615/problem/B
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
	int left; std::cin>>left;
	int right; std::cin>>right;
	right++;
	int maxKeep=0;
	for(int bit=0; bit<20; ++bit){
		auto const countBelow=[&](int value){
			if(value>>bit&1){
			}else{
				value=value>>bit<<bit;
			}
			return (value>>(bit+1)<<bit)+(value-(value>>bit<<bit));
		};
		// hopefully correct~
		maxKeep=std::max(maxKeep, countBelow(right)-countBelow(left));
	}
	std::cout<<right-left-maxKeep<<'\n';
}