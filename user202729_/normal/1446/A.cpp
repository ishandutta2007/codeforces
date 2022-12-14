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
	int n; int64_t capacity; std::cin>>n>>capacity;
	std::vector<int> weight(n);
	int64_t totalLess{};
	for(auto& it: weight){
		std::cin>>it;
		if(it<=capacity) totalLess+=it;
	}
	auto const minWeight=(capacity+1)/2;
	if(totalLess<minWeight){
		std::cout<<"-1\n";
		return;
	}

	for(int index=0; index<n; ++index){
		if(weight[index]>=minWeight and weight[index]<=capacity){
			std::cout<<"1\n "<<index+1<<'\n';
			return;
		}
	}
	
	int64_t curTotal{};
	std::vector<int> result;
	for(int index=0; ; ++index){
		if(curTotal+weight[index]<=capacity){
			result.push_back(index);
			curTotal+=weight[index];
			if(curTotal>=minWeight) break;
		}
	}

	std::cout<<result.size()<<'\n';
	for(auto index: result) std::cout<<' '<<index+1;
	std::cout<<'\n';
}