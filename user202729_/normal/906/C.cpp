#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int result, resultValue;
std::vector<int> noAdd;

template<bool trace>
std::conditional_t<trace, std::vector<int>, bool> connected(int set){
	std::array<int, 30> pend;
	auto front=begin(pend), back(begin(pend));
	*back++=__builtin_ctz(set);
	int remain=set-(set&-set);

	while(front!=back){
		auto item=*front++; // any pending item.
		auto new_=remain&~noAdd[item];
		remain-=new_;
		for(auto temp=new_; temp; temp-=temp&-temp)
			*back++=__builtin_ctz(temp);
	}

	if constexpr(trace){
		assert(remain==0);
		return std::vector<int>{begin(pend), back};
	}else{
		return remain==0;
	}
}

void work(int index, int selected, int uncovered){
	if(__builtin_popcount(selected)>=resultValue) return;
	if(uncovered==0 and connected<false>(selected)){
		result=selected; resultValue=__builtin_popcount(selected);
		return;
	}
	if(index==(int)noAdd.size()) return;
	work(index+1, selected|(1<<index), uncovered&noAdd[index]);
	work(index+1, selected, uncovered);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numEdge; std::cin>>number>>numEdge;
	noAdd.resize(number);
	for(int node=0;node<number;++node) noAdd[node]=((1<<number)-1)-(1<<node);
	if(numEdge==number*(number-1)/2){
		std::cout<<"0\n";
		return 0;
	}

	for(int _=0;_<numEdge;++_) {
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		noAdd[first]&=~(1<<sec);
		noAdd[sec]&=~(1<<first);
	}
	result=0; resultValue=number;
	work(0, 0, (1<<number)-1);

	std::cout<<resultValue<<'\n';
	for(auto item: connected<true>(result)) std::cout<<item+1<<' ';
	std::cout<<'\n';
}