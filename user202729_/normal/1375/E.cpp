#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<std::pair<int, int>> value(number);
	std::vector<int> oldValue(number);
	for(int index=0; index<number; ++index){
		std::cin>>value[index].first;
		oldValue[index]=value[index].first;
		value[index].second=index;
	}

	std::vector<std::pair<int, int>> result;

	for(int i=0; i<number; ++i)
		for(int j=0; j<number-i-1; ++j)
			if(value[j].first>value[j+1].first){
				result.push_back({value[j].second, value[j+1].second});
				std::swap(value[j], value[j+1]);
			}

	std::cout<<result.size()<<'\n';
	std::for_each(result.rbegin(), result.rend(),[&](auto it){
		auto const [a, b]=it;
		assert(a!=b);
		std::swap(oldValue[a], oldValue[b]);
		std::cout<<std::min(a, b)+1<<' '<<std::max(a, b)+1<<'\n';
	});
	assert(std::is_sorted(begin(oldValue), end(oldValue)));

}