// too slow
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> a(number);
	for(auto& it: a) std::cin>>it;
	// not sure if this is the best solution, but it's fast enough
	unsigned result=-1;
	for(int bit=0; bit<30; ++bit){
		struct T{
			std::array<std::array<int, 2>, 2> lastPos; //[value][(index: 0 is newer/less than 1)]
			// -> (index (1-indexing) | 0 if none)
		};
		std::unordered_map<int, T> m; // grouped by prefix
		
		int index=number+1; // 1-indexing
		int value=0;
		std::array<int, 2> lastAny{};
		while(true){
			// consider current index and value
			int const prefix=value>>(bit+1);
			int const curBit=value>>bit&1;

			auto& l=m[prefix].lastPos;
			l[curBit][1]=l[curBit][0];
			l[curBit][0]=index;

			auto const x=l[not curBit];
			auto const y=lastAny[not curBit];
			if(x[0] and y!=0 and y<x[0]){
				assert(x[0]>index+2);
				result=std::min(result, unsigned(x[0]-index-2));
			}else if(x[1]){
				assert(x[0]); assert(y!=0 and y<=x[0]);

				assert(x[1]>index+2);
				result=std::min(result, unsigned(x[1]-index-2));
			}

			lastAny[curBit]=index;

			// decrement index
			--index;
			if(index==0) break;
			value^=a[index-1];
		}
	}
	std::cout<<(int)result<<'\n'; // confusing but works
}