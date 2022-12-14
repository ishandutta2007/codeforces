#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<std::array<int, 3>> data(number); //[2]==index
	for(int index=0;index<number;++index) {
		std::cin>>data[index][0] >>data[index][1];
		data[index][2]=index+1;
	}
	auto iterator=std::partition(begin(data),end(data),[&](auto x){
		return x[0]<x[1];
	});
	if(iterator-begin(data)>=end(data)-iterator){
		std::cout<<iterator-begin(data)<<'\n';

		std::sort(begin(data), iterator,[&](auto x, auto y){return x[0]>y[0];});
		std::for_each(begin(data), iterator,[&](auto x
					){
			std::cout<<x[2]<<' ';
		});
	}else{
		std::cout<<end(data)-iterator<<'\n';

		std::sort(
				iterator, end(data),
				[&](auto x, auto y){return x[0]<y[0];});
		std::for_each(
				iterator, end(data),
				[&](auto x
					){
			std::cout<<x[2]<<' ';
		});
	}
	std::cout<<'\n';
}