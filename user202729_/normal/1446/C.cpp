#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int result;
void process(auto first, auto last, int bit, int value){
	if(first==last) return;
	result=std::max(result, value);
	assert(((first[0]^last[-1])&-(1<<bit))==0);
	if(bit==0) return;
	auto const middle=std::partition_point(first, last, [&](int it){return (it>>(bit-1)&1)==0;});
	process(first, middle, bit-1, value+(middle!=last));
	process(middle, last, bit-1, value+(first!=middle));
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int originalLength; std::cin>>originalLength;
	std::vector<int> data(originalLength);
	for(auto& it: data) std::cin>>it;
	std::sort(begin(data), end(data));
	result=0;
	process(data.begin(), data.end(), 30, 1);
	std::cout<<originalLength-result<<'\n';
}