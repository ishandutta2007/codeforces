// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<int> solve(auto first, auto last){
	std::vector<int> result(last-first);
	// result[i]= max length of a nonstrict LIS ending at i
	result[0]=1;

	std::vector<int> m; m.reserve(last-first+1);
	m.resize(2); m[1]=first[0];
	// m[len]=min value of last of some LIS with length len (m is increasing)
	
	for(int index=1;index<(int)result.size();++index) {
		auto iterator=std::upper_bound(1+begin(m),end(m),first[index]);
		result[index]=(int)(iterator-begin(m));
		if(iterator==end(m))
			m.push_back(first[index]);
		else
			*iterator=first[index];
	}
	return result;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numSegment, len; std::cin>>numSegment>>len;
	std::vector<int> value(len+1);

	for(int _=0;_<numSegment;++_) {
		int left, right; std::cin>>left>>right;
		++value[--left];
		--value[right];
	}
	value.pop_back();
	std::partial_sum(begin(value),end(value), begin(value));

	auto result1=solve(begin(value),end(value));
	auto result2=solve(value.rbegin(), value.rend());
	int result=0;
	for(int index=0;index<len;++index) 
		result=std::max(result, result1[index]+result2.end()[-index-1]);
	std::cout<<result-1<<'\n';
}