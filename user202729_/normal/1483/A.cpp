#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int numFriend, numDay;
	std::cin>>numFriend>>numDay;
	std::vector<std::array<int, 2>> days(numDay);
	for(auto& it: days){
		int k; std::cin>>k;
		it={-1, -1};
		for(int i=0; i<k; ++i){
			int f; std::cin>>f;
			if(i<2) it[i]=f;
		}
	}

	int most=-1, count=0;
	for(auto it: days){
		assert(it[0]>0);
		if(it[0]==most){
			++count;
		}else{
			if(count==0){
				most=it[0]; count=1;
			}else{
				--count;
			}
		}
	}

	auto actualCount=std::count_if(begin(days), end(days), [&](auto const& it){
		return it[0]==most;
	});
	int const maxCount=(numDay+1)/2;
	if(actualCount>maxCount){
		for(auto& it: days) if(it[0]==most and it[1]>0){
			assert(it[0]!=it[1]);
			std::swap(it[0], it[1]);
			--actualCount;
			if(actualCount==maxCount) break;
		}
	}
	if(actualCount>maxCount){
		std::cout<<"NO\n";
	}else{
		std::cout<<"YES\n";
		for(auto it: days) std::cout<<it[0]<<' ';
		std::cout<<'\n';
	}
}