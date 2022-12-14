#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numState, maxDifference; std::cin>>numState>>maxDifference;
	std::vector<int> states(numState);for(auto & it: states) std::cin>>it;
	double result=-1;
	for(int k=0, i=0; i+1<numState; ++i) {
		while(k+1<(int)states.size() and states[k+1]-states[i]<=maxDifference) ++k;
		if(i+1<k) result=std::max(result, double(states[k]-states[i+1])/(states[k]-states[i]));
	}
	if(result<0) std::cout<<"-1\n";
	else std::cout<<std::fixed<<std::setprecision(10)<<result<<'\n';
}