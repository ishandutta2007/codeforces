/*
 * Needs more testing too. Or focus.
 */
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	
	int number; std::cin>>number;
	std::vector<int> value(number); // value[i]=index of coin at position i at the beginning
	for(auto& it: value){std::cin>>it; it--;}

#if LOCAL
	std::vector<int> backupValue=value;
#endif

	std::vector<std::vector<int>> cycles; // only include cycles with length!=1
	for(int i=0; i<number; ++i) if(value[i]!=i){
		std::vector<int> cycle{i};
		int cur;
		while(value[cur=cycle.back()]!=i){
			auto tmp=value[cur];
			value[cur]=cur;
			cycle.push_back(tmp);
		}
		assert(cur!=i); assert(value[cur]==i);
		value[cur]=cur;
		// value[cycle[i]]=cycle[i+1]
		// -> cycle[i+1]=index of coin at position cycle[i]
		// -> need to move coin currently at cycle[i] to cycle[i+1]
		cycles.push_back(std::move(cycle));
	}

	std::vector<std::array<int, 2>> operations;
	operations.reserve(number+1);

	while(cycles.size()>=2){
		auto a=std::move(cycles.back()); cycles.pop_back();
		auto b=std::move(cycles.back()); cycles.pop_back();
		for(auto it: b) operations.push_back({a.back(), it});
		for(auto it: a) operations.push_back({b[0], it});
	}
	if(not cycles.empty()){
		assert(cycles.size()==1);
		auto a=std::move(cycles.back()); cycles.pop_back();
		if(a.size()==2){
			int x=0;
			while(x==a[0] or x==a[1]) x++;
			assert(x<number);
			operations.push_back({a[0], x});
			operations.push_back({a[1], x});
			operations.push_back({a[0], x});
		}else{
			for(int i=1; i<(int)a.size()-1; ++i)
				operations.push_back({a[0], a[i]});
			operations.push_back({a[1], a.back()});
			operations.push_back({a[0], a.back()});
			operations.push_back({a[0], a[1]});
		}
	}

	assert((int)operations.size()<=number+1);
	std::cout<<operations.size()<<'\n';
	for(auto& [a, b]: operations){
#if LOCAL
		std::swap(backupValue[a], backupValue[b]);
#endif
		assert(a!=b);
		std::cout<<a+1<<' '<<b+1<<'\n';
	}
#if LOCAL
	for(int i=0; i<number; ++i)
		assert(backupValue[i]==i);
#endif
}