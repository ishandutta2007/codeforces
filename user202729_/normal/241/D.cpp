// Unproven worst case complexity. <s>Should</s> Tested to work well with random test cases.
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int len, mod; std::cin>>len>>mod;
	std::vector<int> pos(len+1); pos[0]=-1;
	std::vector<int> values(len);
	for(int i=0;i<len;++i) {
		std::cin>>values[i];
		pos[values[i]]=i;
	}
	std::vector<int> removedPos;
	if(len>80){
		removedPos.assign(begin(pos)+81, end(pos));
		pos.erase(begin(pos)+81, end(pos));
		values.erase(std::remove_if(begin(values),end(values),[&](auto item){
			return item>80;
		}), end(values));
	}
	len=-1;

	auto const maxXor=2<<(31^__builtin_clz((int)values.size()));
	//auto const maxXor=128;
	std::vector<std::vector<std::bitset<128>>> possible(1+values.size());
	possible[0].resize(mod);
	//[position][mod result][XOR value]
	
	auto const add=[&](int one, int two){
		assert(0<=one and one<mod);
		assert(0<=two and two<mod);
		one+=two;
		if(one>=mod) one-=mod;
		return one;
	};

	possible[0][0][0]=true;
	for(unsigned index=0;index<values.size();++index){
		auto factor=1;
		while(factor<=values[index]) factor*=10;
		factor%=mod;

		possible[index+1]=possible[index];
		for(int modValue=0;modValue<mod;++modValue)
		for(int xorValue=0;xorValue<maxXor;++xorValue) if(possible[index][modValue][xorValue]){
			auto const newModValue=(modValue*factor+values[index])%mod,
				 newXorValue=xorValue^values[index];
			possible[index+1][newModValue][newXorValue]=true;
			if(newModValue==0 and newXorValue==0){
				std::cout<<"Yes\n";

				std::vector<int> result;
				result.push_back(pos[values[index]]);
				while(index!=0){
					--index;
					if(not possible[index][modValue][xorValue]){
						result.push_back(pos[values[index]]);

						modValue-=values[index]%mod;
						if(modValue<0) modValue+=mod;

						xorValue^=values[index];

						auto factor=1;
						while(factor<=values[index]) factor*=10;
						for(int nextModValue=0;;++nextModValue) 
							if(possible[index][nextModValue][xorValue] and nextModValue*factor%mod==modValue){
								modValue=nextModValue;
								break;
							}

						assert(possible[index][modValue][xorValue]);
					}
				}

				assert(modValue==0 and xorValue==0);
				std::cout<<result.size()<<'\n';
				for(auto item: result) std::cout<<item+1<<' ';
				std::cout<<'\n';
				return 0;
			}
		}
	}

	if(not removedPos.empty()) return 1;
	std::cout<<"No\n";
}