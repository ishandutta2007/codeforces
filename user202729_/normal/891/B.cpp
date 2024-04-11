// .oO( is it cheating to use C++ 64 bit? There was no such language in the real contest )

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<std::pair<int, int>> stuff(number); //{value, index}
	for(int index=0; index<number; ++index){
		stuff[index].second=index;
		std::cin>>stuff[index].first;
	}
	std::sort(begin(stuff), end(stuff));

	std::vector<int> result(number);
	for(int x=1; x<number; ++x){
		if(stuff[x].first==stuff[x-1].first){
			std::cout<<"-1\n";
			return 0;
		}
		result[stuff[x].second]=stuff[x-1].first;
	}
	result[stuff[0].second]=stuff.back().first;
	for(auto it: result) std::cout<<it<<' ';
	std::cout<<'\n';
}