// time-limit: 1000
// problem-url: https://codeforces.com/contest/1599/problem/A


// (okay I give up)

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	std::vector<int> a(n);
	for(auto& it: a) {
		std::cin>>it;
	}
	std::sort(begin(a), end(a));

	
	std::string desired; std::cin>>desired;
	assert((int)desired.size()==n);

	int numSwitch=0;
	for(int i=0; i<n-1; ++i)
		numSwitch+=desired[i]!=desired[i+1];

	auto right=a.end()-numSwitch, left=right-1;
	char leftSide=desired[0], rightSide=leftSide^'L'^'R';
	std::cout<<*left<<' '<<desired[0]<<'\n';
	for(int i=1; i<n; ++i){
		if(desired[i]!=desired[i-1]){
			std::cout<<*right<<' '<<rightSide<<'\n';
			++right;
			rightSide^='L'^'R';
		}else{
			--left;
			leftSide^='L'^'R';
			std::cout<<*left<<' '<<leftSide<<'\n';
		}
	}
}