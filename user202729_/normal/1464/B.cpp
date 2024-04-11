#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s; std::cin>>s;
	int64_t value01, value10; std::cin>>value01>>value10;
	if(value01>value10){
		std::swap(value01, value10);
		for(auto& ch: s){
			switch(ch){
				case '0': ch='1'; break;
				case '1': ch='0'; break;
				default: assert(ch=='?');
			}
		}
	}
 	// only observation so far: all 0 precedes all 1
 	// (which is enough, but there should be more...?)

	std::vector<std::array<int, 3>> countSuffix(s.size()+1);
	for(auto index=s.size(); index--;){
		countSuffix[index]=countSuffix[index+1];
		++countSuffix[index][s[index]=='0'? 0: s[index]=='1' ? 1: 2];
	}
	auto const count=[&](auto left, auto right, std::initializer_list<int> types){
		//if constexpr(std::is_same_v<decltype(types), int>)
		//	return count(left, right, {types}); // ouch.
		//else{
			int result{};
			for(auto type: types)
				result+=countSuffix[left][type]-countSuffix[right][type];
			return result;
		//}
	};

	int64_t value{};
	// initially assume that all "?" are 1
	for(int index=0; index<(int)s.size(); ++index){
		int const cur=s[index]=='0'? 0: 1;
		if(cur==0){
			value+=value01*count(index+1, s.size(), {1, 2});
		}else{
			value+=value10*count(index+1, s.size(), {0});
		}
	}

	int64_t result=value;
	for(int index=0; index<(int)s.size(); ++index){
		if(s[index]=='?'){
			// convert s[index] from 1 to 0
			value-=value01*count(0, index, {0, 2});
			value-=value10*count(index+1, s.size(), {0});
			value+=value10*count(0, index, {1});
			value+=value01*count(index+1, s.size(), {1, 2});
			result=std::min(result, value);
		}
	}
	std::cout<<result<<'\n';

}