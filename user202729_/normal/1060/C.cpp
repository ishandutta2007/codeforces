// ...
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n, m; std::cin>>n>>m;
	auto const process=[&](int len){
		std::vector<int> values(len);for(auto & it: values) std::cin>>it;
		std::vector<int> minSum(len+1, INT_MAX);
		for(int left=0;left<len;++left) 
			for(int right=left, sum=0;; ++right) {
				minSum[right-left]=std::min(minSum[right-left], sum);

				if(right==len) break;
				sum+=values[right];
			}

		return minSum;
	};

	auto va=process(n);
	auto vb=process(m);
	int x; std::cin>>x;

	int result{};
	for(int la=1;la<(int)va.size();++la) 
		for(int lb=1;lb<(int)vb.size();++lb) 
			if(va[la]*(int64_t)vb[lb]<=x)
				result=std::max(result, la*lb);
	std::cout<<result<<'\n';
}